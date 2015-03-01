/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 04:54:55 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/01 19:03:59 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

static void	draw_square(int x, int y, t_env *e, int value)
{
	int		row;
	int		column;

	attron(COLOR_PAIR(value));
	row = y * e->square_length + 4;
	while (row < (y + 1) * e->square_length + 3)
	{
		column = x * e->square_width + 1;
		while (column < (x + 1) * e->square_width)
		{
			mvaddch(row, column, ' ');
			column++;
		}
		row++;
	}
	attroff(COLOR_PAIR(value));
}

void		draw_all_square(t_env *e)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (e->board[y][x].value != 0)
				draw_square(x, y, e, e->board[y][x].value);
			x++;
		}
		y++;
	}
}
