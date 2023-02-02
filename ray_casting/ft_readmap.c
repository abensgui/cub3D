/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:36:11 by hbouladh          #+#    #+#             */
/*   Updated: 2022/11/11 17:36:30 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**ft_readmap(int fd)
{
	char	*buf;
	char	*st;
	char	**map;
	ssize_t	n;
	int		i;

	if (!fd)
		return (NULL);
	st = strdup("");
	n = 1;
	i = 0;
	while (n != 0)
	{
		buf = malloc(n + 1);
		n = read(fd, buf, 1);
		buf[n] = '\0';
		st = ft_strjoin(st, buf);
	}
	map = ft_split(st, '\n');
	if (!map)
		return (NULL);
	return (map);
}
