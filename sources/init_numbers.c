/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:42:14 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/01 21:55:57 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

static void	put_two_random_two(t_square board[4][4])
{
	int		i;
	int		x;
	int		y;

	srand(time(NULL));
	x = rand() % 4;
	y = rand() % 4;
	i = 0;
	while (i < 2)
	{
		while (board[y][x].value != 0)
		{
			x = rand() % 4;
			y = rand() % 4;
		}
		if (!(rand() % 10))
			board[y][x].value = 4;
		else
			board[y][x].value = 2;
		i++;
	}
}

void		init_numbers(t_env *e)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			e->board[y][x].value = 0;
			e->board[y][x].changed = 0;
			x++;
		}
		y++;
	}
	put_two_random_two(e->board);
}
