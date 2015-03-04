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
	init_pair(2, COLOR_BLACK, 230);
	init_pair(4, COLOR_BLACK, 228);
	init_pair(8, COLOR_BLACK, 214);
	init_pair(16, COLOR_BLACK, 202);
	init_pair(32, COLOR_BLACK, 160);
	init_pair(64, COLOR_BLACK, 88);
	init_pair(128, COLOR_BLACK, 190);
	init_pair(256, COLOR_BLACK, 226);
	init_pair(512, COLOR_BLACK, 15);
	init_pair(1024, COLOR_BLACK, 123);
	init_pair(2048, COLOR_BLACK, 51);
	init_pair(4096, COLOR_BLACK, 48);
	init_pair(8192, COLOR_WITHE, COLOR_BLACK);
	init_pair(16384, COLOR_BLACK, 196);
}
