/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchngchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 18:34:31 by yfuks             #+#    #+#             */
/*   Updated: 2015/02/09 19:19:13 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strchngchr(char *str, char *value_to_change, char *value_to_put)
{
	int		len;
	char	*result;
	char	*strcpy;
	char	*tmp[2];
	int		i;

	i = 0;
	result = NULL;
	strcpy = ft_strdup(str);
	if ((tmp[0] = ft_strstr(strcpy, value_to_change)))
	{
		len = ft_strlen(str) - ft_strlen(value_to_change)
			+ ft_strlen(value_to_put) + 1;
		result = ft_strnew(len);
		i = 0;
		while (i < (int)ft_strlen(value_to_change))
			i++;
		tmp[1] = &tmp[0][i];
		tmp[0][0] = 0;
		ft_strcat(result, strcpy);
		ft_strcat(result, value_to_put);
		ft_strcat(result, tmp[1]);
	}
	return (result);
}
