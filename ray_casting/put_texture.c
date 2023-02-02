/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:51:24 by hbouladh          #+#    #+#             */
/*   Updated: 2022/11/17 11:14:29 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*south_texture(t_data *img, int a, int y)
{
	int	x;

	x = (int)round(img->w_touch * (img->width_so / CUBESIZE)) % img->width_so;
	if (img->h_texture > WIN_H)
		y = (int)round((a + (img->h_texture - WIN_H) / 2)
				* (img->height_so / img->h_texture)) % img->height_so;
	else
		y = (int)round(a * (img->height_so / img->h_wall)) % img->height_so;
	return (img->addr_so + ((y * img->line_length_so) + (x * 4)));
}

static char	*west_texture(t_data *img, int a, int y)
{
	int	x;

	x = (int)round(img->w_touch * (img->width_we / CUBESIZE)) % img->width_we;
	if (img->h_texture > WIN_H)
		y = (int)round((a + (img->h_texture - WIN_H) / 2)
				* (img->height_we / img->h_texture)) % img->height_we ;
	else
		y = (int)round(a * (img->height_we / img->h_wall)) % img->height_we ;
	return (img->addr_we + ((y * img->line_length_we) + (x * 4)));
}

static char	*north_texture(t_data *img, int a, int y)
{
	int	x;

	x = (int)round(img->w_touch * (img->width_no / CUBESIZE)) % img->width_no;
	if (img->h_texture > WIN_H)
		y = (int)round((a + (img->h_texture - WIN_H) / 2)
				* (img->height_no / img->h_texture)) % img->height_no;
	else
		y = (int)round(a * (img->height_no / img->h_wall)) % img->height_no;
	return (img->addr_no + ((y * img->line_length_no) + (x * 4)));
}

static char	*east_texture(t_data *img, int a, int y)
{
	int	x;

	x = (int)round(img->w_touch * (img->width_ea / CUBESIZE)) % img->width_ea ;
	if (img->h_texture > WIN_H)
		y = (int)round((a + (img->h_texture - WIN_H) / 2)
				* (img->height_ea / img->h_texture)) % img->height_ea;
	else
		y = (int)round(a * (img->height_ea / img->h_wall)) % img->height_ea;
	return (img->addr_ea + ((y * img->line_length_ea) + (x * 4)));
}

void	put_texture(t_data *img, int a, int j, int y)
{
	char	*dst_t;

	if (img->direction == 'S')
		dst_t = south_texture(img, a, y);
	if (img->direction == 'W')
		dst_t = west_texture(img, a, y);
	if (img->direction == 'N')
		dst_t = north_texture(img, a, y);
	if (img->direction == 'E')
		dst_t = east_texture(img, a, y);
	my_mlx_pixel_put(img, img->ray_num, j,
		*(unsigned int *)dst_t);
}
