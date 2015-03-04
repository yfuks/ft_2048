/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 00:08:52 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/04 18:10:27 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

static void	put_tab(int y, int x, int i)
{
	clear();
	if (i == 0)
		attron(COLOR_PAIR(2));
	mvhline(y - 1, x - 4, ' ', 20);
	mvprintw(y, x - 4, "      New GAME      ");
	mvhline(y + 1, x - 4, ' ', 20);
	if (i == 0)
		attroff(COLOR_PAIR(2));
	if (i == 1)
		attron(COLOR_PAIR(2));
	mvhline(y + 3, x - 4, ' ', 20);
	mvprintw(y + 4, x - 4, "    High scores     ");
	mvhline(y + 5, x - 4, ' ', 20);
	if (i == 1)
		attroff(COLOR_PAIR(2));
	if (i == 2)
		attron(COLOR_PAIR(2));
	mvhline(y + 7, x - 4, ' ', 20);
	mvprintw(y + 8, x - 4, "      Credits       ");
	mvhline(y + 9, x - 4, ' ', 20);
	if (i == 2)
		attroff(COLOR_PAIR(2));
	refresh();
}

static void	put_high_2(char **tab)
{
	int		x;
	int		y;	
	int		i;
	char	**split;

	clear();
	y = getmaxy(stdscr) / 2 - getmaxy(stdscr) / 4;
    x = getmaxx(stdscr) / 2 - 6;
	attron(COLOR_PAIR(2));
	mvhline(y - 2, x - 5, ' ', 25);
	mvprintw(y - 1, x - 5, "       HIGH SCORES       ");
	mvhline(y, x - 5, ' ', 25);
	attroff(COLOR_PAIR(2));
	i = 0;
	while (i < 5 && tab[i])
	{
		if (strchr(tab[i], '='))
		{
			split = ft_strsplit(tab[i], '=');
			if (i == 0)
				attron(COLOR_PAIR(32));
			else if (i == 1 || i == 2)
				attron(COLOR_PAIR(4));
			else
				attron(COLOR_PAIR(2));
			mvhline(y + i * 4 + 2, x - 5, ' ', 12);
			mvhline(y + i * 4 + 3, x - 5, ' ', 12);
			mvprintw(y + i * 4 + 3, x - ft_strlen(split[0]) / 2 + 1, "%s", split[0]);
			mvhline(y + i * 4 + 4, x - 5, ' ', 12);
			if (i == 0)
				attroff(COLOR_PAIR(32));
			else if (i == 1 || i == 2)
				attroff(COLOR_PAIR(4));
			else
				attroff(COLOR_PAIR(2));
			attron(COLOR_PAIR(8));
			mvhline(y + i * 4 + 2, x + 8, ' ', 12);
			mvhline(y + i * 4 + 3, x + 8, ' ', 12);
			mvhline(y + i * 4 + 4, x + 8, ' ', 12);
			mvprintw(y + i * 4 + 3, x + 17 - size_of_number(ft_atoi(split[1])), "%s", split[1]);
			attroff(COLOR_PAIR(8));
		}
		i++;
	}
	refresh();
}

static void	put_high_score(void)
{
	int		a;
	char	**tab;

	a = 0;
	tab = get_score();
	put_high_2(tab);
	while (a != 27)
	{
		a = getch();
		put_high_2(tab);
	}
}

int			put_menu(void)
{
	int		x;
	int		y;
	int		c;
	int		i;

	clear();
	refresh();
	c = 0;
	i = 0;
	y = getmaxy(stdscr) / 2 - 4;
	x = getmaxx(stdscr) / 2 - 4;
	put_tab(y, x, i);
	while (c != 10 && c != 27)
	{
		c = getch();
		y = getmaxy(stdscr) / 2 - 4;
		x = getmaxx(stdscr) / 2 - 4;
		if (c == KEY_DOWN && i < 2)
			i++;
		else if (c == KEY_UP && i > 0)
			i--;
		else if (c == 10 && i == 1)
		{
			put_high_score();
			c = 0;
		}
		else if (c == 10 && i == 2)
		{
			put_credits();
			c = 0;
		}
		put_tab(y, x, i);
	}
	if (c == 27)
		return (0);
	return (1);
}
