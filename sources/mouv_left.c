/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:28:26 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/01 22:43:46 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

static void	tigh_left(t_env *e, t_square board[4][4], int *x, int *y)
{
	while (*x > 0 && board[*y][*x - 1].value == 0
		&& board[*y][*x].value != 0)
	{
		board[*y][*x - 1].value = board[*y][*x].value;
		board[*y][*x - 1].changed = board[*y][*x].changed;
		board[*y][*x].value = 0;
		board[*y][*x].changed = 0;
		e->mouv = 1;
		*x -= 1;
	}
}

static void	fill(t_square board[4][4], int x, int y)
{
	board[y][x - 1].value *= 2;
	board[y][x - 1].changed = 1;
	board[y][x].value = 0;
	board[y][x].changed = 0;
}

void		mouv_left_board(t_square board[4][4], t_env *e)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			tigh_left(e, board, &x, &y);
			redraw(e);
			while (x > 0 && board[y][x - 1].value == board[y][x].value
				&& board[y][x].value != 0 && board[y][x].changed == 0
				&& !board[y][x - 1].changed)
			{
				fill(board, x, y);
				e->mouv = 1;
				x--;
			}
			tigh_left(e, board, &x, &y);
			x++;
		}
		y++;
	}
}
