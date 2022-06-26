#include "so_long.h"

char	**parse_map(char *map)
{
	int fd;
	char *tmp;
	char *mp;
	int i;

	i = 0;
	while(map[i] != '.')
		i++;
	if(strcmp(&map[i], ".ber") != 0)
		return (0);
	fd = open(map, O_RDWR);
	tmp = malloc(1 * sizeof(char));
	mp = malloc(1);
	while(read(fd,tmp,1))
	{
		mp = ft_strjoin(mp,tmp);
		free(tmp);
		tmp = malloc(1);
	}
	close(fd);
	free(tmp);
	return (ft_split(mp,'\n'));
}
int valid_rec()
int	valid_map()
{
	valid_rec();
	valid_wall();
	valid_char();
}
int	main(int ac, char **av)
{
	game_info game;
	int i;
	i = 0;
	if(ac == 2)
	{
		if(!(game.map = parse_map(av[1])))
			return (write(1 , "extension error\n",16));
		valid_map(game.map);
	}
	else
		write(1, "arguments error \n", 17);
	return 0;
}