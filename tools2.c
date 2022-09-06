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

static	char	**fillarr(char **p, const char *s, char c)
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
			memcpy(p[e], s, j);
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

char	**ft_split(const char *s, char c)
{
	char	**p;

	if (!s)
		return (NULL);
	p = (char **)malloc(((words(s, c) + 1) * sizeof(char *)));
	if (!p)
		return (NULL);
	p = fillarr(p, s, c);
	return (p);
}