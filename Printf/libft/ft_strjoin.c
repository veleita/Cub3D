/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:30:48 by clopez-g          #+#    #+#             */
/*   Updated: 2019/11/11 17:12:08 by clopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;
	char			*new;

	i = 0;
	j = 0;
	count = 0;
	new = (char *)malloc(sizeof(char));
	if (!new)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	while (count <= i + j)
	{
		if (count <= i)
			new[count] = s1[i];
		else
			new[count] = s2[j];
		count++;
	}
	new[count] = '\0';
	return (new);
}
