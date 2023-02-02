/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ins.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:37:02 by abensgui          #+#    #+#             */
/*   Updated: 2022/11/16 17:40:15 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_ins(t_vars *data)
{
	int	i;

	i = 0;
	data->no = NULL;
	data->so = NULL;
	data->ea = NULL;
	data->we = NULL;
	while (i < 3)
		data->c[i++] = -1;
	i = 0;
	while (i < 3)
		data->f[i++] = -1;
}
