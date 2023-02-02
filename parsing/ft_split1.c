/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:58:51 by abensgui          #+#    #+#             */
/*   Updated: 2022/11/15 21:58:26 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static	int	ft_lin(const char *s, char c)
{
	int	i;
	int	spl;

	i = 0;
	spl = 0;
	while (s[i])
	{
		if (s[i] == c)
			spl++;
		i++;
	}
	return (spl);
}

static	int	ft_len(char *s, int i, char c)
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

char	*ft_cpstr(char *s, int *ii, char c, int *j)
{
	char	*str;

	str = malloc(sizeof(char) * (ft_len(s, *ii, c) + 1));
	while (s[*ii])
	{
		if (s[*ii] == c)
			break ;
		str[(*j)++] = s[(*ii)++];
	}
	(*ii)++;
	return (str);
}

static	char	**ft_prsplit(int k, char **cpy, char *s, char c)
{
	int	i;
	int	ii;
	int	j;

	i = 0;
	ii = 0;
	while (i < k && s[ii])
	{
		j = 0;
		if (ft_len(s, ii, c) == 0)
		{
			cpy[i] = malloc(sizeof(char) * 2);
			cpy[i][j++] = '\n';
			ii++;
		}
		else
			cpy[i] = ft_cpstr(s, &ii, c, &j);
		cpy[i++][j] = '\0';
	}
	cpy[i] = NULL;
	return (cpy);
}

char	**ft_split1(char *s, char c)
{
	int		k;
	char	**cpy;

	if (s)
	{
		k = ft_lin(s, c) + 1;
		cpy = (char **)malloc(sizeof(char *) * (k + 1));
		if (!cpy)
			return (NULL);
		return (ft_prsplit (k, cpy, s, c));
	}
	return (NULL);
}
