#include<unistd.h>
#include<stdio.h>
#include <fcntl.h>
#include<stdlib.h>
#include <string.h>

static	char	*merge(char const *s1, char const *s2, char *p)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		a;
	int		b;

	if (!s1 || !s2)
		return (NULL);
	a = strlen(s1);
	b = strlen(s2);
	p = malloc((a + b) + 1);
	if (!p)
		return (NULL);
	p = merge(s1, s2, p);
	return (p);
}
int main(int ac, char **av)
{
    char *map;
    int fd;
    int size;

    size = 1;
    map = malloc(10000);
    fd = open(av[1],O_RDWR);
    size = read(fd,map,10000);
    printf("%s",map);
}