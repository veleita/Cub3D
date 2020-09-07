/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:12:37 by clopez-g          #+#    #+#             */
/*   Updated: 2019/11/15 16:48:04 by clopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	j = 0;
	new = (char *)malloc(sizeof(char));
	if (!new)
		return (0);
	ft_strcpy(new, s1);
	while (j != '\0')
	{
		i = 0;
		while (new[i] != '\0')
		{
			if (new[i] == set[j])
				new[i] = 0;
			i++;
		}
		j++;
	}
	return (new);
}
