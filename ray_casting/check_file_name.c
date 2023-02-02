/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:37:52 by hbouladh          #+#    #+#             */
/*   Updated: 2022/11/16 22:33:42 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_file_name(char *str)
{
	size_t	i;
	int		c;
	char	*s;

	s = ".cub";
	i = 0;
	c = ft_strlen(str) - 4;
	if (c < 1)
		return (0);
	while (str[c])
	{
		if (str[c] != s[i])
			return (0);
		i++;
		c++;
	}
	return (1);
}
