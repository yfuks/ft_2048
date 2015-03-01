/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:03:09 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/01 21:49:24 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

void		set_colors(void)
{
	init_color(COLOR_RED, 400, 400, 400);
	init_color(COLOR_BLUE, 800, 800, 800);
	init_pair(2, COLOR_BLACK, COLOR_BLUE);
	init_color(COLOR_GREEN, 200, 600, 800);
	init_pair(4, COLOR_BLACK, COLOR_GREEN);
	init_color(COLOR_YELLOW, 1000, 650, 000);
	init_pair(8, COLOR_BLACK, COLOR_YELLOW);
	init_color(COLOR_MAGENTA, 1000, 450, 000);
	init_pair(16, COLOR_BLACK, COLOR_MAGENTA);
	init_color(COLOR_CYAN, 1000, 150, 000);
	init_pair(32, COLOR_BLACK, COLOR_CYAN);
	init_pair(64, COLOR_BLACK, COLOR_BLUE);
	init_pair(128, COLOR_BLACK, COLOR_GREEN);
	init_pair(256, COLOR_BLACK, COLOR_YELLOW);
	init_pair(512, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(1024, COLOR_BLACK, COLOR_CYAN);
	init_pair(2048, COLOR_BLACK, COLOR_CYAN);
	init_pair(4096, COLOR_BLACK, COLOR_BLUE);
	init_pair(8192, COLOR_BLACK, COLOR_GREEN);
	init_pair(16384, COLOR_BLACK, COLOR_YELLOW);
}
