/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:57:42 by abensgui          #+#    #+#             */
/*   Updated: 2022/11/16 23:01:55 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_ws(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

static int	space_tabe_check(t_vars *data, char **s, int *i, int j)
{
	if (s[*i][j] == 'N' && s[*i][j + 1] == 'O'
		&& check_ws(s[*i][j + 2]) && !data->no)
		data->no = ft_catstr(s, &j, *i);
	else if (s[*i][j] == 'S' && s[*i][j + 1] == 'O'
		&& check_ws(s[*i][j + 2]) && !data->so)
		data->so = ft_catstr(s, &j, *i);
	else if (s[*i][j] == 'W' && s[*i][j + 1] == 'E'
		&& check_ws(s[*i][j + 2]) && !data->we)
		data->we = ft_catstr(s, &j, *i);
	else if (s[*i][j] == 'E' && s[*i][j + 1] == 'A'
		&& check_ws(s[*i][j + 2]) && !data->ea)
		data->ea = ft_catstr(s, &j, *i);
	else if (s[*i][j] == 'F' && check_ws(s[*i][j + 1]) && data->f[0] == -1)
		ft_color(s[*i], &j, data->f);
	else if (s[*i][j] == 'C' && check_ws(s[*i][j + 1]) && data->c[0] == -1)
		ft_color(s[*i], &j, data->c);
	else if (s[*i][j] != '\0' && s[*i][j] != '\n' && s[*i][j] != '1' )
		print_error("Error\n");
	else
		return (0);
	return (1);
}

void	switch_case(t_vars *data, char **s, int *i)
{
	int	j;

	j = 0;
	while (s[*i])
	{
		j = 0;
		skip_space(s[*i], &j);
		if (!space_tabe_check(data, s, i, j))
		{
			if (check_data(data))
				break ;
		}
		(*i)++;
	}
}

t_vars	*ft_map(char **av)
{
	int		num;
	t_vars	*data;
	char	*str;
	char	**s;
	int		i;

	i = 0;
	data = malloc(sizeof(t_vars));
	num = 0;
	str = open_file(av[1]);
	s = ft_split1(str, '\n');
	free(str);
	ft_ins(data);
	switch_case(data, s, &i);
	while (s[i] && (s[i][0] == '\n' || line_space(s[i])))
		i++;
	data->map = &s[i];
	if (!check_data(data))
		print_error("Error\n");
	check_map(data->map);
	return (data);
}
