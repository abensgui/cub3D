/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:33:11 by hbouladh          #+#    #+#             */
/*   Updated: 2022/11/16 23:02:11 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

static void	get_address_img(t_data *img, t_vars *data)
{
	img->img_ea = mlx_xpm_file_to_image(img->mlx, data->ea,
			&img->width_ea, &img->height_ea);
	if (!img->img_ea)
		print_error("Error\n");
	img->addr_ea = mlx_get_data_addr(img->img_ea, &img->bits_per_pixel_ea,
			&img->line_length_ea, &img->endian_ea);
	img->img_no = mlx_xpm_file_to_image(img->mlx, data->no,
			&img->width_no, &img->height_no);
	if (!img->img_no)
		print_error("Error\n");
	img->addr_no = mlx_get_data_addr(img->img_no, &img->bits_per_pixel_no,
			&img->line_length_no, &img->endian_no);
	img->img_so = mlx_xpm_file_to_image(img->mlx, data->so,
			&img->width_so, &img->height_so);
	if (!img->img_so)
		print_error("Error\n");
	img->addr_so = mlx_get_data_addr(img->img_so, &img->bits_per_pixel_so,
			&img->line_length_so, &img->endian_so);
	img->img_we = mlx_xpm_file_to_image(img->mlx, data->we,
			&img->width_we, &img->height_we);
	if (!img->img_we)
		print_error("Error\n");
	img->addr_we = mlx_get_data_addr(img->img_we,
			&img->bits_per_pixel_we, &img->line_length_we, &img->endian_we);
}

int	ft_mlx(t_data *img, char **av)
{
	t_vars	*data;

	img = malloc(sizeof(t_data));
	data = ft_map(av);
	img->map = data->map;
	img->mlx = mlx_init();
	img->img = mlx_new_image(img->mlx, WIN_W, WIN_H);
	get_address_img(img, data);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->mlx_win = mlx_new_window(img->mlx, WIN_W, WIN_H, "Cub3d");
	ft_init_map(img);
	rgb_convert(data, img);
	ray_casting(img);
	mlx_hook(img->mlx_win, 02, 0L, ft_event, img);
	mlx_loop(img->mlx);
	return (0);
}
