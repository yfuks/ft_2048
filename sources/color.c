/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:03:09 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/04 17:57:02 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

void		set_colors(void)
{
	init_pair(1, COLOR_BLACK, 230); // 2
	init_pair(2, COLOR_BLACK, 228); // 4
	init_pair(3, COLOR_BLACK, 215); // 8
	init_pair(4, COLOR_BLACK, 208); // 16
	init_pair(5, COLOR_BLACK, 202); // 32
	init_pair(6, COLOR_BLACK, 88);  // 64
	init_pair(7, COLOR_BLACK, 192); // 128
	init_pair(8, COLOR_BLACK, 226); // 256
	init_pair(9, COLOR_BLACK, 15);  // 1024
	init_pair(10, COLOR_BLACK, 120);// 2048
	init_pair(11, COLOR_BLACK, 51); // 4096
	init_pair(12, COLOR_BLACK, 48); // 8182
	init_pair(13, COLOR_WHITE, COLOR_BLACK); // 16364
	init_pair(14, COLOR_BLACK, 196);// 32728
	init_pair(15, COLOR_WHITE, 253);// Border board
	init_pair(16, COLOR_WHITE, 68); // Menu color
}
