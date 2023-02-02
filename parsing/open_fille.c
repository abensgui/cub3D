/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fille.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:19:51 by abensgui          #+#    #+#             */
/*   Updated: 2022/11/16 23:01:12 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*open_file(char *av1)
{
	int		fd;
	char	*tmp;
	char	*str;

	fd = open(av1, O_RDONLY);
	if (fd < 0)
		print_error("file not found\n");
	str = ft_strdup("");
	tmp = get_next_line(fd);
	while (tmp)
	{
		str = ft_strjoin(str, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	return (str);
}
