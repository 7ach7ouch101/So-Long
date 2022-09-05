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
	tmp = malloc(sizeof(char));
	mp = malloc(sizeof(char));
	if(fd < 0 || !(mp))
		return 0;
	while(read(fd, tmp, 1))
	{
		tmp[1] = '\0';
		mp = ft_strjoin(mp, tmp);
		free(tmp);
		tmp = malloc(sizeof(char));
	}
	tmp[0] = '\0';
	free(tmp);
	close(fd);
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
int valid_char(game_info *game, int C, int E, int P)
{
	int i;
	int j;

	i = 0;
	while(game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if(game->map[i][j] == '1' || game->map[i][j] == '0')
				j = j + 0;
			else if(game->map[i][j] == 'C')
				C++;
			else if(game->map[i][j] == 'E')
				E++;
			else if(game->map[i][j] == 'P')
				P++;
			else
				return (write(1, "map contains diffrent component",31), 0);
			j++;
		}
		i++;
	}
	if(E > 1 || P > 1 || C == 0)
		return (write(1, "Error", 5));
	return 0;
}
void	valid_map(game_info *game)
{
	int C;
	int E;
	int P;

	C = 0;
	E = 0;
	P = 0;
	valid_rec(game);
	valid_wall(game);
	valid_char(game, C, E, P);
}
int	main(int ac, char **av)
{
	game_info game;
	void *mlx;
	void *mlx_win;
	void	*img;
	char	*relative_path = "./test.png";
	int		*img_width = 0;
	int		*img_height = 0;

	if(ac == 2)
	{
		if(!(game.map = parse_map(av[1])))
			return (write(1 , "Error\n",7));
		valid_map(&game);
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 1080, 1050, "test");
		img = mlx_png_file_to_image(mlx, relative_path, &img_width, &img_height);
		mlx_put_image_to_window(mlx, mlx_win, img, img_width, img_height);
		mlx_loop(mlx);
	}
	else
		write(1, "arguments error \n", 17);
	return 0;
}