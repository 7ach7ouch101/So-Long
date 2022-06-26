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
int valid_rec(game_info *game)
{
	int i;
	int j;
	int x;

	i = 0;
	j = 0;
	while(game->map[i][j])
		j++;
	i++;
	while(game->map[i])
	{
		x = 0;
		while(game->map[i][x])
			x++;
		if(x != j)
			return (write(1, "map is not rectangular\n",23));
		i++;
	}
	return (0);
}
int	valid_line(char *map)
{
	int i;

	i = 0;
	while(map[i])
	{
		//printf("%c\n",map[i]);
		if(map[i] == '1')
			i++;
		else
			return (write(1, "The map is not surrounded by walls\n", 35));
	}
	return 0;
}
int	valid_wall(game_info *game)
{
	int h;
	int i;

	h = 0;
	i = 0;
	valid_line(game->map[i]);
	while(game->map[h])
		h++;
	while(i < (h - 1))
	{
		if(game->map[i][0] == '1' && game->map[i][strlen(&game->map[i][0]) - 1] == '1')
			i++;
		else
			return (write(1, "The map is not surrounded by walls\n", 35));
	}
	valid_line(game->map[i]);
	return 0;
}
void	valid_map(game_info *game)
{
	valid_rec(game);
	valid_wall(game);
	valid_char(game);
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
		valid_map(&game);
	}
	else
		write(1, "arguments error \n", 17);
	return 0;
}