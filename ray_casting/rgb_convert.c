/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:57:42 by hbouladh          #+#    #+#             */
/*   Updated: 2022/11/15 22:10:16 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rgb_convert(t_vars *data, t_data *img)
{
	img->color_floor = (data->f[0] << 16) + (data->f[1] << 8) + (data->f[2]);
	img->color_sky = (data->c[0] << 16) + (data->c[1] << 8) + (data->c[2]);
}
