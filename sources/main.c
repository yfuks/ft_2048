/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:09:19 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/02 01:43:36 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

static int	is_power2(void)
{
	int	i;

	i = 2;
	while (i <= WIN_VALUE)
	{
		if (i == WIN_VALUE)
			return (0);
		i = i * 2;
	}
	ft_putendl_fd("Win value isn't a power of 2", 2);
	return (1);
}

static int	is_too_small(void)
{
	if (getmaxy(stdscr) < 15 || getmaxx(stdscr) < 40)
		return (1);
	return (0);
}

static int	init_main(t_env *e)
{
	if (is_power2() == 1)
		return (0);
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	init_board(e);
	return (1);
}

int			main(void)
{
	int		a;
	t_env	e;

	if (!init_main(&e) || !put_menu())
		return (0);
	get_player_name(&e);
	a = -20;
	while ((a == -20 || (a = getch()) != 27) && !is_too_small())
	{
		e.mouv = 0;
		handle_key(a, &e);
		reset_changed(e.board);
		if ((a == KEY_UP || a == KEY_DOWN || a == KEY_LEFT || a == KEY_RIGHT)
			&& e.mouv == 1)
		{
			clear();
			add_rand_nb(e.board);
		}
		if (is_end(&e) == 1)
			break ;
		draw_all(&e);
		refresh();
		a = 0;
	}
	if (is_too_small())
		ft_putendl_fd("Window too small, exiting", 2);
	endwin();
	return (0);
}
