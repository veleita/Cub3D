/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlota <carlota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:40:37 by clopez-g          #+#    #+#             */
/*   Updated: 2020/09/14 19:58:15 by carlota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	strdel(char **str)
{
	free(*str);
	*str = NULL;
}

int			joinline(int fd, char **str, char **line)
{
	int		size;
	char	*temp;

	size = 0;
	while (str[fd][size] != '\n')
		size++;
	*line = ft_substr(str[fd], 0, size);
	temp = ft_strdup_get(&str[fd][size + 1]);
	free(str[fd]);
	str[fd] = temp;
	return (1);
}

int			returnv(char **str, char **line, int re, int fd)
{
	if (re < 0)
		return (-1);
	else if (re == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
	{
		*line = ft_strdup_get("");
		strdel(&str[fd]);
		return (0);
	}
	else if (ft_strchr(str[fd], '\n'))
		return (joinline(fd, str, line));
	else
	{
		*line = ft_strdup_get(str[fd]);
		strdel(&str[fd]);
		return (0);
	}
}

int			get_next_line(int fd, char **line)
{
	static char		*str[4096];
	char			*aux;
	int				re;
	char			buff[BUFF_SIZE];

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	while ((re = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[re] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup_get(buff);
		else
		{
			aux = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = aux;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (returnv(str, line, re, fd));
}
