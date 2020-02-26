/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 02:54:49 by msiivone          #+#    #+#             */
/*   Updated: 2020/01/07 12:26:08 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/get_next_line.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef	struct	s_map
{
	int		width;
	int		height;
	int		**map;
	int		close;
	int		kxplace;
	int		kyplace;
	int		c;
	int		higher;
	int		ins;
	int		z;
	int		z1;
	int		side;
	float	x;
	float	y;
	int		csel;
	void	*mlx;
	void	*win;
}				t_map;

int				reader(t_map *dmap, char *filename);
void			draw(t_map *data);
float			bigger(float x, float y);
void			instructions(t_map *map);

#endif
