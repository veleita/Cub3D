/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:16:46 by clopez-g          #+#    #+#             */
/*   Updated: 2020/03/02 11:33:59 by clopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = start;
	j = start + len;
	new = (char *)malloc(sizeof(char) * len);
	if (!s)
		return (0);
	while (i < j)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
