/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:33:14 by yfuks             #+#    #+#             */
/*   Updated: 2014/11/07 14:19:28 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*number;

	number = (char *)ft_memalloc(10);
	if (n >= 0 && number)
	{
		*--number = '0' + (n % 10);
		n /= 10;
		while (n != 0)
		{
			*--number = '0' + (n % 10);
			n /= 10;
		}
	}
	else if (number)
	{
		*--number = '0' - (n % 10);
		n /= 10;
		while (n != 0)
		{
			*--number = '0' - (n % 10);
			n /= 10;
		}
		*--number = '-';
	}
	return (ft_strdup(number));
}
