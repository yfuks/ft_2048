#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 23:02:19 by yfuks             #+#    #+#              #
#    Updated: 2015/03/04 17:28:06 by yfuks            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = game_2048

SRC =	sources/main.c 				\
		sources/number.c 			\
		sources/mouvement.c			\
		sources/square.c 			\
		sources/end.c 				\
		sources/tools.c 			\
		sources/save.c				\
		libft/libft.a				\
		sources/power.c				\
		sources/color.c				\
		sources/draw.c				\
		sources/square_nb_row.c		\
		sources/square_nb_column.c	\
		sources/total_score.c		\
		sources/redraw.c			\
		sources/init.c				\
		sources/init_numbers.c		\
		sources/draw_win_square.c	\
		sources/draw_loose_square.c	\
		sources/reset.c				\
		sources/mouv_up.c			\
		sources/mouv_down.c			\
		sources/mouv_left.c			\
		sources/mouv_right.c		\
		sources/menu.c				\
		sources/get_player_name.c	\
		sources/get_score.c			\
		sources/put_credits.c		\
		sources/what_power.c

HEAD = -I ./includes

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIB = -lncurses

all : $(NAME)

$(NAME) :
	@make -C ./libft
	@echo "Compile..."
	@gcc $(FLAGS) $(SRC) $(HEAD) $(LIB) -o $(NAME)
	@echo "Done !"

clean :
	@make -C ./libft clean
	@echo "Remove .o..."
	@/bin/rm -f $(OBJ)
	@echo "Done !"

fclean : clean
	@make -C ./libft fclean
	@echo "Remove exe..."
	@/bin/rm -f $(NAME)
	@echo "Done !"

re : fclean all