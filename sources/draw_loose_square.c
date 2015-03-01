/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_loose_square.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:46:30 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/01 22:58:49 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

void	draw_loose_square(t_env *e)
{
	int		x;
	int		y;

	draw_all(e);
	y = getmaxy(stdscr) / 2;
	x = getmaxx(stdscr) / 2 - 22;
	attron(COLOR_PAIR(2));
	mvhline(y - 1, x - 5, ' ', 55);
	mvhline(y, x - 5, ' ', 55);
	mvhline(y + 1, x - 5, ' ', 55);
	mvhline(y + 2, x - 5, ' ', 55);
	mvhline(y + 3, x - 5, ' ', 55);
	mvprintw(y, x, "You lose, press   enter to quit   r to reset");
	mvprintw(y + 2, x + 24, "final score : %d", total_score(e));
	attroff(COLOR_PAIR(2));
}
