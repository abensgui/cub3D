/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:01:07 by abensgui          #+#    #+#             */
/*   Updated: 2022/11/16 23:01:55 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	j_wall(int j, char *s, int p)
{
	while (s[j] && j >= 0)
	{
		if (s[j] == '1')
			return (1);
		else if (s[j] != '0' && !if_player(s[j]))
			break ;
		j += p;
	}
	return (0);
}

int	i_wall(int i, int j, char **s, int p)
{
	int	c;

	c = j;
	while (s[i] && s[i][0] != '\n' && i >= 0)
	{
		if (!s[i] || ft_strlen(s[i]) <= c)
			print_error("Error\n");
		if (s[i][j] == '1')
			return (1);
		else if (s[i][j] != '0' && !if_player(s[i][j]))
			break ;
		i += p;
	}
	return (0);
}

void	check_wall(char **s, int i, int j)
{
	int	check;

	check = 0;
	check += j_wall(j, s[i], 1);
	check += j_wall(j, s[i], -1);
	check += i_wall(i, j, s, 1);
	check += i_wall(i, j, s, -1);
	if (check != 4)
		print_error("Error\n");
}
