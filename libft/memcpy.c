/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:50:42 by yfuks             #+#    #+#             */
/*   Updated: 2014/11/10 21:44:09 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*dest;
	const char		*sourc;

	if (src == NULL || dst == NULL)
		return (NULL);
	dest = dst;
	sourc = src;
	i = 0;
	while (i < n)
	{
		dest[i] = sourc[i];
		i++;
	}
	return (dst);
}
