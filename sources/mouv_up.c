/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:02:21 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/01 22:26:18 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

static void	tigh_up(t_env *e, t_square board[4][4], int *x, int *y)
{
	while (*y > 0 && board[*y - 1][*x].value == 0 &&
		board[*y][*x].value != 0)
	{
		board[*y - 1][*x].value = board[*y][*x].value;
		board[*y - 1][*x].changed = board[*y][*x].changed;
		board[*y][*x].value = 0;
		board[*y][*x].changed = 0;
		e->mouv = 1;
		*y -= 1;
	}
}

static void	fill(t_square board[4][4], int x, int y)
{
	board[y - 1][x].value *= 2;
	board[y - 1][x].changed = 1;
	board[y][x].value = 0;
	board[y][x].changed = 0;
}

void		mouv_up_board(t_square board[4][4], t_env *e)
{
	int		x;
	int		y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			tigh_up(e, board, &x, &y);
			redraw(e);
			while (y > 0 && board[y - 1][x].value == board[y][x].value
			&& board[y][x].value != 0 && !board[y][x].changed
			&& !board[y - 1][x].changed)
			{
				fill(board, x, y);
				e->mouv = 1;
				y--;
			}
			tigh_up(e, board, &x, &y);
			y++;
		}
		x++;
	}
}
