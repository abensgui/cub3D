/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:39:14 by hbouladh          #+#    #+#             */
/*   Updated: 2022/11/16 22:33:57 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_draw_wall(t_data *img)
{
	double	ca;
	int		i;
	int		j;

	player_view(img);
	img->dist = sqrt(pow(img->x_ray - img->xp, 2)
			+ pow(img->y_ray - img->yp, 2));
	ca = img->angle_player - img->angle_ray;
	img->dist = img->dist * cos(ca);
	img->h_wall = (CUBESIZE * WIN_H) / (img->dist);
	img->h_texture = img->h_wall;
	if (img->h_wall > WIN_H)
		img->h_wall = WIN_H;
	img->sd_wall = (WIN_H / 2.0) - (img->h_wall / 2.0);
	j = img->sd_wall;
	i = 0;
	while (i < img->sd_wall)
		my_mlx_pixel_put(img, img->ray_num, i++, img->color_sky);
	j = texture_walls(img, i);
	while (j < WIN_H - 1)
		my_mlx_pixel_put(img, img->ray_num, j++, img->color_floor);
}

static void	get_wall_data(t_data *img, double old_x, double old_y)
{
	if (img->map[(int)(old_y / CUBESIZE)][img->ifhit_xwall] == '1')
		img->wall_dir = 'y';
	else if (img->map[img->ifhit_ywall][(int)(old_x / CUBESIZE)] == '1')
		img->wall_dir = 'x';
	ft_draw_wall(img);
	img->angle_ray += (M_PI / 3) / (WIN_W);
	img->ray_num++;
}

static void	ft_recast_ray(t_data *img, double *s, double *c)
{
	*c = cos(img->angle_ray);
	*s = sin(img->angle_ray);
	img->x_ray = img->xp;
	img->y_ray = img->yp;
}

void	ray_casting(t_data *img)
{
	double	s;
	double	c;
	double	old_x;
	double	old_y;

	img->ray_num = 0;
	img->angle_ray = img->angle_player - (M_PI / 6);
	ft_recast_ray(img, &s, &c);
	while (img->angle_ray <= img->angle_player + M_PI / 6)
	{
		old_x = img->x_ray;
		old_y = img->y_ray;
		img->x_ray += c / 8;
		img->y_ray += s / 8;
		img->ifhit_xwall = (int)(img->x_ray / CUBESIZE);
		img->ifhit_ywall = (int)(img->y_ray / CUBESIZE);
		if (img->map[img->ifhit_ywall][img->ifhit_xwall] != '0'
			|| img->map[(int)(old_y / CUBESIZE)][img->ifhit_xwall] != '0'
			|| img->map[img->ifhit_ywall][(int)(old_x / CUBESIZE)] != '0')
		{
			get_wall_data(img, old_x, old_y);
			ft_recast_ray(img, &s, &c);
		}
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
