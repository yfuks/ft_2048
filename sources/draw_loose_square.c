/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_loose_square.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:46:30 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/02 06:07:46 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

void	draw_loose_square(t_env *e, int i)
{
	int		x;
	int		y;

	clear();
	draw_all(e);
	y = getmaxy(stdscr) / 2;
	x = getmaxx(stdscr) / 2 - 22;
	attron(COLOR_PAIR(2));
	mvhline(y - 1, x - 5, ' ', 55);
	mvhline(y, x - 5, ' ', 55);
	mvhline(y + 1, x - 5, ' ', 55);
	mvhline(y + 2, x - 5, ' ', 55);
	mvhline(y + 3, x - 5, ' ', 55);
	mvprintw(y, x + 18, "You lose");
	attroff(COLOR_PAIR(2));
	if (i == 0)
		attron(COLOR_PAIR(4));
	mvprintw(y + 2, x - 4, "retry");
	if (i == 0)
		attroff(COLOR_PAIR(4));
	if (i == 1)
		attron(COLOR_PAIR(4));
	mvprintw(y + 2, x + 20, "quit");
	if (i == 1)
		attroff(COLOR_PAIR(4));
	if (i == 2)
		attron(COLOR_PAIR(4));
	mvprintw(y + 2, x + 44, "save");
	if (i == 2)
		attron(COLOR_PAIR(4));
}
