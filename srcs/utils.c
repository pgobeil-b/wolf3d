/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgobeil- <pgobeil-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:47:55 by pgobeil-          #+#    #+#             */
/*   Updated: 2019/12/15 02:59:21 by pgobeil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

char	**tex(t_mlx *mlx, int x, int y)
{
	mlx->tex = (char **)malloc(sizeof(char *) * 10);
	mlx->tex[0] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/purple.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	mlx->tex[1] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/eagle.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	mlx->tex[2] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/color.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	mlx->tex[3] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/blue.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	mlx->tex[4] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/wgoal.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	mlx->tex[5] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/wgoal2.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	mlx->tex[6] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/wgoal3.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	mlx->tex[7] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/wgoal4.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	mlx->tex[8] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/wood.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	mlx->tex[9] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/grey.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	return (mlx->tex);
}

char	**mario_tex(t_mlx *mlx, int x, int y)
{
	mlx->tex = (char **)malloc(sizeof(char *) * 10);
	mlx->tex[0] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/mariowall.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	mlx->tex[1] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/mariowall2.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	mlx->tex[2] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/mariohill.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	mlx->tex[3] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/pipe.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	mlx->tex[4] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/goal.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	mlx->tex[5] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/goal2.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	mlx->tex[6] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/goal3.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	mlx->tex[7] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/goal4.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	mlx->tex[8] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/marioceiling.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	mlx->tex[9] = mlx_get_data_addr((mlx_xpm_file_to_image(mlx->mlx_ptr,\
	"./pics/marioground.xpm", &x, &y)), &mlx->bpp, &mlx->sline, &mlx->endian);
	return (mlx->tex);
}

void	toggle_goal_sound(int mode)
{
	system("pkill afplay");
	if (mode == 0)
		system("afplay -v 2 sounds/goal.mp3 &");
	else
		system("afplay -v 2 sounds/america.mp3 &");
}

void	pxto_win(int x, int y, int color, t_mlx *mlx)
{
	int index;

	color = mlx_get_color_value(mlx->mlx_ptr, color);
	index = (4 * S_WIDTH * y + x * 4);
	ft_memcpy(mlx->pixs + index, &color, sizeof(int));
}

int		**give_map(void)
{
	int		**map;
	int		i;

	i = 0;
	map = (int **)malloc(sizeof(int *) * WIDTH);
	while (i < HEIGHT)
	{
		map[i] = (int *)malloc(sizeof(int) * HEIGHT);
		i++;
	}
	return (map);
}
