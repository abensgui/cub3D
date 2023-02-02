/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:36:38 by hbouladh          #+#    #+#             */
/*   Updated: 2022/11/16 21:19:09 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_direction(t_data *img, int *i, int *j)
{
	if (img->map[*i][*j] == 'N')
	{
		img->angle_player = (3 * M_PI) / 2;
		img->direction = 'N';
	}
	else if (img->map[*i][*j] == 'S')
	{
		img->angle_player = M_PI / 2;
		img->direction = 'S';
	}
	else if (img->map[*i][*j] == 'E')
	{
		img->angle_player = 0;
		img->direction = 'E';
	}
	else if (img->map[*i][*j] == 'W')
	{
		img->angle_player = M_PI;
		img->direction = 'W';
	}
}

void	ft_set_player(t_data *img, int i, int j)
{
	if (img->map[i][j] == 'N' || img->map[i][j] == 'S'
			|| img->map[i][j] == 'E' || img->map[i][j] == 'W')
	{
		img->xp = j * CUBESIZE + 10;
		img->yp = i * CUBESIZE + 10;
		set_direction(img, &i, &j);
		img->map[i][j] = '0';
	}
}
