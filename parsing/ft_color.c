/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:58:30 by abensgui          #+#    #+#             */
/*   Updated: 2022/11/16 23:01:55 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_num(char *s, int *j, int *n, int *k)
{
	int	num;

	num = 0;
	while (ft_isdigit(s[*j]))
	{
		num = num * 10 + (s[*j] - 48);
		(*j)++;
		if (num < 0 || num > 255)
			print_error("Error\n");
	}
	if (*k < 3)
	{
		n[*k] = num;
		num = 0;
		(*k)++;
	}
	else
		print_error("Error\n");
}

void	error_sign(char c)
{
	if (c == '-' || c == '+')
		print_error("Error\n");
}

void	ft_color(char *s, int *j, int *n)
{
	int	k;
	int	c;
	int	num;

	(*j)++;
	k = 0;
	c = 0;
	num = 0;
	while (s[*j])
	{
		skip_space(s, j);
		error_sign(s[*j]);
		if (ft_isdigit(s[*j]))
			get_num(s, j, n, &k);
		if ((s[*j] == ',' && s[(*j) + 1] != ',' && c < 3))
		{
			(*j)++;
			c++;
		}
		if ((s[*j] && s[*j] != ' ' && s[*j] != '\t' && !ft_isdigit(s[*j]))
			|| c > 2 || (s[*j] == ',' && s[(*j) + 1] == ','))
			print_error("Error\n");
	}
	if (c != 2)
		print_error("Error\n");
}
