/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:02:02 by clopez-g          #+#    #+#             */
/*   Updated: 2020/03/02 11:02:42 by clopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		printprintf(t_t *t)
{
	if (ft_strcmp(t->cpy, "%") == 0)
		return (0);
	while (t->cpy[t->i] != '\0')
	{
		if (t->cpy[t->i] == '%')
		{
			reinit(t);
			types(t);
			if (t->flag == 'q' && !va_arg(t->ap, int))
				return (0);
		}
		else
		{
			write(1, &t->cpy[t->i], 1);
			t->rv++;
		}
		t->i++;
	}
	return (t->rv);
}

int		ft_printf(const char *str, ...)
{
	t_t *t;

	if (!(t = (t_t*)malloc(sizeof(t_t))))
		return (-1);
	t->str = str;
	init(t);
	if (str)
	{
		va_start(t->ap, str);
		t->rv = printprintf(t);
		va_end(t->ap);
	}
	free(t);
	return (t->rv);
}
