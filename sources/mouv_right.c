/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:34:56 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/01 22:44:02 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

static void	tigh_right(t_env *e, t_square board[4][4], int *x, int *y)
{
	while (*x < 3 && board[*y][*x + 1].value == 0
		&& board[*y][*x].value != 0)
	{
		board[*y][*x + 1].value = board[*y][*x].value;
		board[*y][*x + 1].changed = board[*y][*x].changed;
		board[*y][*x].value = 0;
		board[*y][*x].changed = 0;
		e->mouv = 1;
		*x += 1;
	}
}

static void	fill(t_square board[4][4], int x, int y)
{
	board[y][x + 1].value *= 2;
	board[y][x + 1].changed = 1;
	board[y][x].value = 0;
	board[y][x].changed = 0;
}

void		mouv_right_board(t_square board[4][4], t_env *e)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 3;
		while (x >= 0)
		{
			tigh_right(e, board, &x, &y);
			redraw(e);
			while (x < 3 && board[y][x + 1].value == board[y][x].value
				&& board[y][x].value != 0 && board[y][x].changed == 0
				&& !board[y][x + 1].changed)
			{
				fill(board, x, y);
				e->mouv = 1;
				x++;
			}
			tigh_right(e, board, &x, &y);
			x--;
		}
		y++;
	}
}
