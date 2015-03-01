/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:41:57 by yfuks             #+#    #+#             */
/*   Updated: 2014/11/07 14:27:42 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	i;
	char			*result;

	i = 0;
	if (s2 == NULL || ft_strlen(s2) == 0)
		return ((char *)s1);
	while (i < ft_strlen(s1))
	{
		if (ft_strncmp((char *)&s1[i], s2, ft_strlen(s2)) == 0)
			return ((result = (char *)&s1[i]));
		i++;
	}
	return (NULL);
}
