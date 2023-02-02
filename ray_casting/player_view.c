/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <hbouladh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:51:08 by hbouladh          #+#    #+#             */
/*   Updated: 2022/11/12 18:53:30 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_view(t_data *img)
{
	if (img->wall_dir == 'x' && img->yp > img->y_ray)
	{
		img->w_touch = img->x_ray;
		img->direction = 'S';
	}
	else if (img->wall_dir == 'x')
	{
		img->w_touch = img->x_ray;
		img->direction = 'N';
	}
	if (img->wall_dir == 'y' && img->xp > img->x_ray)
	{
		img->w_touch = img->y_ray;
		img->direction = 'E';
	}
	else if (img->wall_dir == 'y')
	{
		img->w_touch = img->y_ray;
		img->direction = 'W';
	}
}
