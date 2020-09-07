/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:19:36 by clopez-g          #+#    #+#             */
/*   Updated: 2019/11/15 18:14:20 by clopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nelem, size_t size)
{
	void	*result;
	size_t	i;

	i = 0;
	if (nelem == 0 || size == 0)
		return (0);
	result = malloc(size * nelem);
	while (i <= nelem)
	{
		((char*)result)[i] = 0;
		i++;
	}
	return (result);
}
