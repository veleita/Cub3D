/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chartype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:00:49 by clopez-g          #+#    #+#             */
/*   Updated: 2020/03/02 11:01:06 by clopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		logic_c(int c, t_t *t)
{
	if (c <= 127)
	{
		t->rv += 1;
	}
	if (c > 127 && c <= 2047)
	{
		t->rv += 2;
	}
	if (c >= 2048 && c <= 65535)
	{
		t->rv += 3;
	}
	if (c >= 65536 && c <= 2097151)
	{
		t->rv += 4;
	}
}

t_t			*chartype(t_t *t)
{
	int		c;

	if (t->flag == '%')
		c = '%';
	else
		c = (char)va_arg(t->ap, int);
	c = (int)c;
	if (t->conver[2] == '0' && t->conver[0] != '-')
		print_aux(t, '0', t->width - 1, 1);
	else if (t->conver[0] != '-')
		print_aux(t, ' ', t->width - 1, 1);
	write(1, &c, 1);
	logic_c(c, t);
	if (t->conver[0] == '-')
		print_aux(t, ' ', t->width - 1, 1);
	return (t);
}
