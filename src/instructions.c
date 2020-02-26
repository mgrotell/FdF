/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:04:52 by msiivone          #+#    #+#             */
/*   Updated: 2020/01/07 12:21:01 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	instructions(t_map *map)
{
	mlx_string_put(map->mlx, map->win, 10, 10, 0x808080,
			"Press 1, 2 to change view (paraller, isometric)");
	mlx_string_put(map->mlx, map->win, 10, 30, 0x808080,
			"Press c to change color");
	mlx_string_put(map->mlx, map->win, 10, 50, 0x808080,
			"Press arrow keys to move object");
	mlx_string_put(map->mlx, map->win, 10, 70, 0x808080,
			"Press + - to zoom");
	mlx_string_put(map->mlx, map->win, 10, 90, 0x808080,
			"Press numpad + - to change height");
}
