/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2048.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:11:31 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/01 23:42:47 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_2048_H
# define FT_2048_H
# include "libft.h"
# include <curses.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include "libft.h"

enum	e_const
{
	WIN_VALUE = -1
};
typedef struct	s_square
{
	int			value;
	int			changed;
}				t_square;
typedef struct	s_env
{
	t_square	board[4][4];
	int			square_width;
	int			square_length;
	int			mouv;
	int			win;
	int			best_score;
}				t_env;
void			save_best_score(int score);
void			draw_all(t_env *e);
void			init_numbers(t_env *e);
void			handle_key(int key, t_env *e);
void			add_rand_nb(t_square board[4][4]);
void			reset_changed(t_square board[4][4]);
void			draw_all_square(t_env *e);
int				is_end(t_env *e);
void			redraw(t_env *e);
void			init_board(t_env *e);
int				size_of_number(int num);
void			set_colors(void);
int				power(int number, int power);
int				square_row_size(void);
int				square_column_size(void);
int				total_score(t_env *e);
void			draw_win_square(t_env *e);
void			draw_loose_square(t_env *e);
void			mouv_up_board(t_square board[4][4], t_env *e);
void			mouv_down_board(t_square board[4][4], t_env *e);
void			mouv_left_board(t_square board[4][4], t_env *e);
void			mouv_right_board(t_square board[4][4], t_env *e);
#endif
