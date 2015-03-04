/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 01:08:42 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/02 02:13:53 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

static int	nb_lines_files(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	if ((fd = open("score.hs", O_RDONLY)) == -1)
		return (i);
	while (get_next_line(fd, &line))
	{
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

static int	is_empty(char **all)
{
	int		i;

	i = 0;
	while (all[i])
	{
		if (all[i][0] != 0)
			return (0);
		i++;
	}
	return (1);
}

static char	**sort_score(char **all)
{
	int		i;
	int		j;
	char	**result;

	if (!(result = (char **)malloc(sizeof(char *) * 5)))
		return (0);
	i = 0;
	while (i < 5)
	{
		result[i] = ft_strnew(1);;
		i++;
	}
	result[i] = NULL;
	i = 0;
	while (i < 5 && !is_empty(all))
	{
		j = 0;
		while (all[j])
		{
			if (!strchr(result[i], '='))
				result[i] = ft_strdup(all[j]);
			else if (all[j][0] && ft_atoi(ft_strsplit(result[i], '=')[1]) <
					ft_atoi(ft_strsplit(all[j], '=')[1]))
				result[i] = ft_strdup(all[j]);
			j++;
		}
		j = 0;
		while (all[j])
		{
			if (strchr(result[i], '=') &&  strchr(all[j], '=')
				&& ft_atoi(ft_strsplit(result[i], '=')[1]) ==
					ft_atoi(ft_strsplit(all[j], '=')[1]))
				all[j][0] = 0;
			j++;
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

char		**get_score(void)
{
	int     fd;
    char    *line;
	char	**all;
	int		i;

	if ((fd = open("score.hs", O_RDONLY)) == -1)
		return (NULL);
	if (!(all = (char **)malloc(sizeof(char *) * nb_lines_files() + 1)))
		return (NULL);
	i = 0;
	while (get_next_line(fd, &line))
	{
		all[i] = ft_strdup(line);
		i++;
		free(line);
	}
	all[i] = NULL;
	close(fd);
	return (sort_score(all));
}
