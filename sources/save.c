/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 02:37:29 by bchoukri          #+#    #+#             */
/*   Updated: 2015/03/02 00:11:45 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"
#include "libft.h"

void	save_best_score(int score, char *player_name)
{
	char	*line;
	int		fd;

	clear();
	line = ft_strnew(10);
	if ((fd = open("score.hs", O_CREAT | O_RDWR | O_APPEND)) == -1)
	{
		mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2 - 8, "Error open");
		return ;
	}
	line = ft_strjoin(player_name, "=");
	line = ft_strjoin(line, ft_itoa(score));
	ft_putendl_fd(line, fd);
	close(fd);
}
