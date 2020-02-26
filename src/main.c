/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 02:54:41 by msiivone          #+#    #+#             */
/*   Updated: 2020/01/07 12:26:24 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int		currentkey(int key, t_map *data)
{
	if (key == 126 || key == 125)
		data->kyplace += key == 125 ? 10 : -10;
	if (key == 124 || key == 123)
		data->kxplace += key == 124 ? 10 : -10;
	if (key == 24 || key == 27)
		data->close += key == 24 ? 2 : -5;
	if (key == 69 || key == 78)
		data->higher += (key == 69 ? 2 : -2);
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 19 || key == 18)
		data->side = key == 19 ? 1 : 0;
	if (key == 34)
		data->ins = data->ins + 1 > 1 ? 0 : 1;
	if (key == 8)
	{
		data->csel += data->csel >= 2 ? -data->csel : 1;
		data->c = data->csel == 0 ? 0x808080 : data->c;
	}
	mlx_clear_window(data->mlx, data->win);
	if (data->ins)
		instructions(data);
	draw(data);
	return (0);
}

int		get_width(char *line)
{
	int		size;
	char	**k;

	k = ft_strsplit(line, ' ');
	size = 0;
	while (k[size])
	{
		free(k[size]);
		size++;
	}
	free(k);
	return (size);
}

int		get_height(char *filename, t_map *data)
{
	int		size;
	int		fd;
	int		comp;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	size = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		if (size == 0)
			comp = get_width(line);
		if (comp != get_width(line) && size != 0)
			return (0);
		size++;
		free(line);
	}
	data->width = comp;
	close(fd);
	return (size);
}

int		calzoom(int x, int y, t_map *map)
{
	int	bigger;
	int	zoom;

	zoom = 0;
	bigger = x > y ? x : y;
	while (bigger * zoom < 800)
	{
		zoom++;
	}
	mlx_string_put(map->mlx, map->win, 10, 10, 0x808080,
			"Press i for instructions");
	return (zoom);
}

int		main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf source_file");
		ft_putchar('\n');
		return (0);
	}
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (0);
	if (!(map->height = get_height(argv[1], map)))
		return (0);
	if (!(reader(map, argv[1])))
		return (0);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, 1300, 1300, "fdf");
	map->close = calzoom(map->width, map->height, map);
	map->c = 0x808080;
	map->higher = 0;
	map->ins = 0;
	map->kxplace = 650 - map->width / 2 * map->close;
	map->kyplace = 650 - map->height / 2 * map->close;
	mlx_key_hook(map->win, currentkey, map);
	draw(map);
	mlx_loop(map->mlx);
}
