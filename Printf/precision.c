/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:34:20 by clopez-g          #+#    #+#             */
/*   Updated: 2020/03/02 11:34:37 by clopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_t		*precision(t_t *t)
{
	if (t->trat[t->i] == '.')
	{
		t->i++;
		t->pres = 0;
	}
	if (t->trat[t->i] == '*')
	{
		t->pres = (int)(va_arg(t->ap, int));
		if (t->pres < 0)
			t->pres = -1;
		t->i++;
	}
	while (t->trat[t->i] >= '0' && t->trat[t->i] <= '9')
	{
		t->pres *= 10;
		t->pres += (t->trat[t->i] - 48);
		t->i++;
	}
	return (t);
}
