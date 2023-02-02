/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:55:50 by abensgui          #+#    #+#             */
/*   Updated: 2022/11/16 23:01:55 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_element(char **s, int i)
{
	int	j;
	int	c;

	c = 0;
	j = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] != '0' && s[i][j] != '1' && s[i][j] != 32
				&& s[i][j] != '\n' && !if_player(s[i][j]))
				print_error("Error\n");
			else if (if_player(s[i][j]))
				c++;
			j++;
			if (c > 1)
				print_error("Error\n");
		}
		i++;
	}
	if (c == 0)
		print_error("Error\n");
}
