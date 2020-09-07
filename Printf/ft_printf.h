/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:03:00 by clopez-g          #+#    #+#             */
/*   Updated: 2020/03/02 11:28:48 by clopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <ctype.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

typedef struct	s_tab
{
	const char	*str;
	int			rv;
	int			i;
	int			pres;
	int			width;
	va_list		ap;
	char		*cpy;
	char		*trat;
	char		*flagtype;
	char		flag;
	char		flag_aux;
	char		*convertype;
	char		conver[5];
}				t_t;

t_t				*init(t_t *t);
int				printprintf(t_t *t);
int				ft_printf(const char *str, ...);

t_t				*flagtype(t_t	*t);
int				types(t_t *t);
t_t				*printtype(t_t *t);
t_t				*reinit(t_t *t);

t_t				*precision(t_t *t);
t_t				*width(t_t *t);
t_t				*convertype(t_t *t);

t_t				*chartype(t_t *t);
t_t				*strtype(t_t *t);
t_t				*inttype(t_t *t);
t_t				*uninttype(t_t *t);
t_t				*hextype(t_t *t);
t_t				*ptrtype(t_t *t);

void			print_aux(t_t *t, char c, int len, int update_len);

char			*ft_strnew(size_t size);
char			*ft_itoa_base(uintmax_t num, uintmax_t base, char c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strndup(const char *s1, size_t n);

#endif
