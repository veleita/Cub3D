/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlota <carlota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:40:59 by clopez-g          #+#    #+#             */
/*   Updated: 2020/09/14 19:58:20 by carlota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup_get(char const *src)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (new == NULL)
		return (NULL);
	while (i > 0)
	{
		new[j] = src[j];
		i--;
		j++;
	}
	new[j] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != c)
	{
		if (str[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return (&str[i]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;
	size_t	slen;

	i = 0;
	if (!s)
		return (0);
	new = malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
	{
		new[i] = '\0';
		return (new);
	}
	while (len > 0 && s[start] != '\0')
	{
		new[i] = s[start];
		i++;
		start++;
		len--;
	}
	new[i] = '\0';
	return (new);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	dst = malloc(sizeof(*dst) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dst == NULL)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		dst[i] = s2[y];
		i++;
		y++;
	}
	dst[i] = '\0';
	return (dst);
}
