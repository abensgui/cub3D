/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:08:42 by abensgui          #+#    #+#             */
/*   Updated: 2022/11/16 23:01:55 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_catstr(char **s, int *j, int i)
{
	char	*str;

	*j += 2;
	skip_space(s[i], j);
	str = ft_strdup("");
	while (s[i][*j] && s[i][*j] != ' ' && s[i][*j] != '\t')
	{
		if (s[i][*j] == '\\' && s[i][(*j) + 1] == ' ')
			(*j)++;
		str = ft_joinchar(str, s[i][*j]);
		(*j)++;
	}
	while (s[i][*j])
	{
		if (s[i][*j] != ' ' && s[i][*j] != '\t')
			print_error("Error\n");
		(*j)++;
	}
	return (str);
}
