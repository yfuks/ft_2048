/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:41:07 by yfuks             #+#    #+#             */
/*   Updated: 2014/11/07 15:35:30 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*rcontent;
	size_t	rsize;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		rcontent = ft_memalloc(content_size);
		rsize = content_size;
		ft_memcpy(rcontent, content, content_size);
		new->content = rcontent;
		new->content_size = rsize;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	return (new);
}
