/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:02:41 by abensgui          #+#    #+#             */
/*   Updated: 2022/11/15 18:27:33 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{	
			if (s[i] == c)
			{
				return (i);
			}
			i++;
		}
	}
	return (-1);
}

static char	*ft_free(char **t)
{
	free (*t);
	*t = NULL;
	return (NULL);
}

static char	*get_next(char **t)
{
	int			i;
	char		*s;
	char		*tmp;
	static int	j;

	i = 0;
	i = ft_strchr(*t, '\n');
	if (j == -1 || !(**t))
		return (ft_free(t));
	else if (i == -1)
	{
		j = -1;
		s = ft_strdup(*t);
		free (*t);
		*t = NULL;
		return (s);
	}
	s = ft_substr(*t, 0, i + 1);
	tmp = *t;
	*t = ft_strdup(*t + i + 1);
	free (tmp);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*t;
	char		*buffer;	
	ssize_t		r;

	r = 1;
	if (fd < 0)
		return (NULL);
	buffer = malloc(2 * sizeof(char));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) == -1)
		return (ft_free(&buffer));
	if (!t)
		t = ft_strdup("");
	while (r && ft_strchr(t, '\n') == -1)
	{
		r = read(fd, buffer, 1);
		buffer[r] = '\0';
		t = ft_strjoin(t, buffer);
	}
	free (buffer);
	return (get_next(&t));
}
