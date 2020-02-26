/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 03:09:22 by msiivone          #+#    #+#             */
/*   Updated: 2019/12/23 09:14:31 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	fillmap(int *xmap, char *line)
{
	char	**strmap;
	int		x;

	x = 0;
	strmap = ft_strsplit(line, ' ');
	while (strmap[x])
	{
		xmap[x] = ft_atoi(strmap[x]);
		free(strmap[x]);
		x++;
	}
	free(strmap);
	return (x);
}

int	reader(t_map *dmap, char *filename)
{
	char	*line;
	int		x;
	int		fd;
	int		size;

	fd = open(filename, O_RDONLY);
	dmap->map = (int**)malloc(sizeof(int*) * (dmap->height + 1));
	x = 0;
	size = 0;
	while ((get_next_line(fd, &line)))
	{
		dmap->map[x] = (int*)malloc(sizeof(int) * (dmap->width + 1));
		size = fillmap(dmap->map[x], line);
		if (size != dmap->width)
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
		x++;
	}
	dmap->map[x] = NULL;
	close(fd);
	return (size);
}
