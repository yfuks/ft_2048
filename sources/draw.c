/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:06:15 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/04 18:37:25 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

static int		draw_numbers(t_env *e)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			attron(COLOR_PAIR(what_power(e->board[y][x].value)));
			if (e->board[y][x].value != 0)
				mvprintw((y * e->square_length) + e->square_length / 2 + 3,
						(x * e->square_width) + e->square_width / 2
						- (size_of_number(e->board[y][x].value) / 2),
						"%d", e->board[y][x].value);
			attroff(COLOR_PAIR(e->board[y][x].value));
			x++;
		}
		y++;
	}
	return (1);
}

static void		draw_title(t_env *e)
{
	attron(COLOR_PAIR(16));
	move(0, 0);
	whline(stdscr, ' ', e->square_width * 4 + 1);
	move(1, 0);
	whline(stdscr, ' ', e->square_width * 4 + 1);
	move(2, 0);
	whline(stdscr, ' ', e->square_width * 4 + 1);
	mvprintw(1, 5, "%d", power(2, e->win));
	if (total_score(e) > e->best_score)
		e->best_score = total_score(e);
	mvprintw(1, getmaxx(stdscr) - 35, "Score : %d HighScore : %d",
			total_score(e), e->best_score);
	attroff(COLOR_PAIR(16));
}

static void		draw_board(t_env *e)
{
	int		i;

	e->square_length = square_row_size();
	e->square_width = square_column_size();
	start_color();
	attron(COLOR_PAIR(15));
	i = 0;
	while (i < 5)
	{
		move(3, e->square_width * i);
		wvline(stdscr, ' ', e->square_length * 4);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		move(e->square_length * i + 3, 0);
		whline(stdscr, ' ', e->square_width * 4 + 1);
		i++;
	}
	attroff(COLOR_PAIR(15));
	draw_title(e);
}

void			draw_all(t_env *e)
{
	draw_board(e);
	draw_all_square(e);
	draw_numbers(e);
}
