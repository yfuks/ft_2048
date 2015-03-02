/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 06:53:49 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/02 05:23:54 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

static int		win_value_found(t_env *e)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (e->board[y][x].value == power(2, e->win))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int		check_loose(t_env *e)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (x < 3 && e->board[y][x].value == e->board[y][x + 1].value)
				return (0);
			if (y < 3 && e->board[y][x].value == e->board[y + 1][x].value)
				return (0);
			if (e->board[y][x].value == 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int		draw_win(t_env *e)
{
	int		c;

	draw_all(e);
	draw_win_square(e);
	e->win++;
	while ((c = getch()))
	{
		if (c == 'c')
			return (1);
		else if (c == 'q')
			return (0);
		else if (c == 's' && total_score(e) > e->best_score)
		{
			save_best_score(total_score(e), e->player_name);
			e->best_score = total_score(e);
			return (1);
		}
	}
	return (0);
}

static int		draw_loose(t_env *e)
{
	int		key;

	key = 0;
	keypad(stdscr, TRUE);
	draw_loose_square(e);
	while (key != 10)
	{
		key = getch();
		if (key == 114)
		{
			clear();
			init_board(e);
			return (1);
		}
		if (key == 's')
		{
			save_best_score(tota_score(e), e->player_name);
			return (0);
		}
	}
	return (0);
}

int				is_end(t_env *e)
{
	if (e->mouv == 1)
	{
		if (check_loose(e) == 1)
		{
			if (draw_loose(e) == 1)
				return (2);
			return (1);
		}
	}
	if (win_value_found(e))
	{
		if (!draw_win(e))
			return (1);
	}
	clear();
	return (0);
}
