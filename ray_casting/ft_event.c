/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <hbouladh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:13:29 by hbouladh          #+#    #+#             */
/*   Updated: 2022/11/13 20:53:21 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_event(int key_code, t_data *img)
{
	if (key_code == 1 || key_code == 0 || key_code == 2
		|| key_code == 13 || key_code == 123 || key_code == 124)
		ft_key_moves(key_code, img);
	if (key_code == 53)
	{
		write(1, "Exit", 5);
		exit(0);
	}
	return (0);
}
