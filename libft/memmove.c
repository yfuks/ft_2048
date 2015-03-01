/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:37:54 by yfuks             #+#    #+#             */
/*   Updated: 2014/11/10 21:45:12 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cpy;

	if (src == NULL || dst == NULL)
		return (NULL);
	if (!(cpy = (char*)malloc(sizeof(char*) * len)))
		return (NULL);
	cpy = ft_strncpy(cpy, src, len);
	dst = (void*)ft_strncpy(dst, cpy, len);
	free(cpy);
	return (dst);
}
