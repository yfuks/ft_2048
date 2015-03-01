/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 02:37:18 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/01 21:46:57 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

void		add_rand_nb(t_square board[4][4])
{
	int		x;
	int		y;

	x = rand() % 4;
	y = rand() % 4;
	while (board[y][x].value != 0)
	{
		x = rand() % 4;
		y = rand() % 4;
	}
	if (!(rand() % 10))
		board[y][x].value = 4;
	else
		board[y][x].value = 2;
}
