/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_far_from_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <hbouladh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:35:26 by hbouladh          #+#    #+#             */
/*   Updated: 2022/11/13 13:51:59 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_far_from_wall(t_data *img, int key_code)
{
	double	x;
	double	y;

	x = img->xp;
	y = img->yp;
	if (!check_far_from_wall(img, key_code, x, y))
		return (0);
	return (1);
}
