/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:32:07 by hbouladh          #+#    #+#             */
/*   Updated: 2022/11/16 22:06:53 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_step(t_data *img)
{
	img->new_xp_front = img->xp + (cos(img->angle_player) * MOVESPEED);
	img->new_yp_front = img->yp + (sin(img->angle_player) * MOVESPEED);
	img->new_xp_back = img->xp - cos(img->angle_player) * MOVESPEED;
	img->new_yp_back = img->yp - sin(img->angle_player) * MOVESPEED;
	img->new_xp_left = img->xp + sin(img->angle_player) * MOVESPEED;
	img->new_yp_left = img->yp - cos(img->angle_player) * MOVESPEED;
	img->new_xp_right = img->xp - sin(img->angle_player) * MOVESPEED;
	img->new_yp_right = img->yp + cos(img->angle_player) * MOVESPEED;
	img->x_wall_front = (int)(img->new_xp_front / CUBESIZE);
	img->y_wall_front = (int)(img->new_yp_front / CUBESIZE);
	img->x_wall_back = (int)(img->new_xp_back / CUBESIZE);
	img->y_wall_back = (int)(img->new_yp_back / CUBESIZE);
	img->x_wall_left = (int)(img->new_xp_left / CUBESIZE);
	img->y_wall_left = (int)(img->new_yp_left / CUBESIZE);
	img->x_wall_right = (int)(img->new_xp_right / CUBESIZE);
	img->y_wall_right = (int)(img->new_yp_right / CUBESIZE);
}

static void	front_back(int key_code, t_data *img)
{
	if (key_code == 1)
	{
		if (img->map[img->y_wall_back][img->x_wall_back] != '1'
			&& is_far_from_wall(img, key_code))
		{
			img->xp = img->new_xp_back;
			img->yp = img->new_yp_back;
		}
	}
	else if (key_code == 13)
	{
		if (img->map[img->y_wall_front][img->x_wall_front] != '1'
			&& is_far_from_wall(img, key_code))
		{
			img->xp = img->new_xp_front;
			img->yp = img->new_yp_front;
		}
	}
}

static void	left_right(int key_code, t_data *img)
{
	if (key_code == 0)
	{
		if (img->map[img->y_wall_left][img->x_wall_left] != '1'
			&& is_far_from_wall(img, key_code))
		{
			img->xp = img->new_xp_left;
			img->yp = img->new_yp_left;
		}
	}
	else if (key_code == 2)
	{
		if (img->map[img->y_wall_right][img->x_wall_right] != '1'
			&& is_far_from_wall(img, key_code))
		{
			img->xp = img->new_xp_right;
			img->yp = img->new_yp_right;
		}
	}
}

static void	rotate_player(int key_code, t_data *img)
{
	if (key_code == 124)
	{
		img->angle_player += 0.1;
		if (img->angle_player <= 0 || img->angle_player >= M_PI * 2)
			img->angle_player = 0;
	}
	else if (key_code == 123)
	{
		img->angle_player -= 0.1;
		if (img->angle_player <= 0)
			img->angle_player = M_PI * 2;
	}
}

void	ft_key_moves(int key_code, t_data *img)
{
	init_step(img);
	front_back(key_code, img);
	left_right(key_code, img);
	rotate_player(key_code, img);
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, WIN_W, WIN_H);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	ray_casting(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
