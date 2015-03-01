/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:33:14 by yfuks             #+#    #+#             */
/*   Updated: 2014/11/10 18:39:03 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list*elem))
{
	t_list	*cursor;

	cursor = lst;
	if (lst != NULL || f != NULL)
	{
		while (cursor)
		{
			(*f)(cursor);
			cursor = cursor->next;
		}
	}
}
