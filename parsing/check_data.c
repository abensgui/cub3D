/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:11:59 by abensgui          #+#    #+#             */
/*   Updated: 2022/11/15 20:12:15 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_data(t_vars *data)
{
	int	i;

	i = 0 ;
	while (i < 3)
	{
		if (data->c[i] == -1)
			return (0);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (data->f[i] == -1)
			return (0);
		i++;
	}
	if (!data->no || !data->so || !data->ea || !data->we || data->no[0] == '\0'
		|| data->so[0] == '\0' || data->we[0] == '\0' || data->ea[0] == '\0')
		return (0);
	return (1);
}
