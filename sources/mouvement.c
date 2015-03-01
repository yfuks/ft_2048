/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 03:06:20 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/01 22:42:26 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

void		handle_key(int key, t_env *e)
{
	if (key == KEY_UP)
		mouv_up_board(e->board, e);
	else if (key == KEY_DOWN)
		mouv_down_board(e->board, e);
	else if (key == KEY_LEFT)
		mouv_left_board(e->board, e);
	else if (key == KEY_RIGHT)
		mouv_right_board(e->board, e);
}
