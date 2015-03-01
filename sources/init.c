/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:31:22 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/01 23:30:25 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

static int	high_score(void)
{
	int		fd;
	char	*line;
	char	**split;
	int		best;

	split = NULL;
	best = 0;
	if ((fd = open("score.hs", O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line))
	{
		if (ft_strchr(line, '='))
			split = ft_strsplit(line, '=');
		free(line);
		if (split[1])
			if (ft_atoi(split[1]) > best)
				best = ft_atoi(split[1]);
	}
	close(fd);
	return (best);
}

void		init_board(t_env *e)
{
	int		i;

	i = 0;
	while (power(2, i) != WIN_VALUE)
		i++;
	e->win = i;
	e->best_score = high_score();
	init_numbers(e);
	draw_all(e);
	set_colors();
}
