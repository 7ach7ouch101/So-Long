#include <mlx.h>
#include <stdio.h>
#include <unistd.h> 
#include <string.h>

int	parse_map(char *map)
{
	int i;
	int fd;
	i = 0;
	while(map[i] != '.')
		i++;
	if(strcmp(&map[i], ".ber") != 0)
		return (0);
	fd = open(, O_RDWR)
	return 1;
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
		printf("done");
	}
	else
		write(1, "arguments error \n", 17);
	return 0;
}