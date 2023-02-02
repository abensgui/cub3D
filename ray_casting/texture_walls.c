/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:51:40 by hbouladh          #+#    #+#             */
/*   Updated: 2022/11/16 21:05:22 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	texture_walls(t_data *img, int j)
{
	int		a;
	int		i;
	int		y;

	i = 1;
	a = 0;
	y = 0;
	while (i < img->h_wall && a < img->h_wall)
	{
		put_texture(img, a, j, y);
		i++;
		j++;
		a++;
	}
	return (j);
}
