/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:37:15 by hbouladh          #+#    #+#             */
/*   Updated: 2022/11/11 17:37:46 by hbouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	spl(char *s, char c)
{
	int	i;
	int	spl;

	i = 0;
	spl = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			spl++;
			while (s[i] && s[i] != c)
				i++;
			i--;
		}
		i++;
	}
	return (spl);
}

static int	len(char *s, int i, char c)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static char	**ft_free(char **cpy, int i)
{
	i--;
	while (cpy[i])
	{
		free(cpy[i]);
		i--;
	}
	free(cpy);
	return (NULL);
}

static char	**engine(int k, char **cpy, char *s, char c)
{
	int	i;
	int	ii;
	int	l;
	int	j;

	i = 0;
	ii = 0;
	while (i < k && s[ii])
	{
		while (s[ii] == c)
			ii++;
		l = len(s, ii, c);
		cpy[i] = (char *)malloc(sizeof(char) * (l + 1));
		if (!cpy)
			return (ft_free(cpy, i));
		j = 0;
		while (s[ii] != c && s[ii])
			cpy[i][j++] = s[ii++];
		cpy[i][j] = '\0';
		i++;
	}
	free((char *)s);
	cpy[i] = NULL;
	return (cpy);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	char	**cpy;

	i = 0;
	if (s)
	{
		k = spl((char *)s, c);
		cpy = (char **)malloc(sizeof(char *) * (k + 1));
		if (!cpy)
			return (NULL);
		return (engine(k, cpy, (char *)s, c));
		return (cpy);
	}
	return (0);
}
