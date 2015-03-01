#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 20:41:40 by yfuks             #+#    #+#              #
#    Updated: 2015/03/01 16:33:52 by yfuks            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC =	atoi.c		\
		bzero.c		\
		isalnum.c	\
		isalpha.c	\
		isascii.c	\
		isdigit.c	\
		isprint.c	\
		itoa.c		\
		lstadd.c	\
		lstdel.c	\
		lstdelone.c	\
		lstiter.c	\
		lstmap.c	\
		lstnew.c	\
		memalloc.c	\
		memccpy.c	\
		memchr.c	\
		memcmp.c	\
		memcpy.c	\
		memdel.c	\
		memmove.c	\
		memset.c	\
		putchar.c	\
		putchar_fd.c\
		putendl.c	\
		putendl_fd.c\
		putnbr.c	\
		putnbr_fd.c	\
		putstr.c	\
		putstr_fd.c	\
		strcat.c	\
		strchr.c	\
		strcmp.c	\
		strcpy.c	\
		strcrl.c	\
		strdel.c	\
		strdup.c	\
		strequ.c	\
		striter.c	\
		striteri.c	\
		strjoin.c	\
		strlcat.c	\
		strlen.c	\
		strmap.c	\
		strmapi.c	\
		strncat.c	\
		strncmp.c	\
		strncpy.c	\
		strnequ.c	\
		strnew.c	\
		strnstr.c	\
		strrchr.c	\
		strsplit.c	\
		strstr.c	\
		strsub.c	\
		strtrim.c	\
		tolower.c	\
		toupper.c	\
		strappend.c	\
		strchngchr.c\
		get_next_line.c

HEAD = ./includes

OBJ = 	atoi.o      \
        bzero.o     \
        isalnum.o   \
        isalpha.o   \
        isascii.o   \
        isdigit.o   \
        isprint.o   \
        itoa.o      \
        lstadd.o    \
        lstdel.o    \
        lstdelone.o \
        lstiter.o   \
        lstmap.o    \
        lstnew.o    \
        memalloc.o  \
        memccpy.o   \
        memchr.o    \
        memcmp.o    \
        memcpy.o    \
        memdel.o    \
        memmove.o   \
        memset.o    \
        putchar.o   \
        putchar_fd.o\
        putendl.o   \
        putendl_fd.o\
        putnbr.o    \
        putnbr_fd.o \
        putstr.o    \
        putstr_fd.o \
        strcat.o    \
        strchr.o    \
        strcmp.o    \
        strcpy.o    \
        strcrl.o    \
        strdel.o    \
        strdup.o    \
		strequ.o    \
        striter.o   \
        striteri.o  \
        strjoin.o   \
        strlcat.o   \
        strlen.o    \
        strmap.o    \
        strmapi.o   \
        strncat.o   \
        strncmp.o   \
        strncpy.o   \
        strnequ.o   \
        strnew.o    \
        strnstr.o   \
        strrchr.o   \
        strsplit.o  \
        strstr.o    \
        strsub.o    \
        strtrim.o   \
        tolower.o   \
        toupper.o	\
		strappend.o	\
		strchngchr.o\
		get_next_line.o

all : $(NAME)

$(NAME):
	@echo "Compiling .."
	@gcc -Wall -Wextra -Werror -c $(SRC) -I $(HEAD) && ar rc $(NAME) $(OBJ)
	@echo "Done !"

clean:
	@echo "Remove .o  ..."
	@/bin/rm -f $(OBJ)
	@echo "Done !"

fclean: clean
	@echo "Remove lib ..."
	@/bin/rm -f $(NAME)
	@echo "Done !" 

re: fclean all