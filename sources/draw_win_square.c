/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_win_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:52:31 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/01 23:22:40 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

void	draw_win_square(t_env *e)
{
	int		x;
	int		y;

	y = getmaxy(stdscr) / 2;
	x = getmaxx(stdscr) / 2 - 17;
	attron(COLOR_PAIR(2));
	mvhline(y - 1, x - 10, ' ', 55);
	mvhline(y, x - 10, ' ', 55);
	mvhline(y + 1, x - 10, ' ', 55);
	mvhline(y + 2, x - 10, ' ', 55);
	mvhline(y + 3, x - 10, ' ', 55);
	mvprintw(y, x, "Congratulation ! You just reach %d", power(2, e->win));
	mvprintw(y + 2, x - 5, "Press c to continue   q to quit");
	if (total_score(e) > e->best_score)
		mvprintw(y + 2, x + 29, "s to save");
	attroff(COLOR_PAIR(2));
}
