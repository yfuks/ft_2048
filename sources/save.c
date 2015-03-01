/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 02:37:29 by bchoukri          #+#    #+#             */
/*   Updated: 2015/03/01 23:36:16 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"
#include "libft.h"

void	save_best_score(int score)
{
	char	*line;
	int		fd;

	clear();
	line = ft_strnew(10);
	if ((fd = open("score.hs", O_CREAT | O_WRONLY | O_APPEND)) == -1)
	{
		mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2 - 8, "Error open");
		return ;
	}
	mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2 - 8, "Enter your name :");
	move(getmaxy(stdscr) / 2 + 2, getmaxx(stdscr) / 2 - 3);
	curs_set(1);
	echo();
	getnstr(line, 10);
	curs_set(0);
	noecho();
	line = ft_strjoin(line, "=");
	line = ft_strjoin(line, ft_itoa(score));
	ft_putendl_fd(line, fd);
	close(fd);
}
