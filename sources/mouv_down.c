/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:12:30 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/01 22:27:34 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

static void	tigh_down(t_env *e, t_square board[4][4], int *x, int *y)
{
	while (*y < 3 && board[*y + 1][*x].value == 0
		&& board[*y][*x].value != 0)
	{
		board[*y + 1][*x].value = board[*y][*x].value;
		board[*y + 1][*x].changed = board[*y][*x].changed;
		board[*y][*x].value = 0;
		board[*y][*x].changed = 0;
		e->mouv = 1;
		*y += 1;
	}
}

static void	fill(t_square board[4][4], int x, int y)
{
	board[y + 1][x].value *= 2;
	board[y + 1][x].changed = 1;
	board[y][x].value = 0;
	board[y][x].changed = 0;
}

void		mouv_down_board(t_square board[4][4], t_env *e)
{
	int		x;
	int		y;

	x = 0;
	while (x < 4)
	{
		y = 3;
		while (y >= 0)
		{
			tigh_down(e, board, &x, &y);
			redraw(e);
			while (y < 3 && board[y + 1][x].value == board[y][x].value
				&& board[y][x].value != 0 && board[y][x].changed == 0
				&& !board[y + 1][x].changed)
			{
				fill(board, x, y);
				e->mouv = 1;
				y++;
			}
			tigh_down(e, board, &x, &y);
			y--;
		}
		x++;
	}
}
