/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strappend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 16:23:58 by yfuks             #+#    #+#             */
/*   Updated: 2014/11/18 18:14:44 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *s1, char *s2)
{
	char	*result;
	int		i[2];

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	result = ft_strnew(ft_strlen(s2) + ft_strlen(s1) + 1);
	i[0] = 0;
	while (s1[i[0]])
	{
		result[i[0]] = s1[i[0]];
		i[0]++;
	}
	i[1] = 0;
	while (s2[i[1]])
	{
		result[i[0]] = s2[i[1]];
		i[0]++;
		i[1]++;
	}
	result[i[0]] = '\0';
	return (result);
}
