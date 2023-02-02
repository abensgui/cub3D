/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:02:49 by abensgui          #+#    #+#             */
/*   Updated: 2022/11/15 18:27:24 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

static int	ft_alloc(int len, int sa, char *s)
{
	int	ls;
	int	x;

	ls = ft_strlen(s);
	if (len > ls)
		x = ls - sa;
	else
		x = len;
	if (x < 0)
		return (0);
	return (x);
}

char	*ft_strdup(char *sr)
{
	char	*p;
	int		i;
	char	*src;

	i = 0;
	if (sr)
	{
		src = (char *) sr;
		p = malloc((ft_strlen(src) + 1) * sizeof(char));
		if (!p)
			return (0);
		while (src[i])
		{
			p[i] = src[i];
			i++;
		}
		p[i] = '\0';
		return (p);
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	if (s1)
	{	
		while (s1[i])
		{
			s[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2[k])
			s[i++] = s2[k++];
	}
	s[i] = '\0';
	free((char *)s1);
	return (s);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	i;
	size_t	ls;

	if (s)
	{
		ls = ft_strlen(s);
		ss = malloc((ft_alloc(len, start, s) + 1) * sizeof(char));
		if (!ss)
			return (NULL);
		i = 0;
		while (s[i] && i < len && start < ls && i < ls - start)
		{
			ss[i] = s[i + start];
			i++;
		}
		ss[i] = '\0';
		return (ss);
	}
	return (0);
}
