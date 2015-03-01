/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_nb_column.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:18:13 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/01 19:18:59 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

int		square_column_size(void)
{
	int		column;
	int		i;

	column = getmaxx(stdscr) - 1;
	i = 0;
	while ((column - i) % 4 != 0)
		i++;
	return ((column - i) / 4);
}
