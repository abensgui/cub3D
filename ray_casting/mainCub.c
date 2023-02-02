/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainCub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:38:17 by hbouladh          #+#    #+#             */
/*   Updated: 2022/11/16 20:05:42 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	int		fd;
	t_data	*img;

	img = NULL;
	fd = 0;
	if (ac == 2 && check_file_name(av[1]))
		ft_mlx(img, av);
	else
	{
		write(1, "Insert Map", 11);
		exit(0);
	}
}
