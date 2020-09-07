/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:36:57 by clopez-g          #+#    #+#             */
/*   Updated: 2020/03/02 11:37:06 by clopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		types(t_t *t)
{
	t->i++;
	convertype(t);
	width(t);
	precision(t);
	flagtype(t);
	printtype(t);
	return (t->rv);
}

t_t		*printtype(t_t *t)
{
	char	ident;

	ident = t->flag;
	if (ident == 'd' || ident == 'i')
		inttype(t);
	else if (ident == 's')
		strtype(t);
	else if (ident == 'c')
		chartype(t);
	else if (ident == 'x' || ident == 'X')
		hextype(t);
	else if (ident == 'u')
		uninttype(t);
	else if (ident == 'p')
		ptrtype(t);
	else if (ident == '%')
	{
		t->flag = '%';
		chartype(t);
	}
	return (t);
}
