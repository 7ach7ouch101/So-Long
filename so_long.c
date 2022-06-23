#include <mlx.h>
#include <stdio.h>
#include <unistd.h> 
#include <string.h>
#include<fcntl.h>
#include <stdlib.h>
char	*get_next_line(int fd)
{
	char	str[8000000];
	int		i;
	char	buff[1];
	int		byte;

	byte = read(fd, buff, 1);
	i = 0;
	while (byte > 0)
	{
		str[i++] = buff[0];
		if (buff[0] == '\n')
			break ;
		byte = read(fd, buff, 1);
	}
	str[i] = '\0';
	if (str[0] == '\0')
		return (0);
	return (strdup(str));
}

int	parse_map(char *map)
{
	int fd;
	char *test;
	int i;
	int j;

	j = 0;
	i = 0;
	while(map[i] != '.')
		i++;
	if(strcmp(&map[i], ".ber") != 0)
		return (0);
	fd = open(map, O_RDWR);
	test = get_next_line(fd);
	while(test)
	{
		free(test);
		test = get_next_line(fd);
	}
	return (1);
}

int	main(int ac, char **av)
{
	if(ac == 2)
	{
		if(!parse_map(av[1]))
		{
			write(1, "Error\n", 6);
			return 0;
		}
	}
	else
		write(1, "arguments error \n", 17);
	return 0;
}