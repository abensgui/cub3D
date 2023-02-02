/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:56:51 by abensgui          #+#    #+#             */
/*   Updated: 2022/11/16 23:01:55 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	if_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	if_wall(char **s, int *i, int j)
{
	while (s[*i][j])
	{
		if (s[*i][j] == '0')
		{
			if (j == 0 || *i == 0)
				print_error("Error\n");
			check_wall(s, *i, j);
		}
		else if (if_player(s[*i][j]))
		{
			if (j == 0 || *i == 0)
				print_error("Error\n");
			check_wall(s, *i, j);
		}
		j++;
	}
}

void	check_map(char **s)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	check_element(s, i);
	while (s[i])
	{
		j = 0;
		if (s[i][j] == '\n')
			print_error("Error\n");
		else
		{
			if_wall(s, &i, j);
			i++;
		}
	}
}
