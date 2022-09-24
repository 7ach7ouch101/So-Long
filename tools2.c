/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:36:16 by mmeziani          #+#    #+#             */
/*   Updated: 2022/09/24 20:37:02 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	words(const char *str, char c)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c && str[i + 1] == c)
			|| (str[i + 1] == '\0' && str[i] != c))
			u++;
		i++;
	}
	return (u);
}

void	*freee(char **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

static	char	**fillarr(char **p, char *s, char c)
{
	int	j;
	int	e;

	e = 0;
	while (*s)
	{
		j = 0;
		while (s[j] != c && s[j] != '\0')
			j++;
		if (j > 0)
		{
			p[e] = (char *)malloc((j + 1) * sizeof(char));
			if (!p)
				return (freee(p));
			ft_memcpy(p[e], s, j);
			p[e][j] = '\0';
			e++;
			s = s + j;
		}
		else
			s++;
	}
	p[e] = NULL;
	return (p);
}

char	**ft_split(char *s, char c)
{
	char	**p;

	if (!s)
		return (NULL);
	p = (char **)malloc(((words(s, c) + 1) * sizeof(char *)));
	if (!p)
		return (NULL);
	p = fillarr(p, s, c);
	free(s);
	return (p);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!(s1) ||!(s2))
		return (0);
	while ((s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0')))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
