/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgobeil- <pgobeil-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 23:54:42 by fguzman           #+#    #+#             */
/*   Updated: 2019/12/15 02:48:43 by pgobeil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init(t_mlx *mlx, t_p_coords *v, char *argv)
{
	v->pos.x = 22;
	v->pos.y = 12;
	v->dir.x = -1;
	v->dir.y = 0;
	v->plane.x = 0;
	v->plane.y = 0.66;
	v->time = 0;
	v->oldtime = 0;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, S_WIDTH, S_HEIGHT, "wolf3d");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, S_WIDTH, S_HEIGHT);
	mlx->pixs = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,\
	&mlx->sline, &mlx->endian);
	if (ft_strcmp(argv, "mario") == 0)
	{
		system("afplay -v 2 sounds/mario.mp3 &");
		mlx->wolf = 0;
		mlx->tex = mario_tex(mlx, 64, 64);
	}
	else
	{
		system("afplay -v 2 sounds/wolf.mp3 &");
		mlx->wolf = 1;
		mlx->tex = tex(mlx, 64, 64);
	}
}

void	cast_all_rays(t_p_coords *v, int **map, t_mlx *mlx)
{
	double		camerax;
	t_proj_ray	curslide;
	t_trigger	t;
	int			orientation;

	mlx->x = 0;
	orientation = 0;
	while (mlx->x < S_WIDTH)
	{
		orientation = 0;
		camerax = 2 * mlx->x / (double)S_WIDTH - 1;
		v->raydir.x = v->dir.x + v->plane.x * camerax;
		v->raydir.y = v->dir.y + v->plane.y * camerax;
		mapping(v, map, &curslide, &t);
		mlx->t_index = (mlx->map[v->map.x][v->map.y] - 1 + t.side) % 9;
		drawslide(&curslide, &t, v, mlx);
		mlx->x++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

void	tex_calc(t_trigger *t, t_p_coords *v)
{
	if (t->side == 0 || t->side == 1)
		v->tex.wall_x = v->pos.y + v->d.perpwalldist * v->raydir.y;
	else
		v->tex.wall_x = v->pos.x + v->d.perpwalldist * v->raydir.x;
	v->tex.wall_x -= floor((v->tex.wall_x));
	v->tex.tex_x = (int)(v->tex.wall_x * (double)(64));
	if ((t->side == 0 || t->side == 1) && v->raydir.x > 0)
		v->tex.tex_x = 64 - v->tex.tex_x - 1;
	else if (t->side > 1 && v->raydir.y < 0)
		v->tex.tex_x = 64 - v->tex.tex_x - 1;
}

void	floor_tex(t_p_coords *v, t_mlx *mlx)
{
	int y;

	v->tex.distwall = v->d.perpwalldist;
	v->tex.distplayer = 0.0;
	if (v->tex.end < 0)
		v->tex.end = S_HEIGHT;
	y = v->tex.end + 1;
	while (y < S_HEIGHT)
	{
		v->tex.currentdist = S_HEIGHT / (2.0 * y - S_HEIGHT);
		v->tex.weight = (v->tex.currentdist - v->tex.distplayer)
			/ (v->tex.distwall - v->tex.distplayer);
		v->tex.cfloor_x = v->tex.weight * v->tex.floor_x +
			(1.0 - v->tex.weight) * v->pos.x;
		v->tex.cfloor_y = v->tex.weight * v->tex.floor_y +
			(1.0 - v->tex.weight) * v->pos.y;
		v->tex.tex_x = (int)(v->tex.cfloor_x * 64) % 64;
		v->tex.tex_y = (int)(v->tex.cfloor_y * 64) % 64;
		pxto_win(mlx->x, S_HEIGHT - y, *((int *)mlx->tex[8] +
			64 * v->tex.tex_y + v->tex.tex_x), mlx);
		pxto_win(mlx->x, y, *((int *)mlx->tex[9] +
			64 * v->tex.tex_y + v->tex.tex_x), mlx);
		y++;
	}
}

void	fc_calc(t_trigger *t, t_p_coords *v)
{
	if ((t->side == 0 || t->side == 1) && v->raydir.x > 0)
	{
		v->tex.floor_x = v->map.x;
		v->tex.floor_y = v->map.y + v->tex.wall_x;
	}
	else if ((t->side == 0 || t->side == 1) && v->raydir.x < 0)
	{
		v->tex.floor_x = v->map.x + 1.0;
		v->tex.floor_y = v->map.y + v->tex.wall_x;
	}
	else if (t->side > 1 && v->raydir.y > 0)
	{
		v->tex.floor_x = v->map.x + v->tex.wall_x;
		v->tex.floor_y = v->map.y;
	}
	else
	{
		v->tex.floor_x = v->map.x + v->tex.wall_x;
		v->tex.floor_y = v->map.y + 1.0;
	}
}
