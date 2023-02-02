/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_far_from_wall_util.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:53:51 by hbouladh          #+#    #+#             */
/*   Updated: 2022/11/13 13:53:54 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	back_wall(t_data *img, double x, double y, int i)
{
	int	far_y;
	int	far_x;

	far_y = (int)(img->yp / CUBESIZE);
	far_x = (int)(img->xp / CUBESIZE);
	x -= cos(img->angle_player);
	y -= sin(img->angle_player);
	while (i < 20)
	{
		if (img->map[(int)(y / CUBESIZE)][(int)(x / CUBESIZE)] == '1'
				|| img->map[far_y][(int)(x / CUBESIZE)] == '1'
				|| img->map[(int)(y / CUBESIZE)][far_x] == '1')
			return (0);
		x -= cos(img->angle_player);
		y -= sin(img->angle_player);
		i++;
	}
	return (1);
}

static int	front_wall(t_data *img, double x, double y, int i)
{
	int	far_y;
	int	far_x;

	far_y = (int)(img->yp / CUBESIZE);
	far_x = (int)(img->xp / CUBESIZE);
	x += cos(img->angle_player);
	y += sin(img->angle_player);
	while (i < 20)
	{
		if (img->map[(int)(y / CUBESIZE)][(int)(x / CUBESIZE)] == '1'
				|| img->map[far_y][(int)(x / CUBESIZE)] == '1'
				|| img->map[(int)(y / CUBESIZE)][far_x] == '1')
			return (0);
		x += cos(img->angle_player);
		y += sin(img->angle_player);
		i++;
	}
	return (1);
}

static int	left_wall(t_data *img, double x, double y, int i)
{
	int	far_y;
	int	far_x;

	far_y = (int)(img->yp / CUBESIZE);
	far_x = (int)(img->xp / CUBESIZE);
	x += sin(img->angle_player);
	y -= cos(img->angle_player);
	while (i < 20)
	{
		if (img->map[(int)(y / CUBESIZE)][(int)(x / CUBESIZE)] == '1'
				|| img->map[far_y][(int)(x / CUBESIZE)] == '1'
				|| img->map[(int)(y / CUBESIZE)][far_x] == '1')
			return (0);
		x += sin(img->angle_player);
		y -= cos(img->angle_player);
		i++;
	}
	return (1);
}

static int	right_wall(t_data *img, double x, double y, int i)
{
	int	far_y;
	int	far_x;

	far_y = (int)(img->yp / CUBESIZE);
	far_x = (int)(img->xp / CUBESIZE);
	x -= sin(img->angle_player);
	y += cos(img->angle_player);
	while (i < 20)
	{
		if (img->map[(int)(y / CUBESIZE)][(int)(x / CUBESIZE)] == '1'
				|| img->map[far_y][(int)(x / CUBESIZE)] == '1'
				|| img->map[(int)(y / CUBESIZE)][far_x] == '1')
			return (0);
		x -= sin(img->angle_player);
		y += cos(img->angle_player);
		i++;
	}
	return (1);
}

int	check_far_from_wall(t_data *img, int key_code, int x, int y)
{
	int		i;

	i = 0;
	if (key_code == 1)
	{
		if (!back_wall(img, x, y, i))
			return (0);
	}
	else if (key_code == 13)
	{
		if (!front_wall(img, x, y, i))
			return (0);
	}
	else if (key_code == 0)
	{
		if (!left_wall(img, x, y, i))
			return (0);
	}
	else if (key_code == 2)
	{
		if (!right_wall(img, x, y, i))
			return (0);
	}
	return (1);
}
