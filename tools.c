#include "so_long.h"

char	*merge(char *s1, char *s2, char *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_strlen2(char *s)
{
	int	i;

	if (!s)
		exit(1);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		a;
	int		b;

	if (!s1 || !s2)
		exit(1);
	a = ft_strlen2(s1);
	b = ft_strlen2(s2);
	p = malloc((a + b) + 1);
	if (!p)
		return (NULL);
	p = merge(s1, s2, p);
	//free (s1);
	return (p);
}