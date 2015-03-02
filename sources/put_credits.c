/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_credits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 02:51:50 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/02 05:10:43 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

pid_t		g_father;

static void	play_music(char *path)
{
	char	*cmd[3];

	cmd[0] = ft_strdup("/usr/bin/afplay");
	cmd[1] = ft_strdup(path);
	cmd[2] = NULL;
	g_father = fork();
	if (g_father == 0)
	{
		if (!(execve(cmd[0], cmd, NULL)))
			ft_putendl_fd("can't play music", 2);
	}
	free(cmd[0]);
	free(cmd[1]);
}

void		put_credits(void)
{
	int		x;
	int		y;
	int		i;
	int		b;
	char	*tab[41];

	clear();
	refresh();
	y = getmaxy(stdscr) / 2;
	x = getmaxx(stdscr) / 2;
	mvprintw(y - 1, x - ft_strlen("Chargement ...") / 2, "Chargement ...");
	refresh();
	tab[0] = ft_strdup("Moi je l'ai vu mais c'est la vie");
	tab[1] = ft_strdup("il m'a pas connu je n'ai pas cru");
	tab[2] = ft_strdup("hier je revais qu'il m'a touché");
	tab[3] = ft_strdup("avant hier il a dansé avec moi");
	tab[4] = ft_strdup("(d)ans mes reves, (d)ans mes reves, (d)ans mes reves, (d)ans mes reves");
	tab[5] = ft_strdup(" ");
	tab[6] = ft_strdup("joli garcon aime moi, ne dis pas aurevoir");
	tab[7] = ft_strdup("joli garcon aime moi, ne dis pas aurevoir");
	tab[8] = ft_strdup("joli garcon aime moi, ne dis pas aurevoir");
	tab[9] = ft_strdup("joli garcon aime moi, ne dis pas aurevoir");
	tab[10] = ft_strdup("joli garcon aime moi, ne dis pas aurevoir");
	tab[11] = ft_strdup("joli garcon aime moi, ne dis pas aurevoir");
	tab[12] = ft_strdup(" ");
	tab[13] = ft_strdup("Je l'ai vu la plus femme que j'ai jamais vu");
	tab[14] = ft_strdup(" ");
	tab[15] = ft_strdup("on peut dire qu'il se moque de moi");
	tab[16] = ft_strdup("j'ai une envie folle de toi");
	tab[17] = ft_strdup("on peut dire je suis folle comme ca");
	tab[18] = ft_strdup("j'aimerais bien t'embrasser");
	tab[19] = ft_strdup("mon chérie ne b(a)ise pas l'autre fille, mon chérie ne b(a)ise pas l'autre fille");
	tab[20] = ft_strdup("Joli garcon");
	tab[21] = ft_strdup(" ");
	tab[22] = ft_strdup("Je l'ai vu la plus belle femme");
	tab[23] = ft_strdup("joli garcon");
	tab[24] = ft_strdup("que j'ai jamais vu");
	tab[25] = ft_strdup("ne dit pas aurevoir");
	tab[26] = ft_strdup(" ");
	tab[27] = ft_strdup("joli garcon aime moi, ne dis pas aurevoir");
	tab[28] = ft_strdup("joli garcon aime moi, ne dis pas aurevoir");
	tab[29] = ft_strdup("joli garcon aime moi, ne dis pas aurevoir");
	tab[30] = ft_strdup("joli garcon aime moi, ne dis pas aurevoir");
	tab[31] = ft_strdup(" ");
	tab[32] = ft_strdup("je l'ai vu");
	tab[33] = ft_strdup("joli garcon aime moi, ne dis pas aurevoir");
	tab[34] = ft_strdup("joli garcon aime moi, ne dis pas aurevoir");
	tab[35] = ft_strdup("joli garcon aime moi, ne dis pas aurevoir");
	tab[36] = ft_strdup("joli garcon aime moi, ne dis pas aurevoir");
	tab[37] = ft_strdup("joli garcon aime moi, ne dis pas aurevoir");
	tab[38] = ft_strdup("joli garcon aime moi, ne dis pas aurevoir");
	tab[39] = ft_strdup(" ");
	tab[40] = ft_strdup(" Joli Garçon - Lolita");
	clear();
	refresh();
	play_music("music/lolita.mp3");
	b = 0;
	sleep(11);
	while (b < 120)
	{
		y = getmaxy(stdscr);
		x = getmaxx(stdscr) / 2;
		clear();
		i = 0;
		while (i < 41)
		{
			if (y + i * 2 - b < getmaxy(stdscr) && y + i * 2 - b > 0)
				mvprintw(y + i * 2 - b, x - ft_strlen(tab[i]) / 2, tab[i]);
			i++;
		}
		b++;
		if (b < 85)
			usleep(1900000);
		else
			usleep(500000);
		refresh();
	}
	i = 0;
	while (i < 41)
	{
		free(tab[i]);
		i++;
	}
	kill(g_father, SIGKILL);
}
