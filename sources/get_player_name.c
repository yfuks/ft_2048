/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 01:05:18 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/02 02:01:06 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

void	get_player_name(t_env *e)
{
	char	*line;

	clear();
	line = ft_strnew(10);
	mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2 - 8, "Enter your name :");
	move(getmaxy(stdscr) / 2 + 2, getmaxx(stdscr) / 2 - 3);
	curs_set(1);
	echo();
	refresh();
	getnstr(line, 10);
	curs_set(0);
	noecho();
	e->player_name = line;
}
