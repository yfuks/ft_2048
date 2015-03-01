/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:52:18 by yfuks             #+#    #+#             */
/*   Updated: 2014/11/06 19:57:56 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*result;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	result = ft_memalloc(ft_strlen(s));
	ft_strcpy(result, s);
	while (result[i])
	{
		result[i] = (*f)(result[i]);
		i++;
	}
	return (result);
}
