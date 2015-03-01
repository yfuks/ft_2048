/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:13:32 by yfuks             #+#    #+#             */
/*   Updated: 2014/11/10 22:03:23 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*dest;
	char		*sourc;

	i = 0;
	dest = dst;
	sourc = (char *)src;
	while (i < n && (i == 0 || sourc[i - 1] != c))
	{
		dest[i] = sourc[i];
		i++;
	}
	if (i > 0 && sourc[i - 1] == c)
		return (dest + i);
	else
		return (NULL);
}
