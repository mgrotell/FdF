/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 03:51:50 by msiivone          #+#    #+#             */
/*   Updated: 2020/01/07 12:03:28 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"
#include <math.h>

void	escape(float *x, float *y, int z, t_map *data)
{
	if (data->side == 1)
	{
		*x = (*x - *y) * cos(0.8);
		*y = (*x + *y) * sin(0.8) - z;
	}
	*x *= data->close;
	*y *= data->close;
	*x += data->kxplace;
	*y += data->kyplace;
}

void	setcolor(t_map *data)
{
	if (data->csel == 1)
		data->c = ((data->z1) || (data->z) ? 0x20B2AA : 0x808080);
	if (data->csel == 2)
		data->c = ((data->z1 > 99) || (data->z > 99) ? 0x20B2AA : 0xDC143C);
}

void	bham(float x1, float y1, t_map *data)
{
	float	xs;
	float	ys;
	int		max;

	data->z += (data->z) ? data->higher : 0;
	data->z1 += (data->z1) ? data->higher : 0;
	setcolor(data);
	escape(&data->x, &data->y, data->z, data);
	escape(&x1, &y1, data->z1, data);
	xs = x1 - data->x;
	ys = y1 - data->y;
	max = bigger(xs, ys);
	ys /= max;
	xs /= max;
	xs /= 2;
	ys /= 2;
	while ((int)(data->x - x1) || (int)(data->y - y1))
	{
		mlx_pixel_put(data->mlx, data->win, data->x, data->y, data->c);
		data->x += xs;
		data->y += ys;
	}
}

void	setxy(float x, float y, t_map *data)
{
	data->x = x;
	data->y = y;
	data->z = data->map[(int)y][(int)x];
}

void	draw(t_map *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				data->z1 = data->map[y][x + 1];
				setxy(x, y, data);
				bham(x + 1, y, data);
			}
			if (y < data->height - 1)
			{
				data->z1 = data->map[y + 1][x];
				setxy(x, y, data);
				bham(x, y + 1, data);
			}
			x++;
		}
		y++;
	}
}
