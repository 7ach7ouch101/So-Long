/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:37:06 by mmeziani          #+#    #+#             */
/*   Updated: 2022/09/23 23:28:32 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_movements(int movements)
{
	write(1, &movements, 1);
	write(1, "\n", 1);
	return ;
}

void	move_player(game_info *game, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P' && game->map[i + x][j + y] != '1'
				&& game->map[i + x][j + y] != 'E')
			{
				if (game->map[i + x][j + y] == 'C')
					game->coins--;
				game->map[i][j] = '0';
				game->map[i + x][j + y] = 'P';
				game->movements = game->movements + 1;
				ft_print_movements(game->movements);
				return ;
			}
			if (game->map[i][j] == 'P' && game->map[i + x][j + y] == 'E'
				&& game->coins == 0)
				exit(0);
		}
	}
}

int	close_window(game_info *game, t_assets *ass)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	freee(game->map);
	free(ass);
	free(game->mlx);
	exit(0);
}

int	test(int key, game_info *game, t_assets *ass)
{
	int	i;

	i = 0;
	if (key == 53)
		close_window (game, ass);
	if (key == 13 || key == 0 || key == 1 || key == 2)
	{
		if (key == 13)
			move_player (game, -1, 0);
		else if (key == 0)
			move_player (game, 0, -1);
		else if (key == 1)
			move_player (game, 1, 0);
		else if (key == 2)
			move_player (game, 0, 1);
	}
	mlx_clear_window(game->mlx, game->mlx_win);
	ass = malloc(sizeof(t_assets));
	loading (game->mlx, ass);
	rendreing (game, ass);
	return (0);
}

int	main(int ac, char **av)
{
	game_info	game;
	t_assets	*ass;

	ass = malloc(sizeof(t_assets));
	game.movements = 0;
	if (ac == 2)
	{
		if ( !(game.map = parse_map(av[1])))
			return (write (1, "Error\n", 7));
		valid_map(&game);
		game.mlx = mlx_init();
		game.mlx_win = mlx_new_window(game.mlx,
				60 * game.width, 60 * game.height, "test");
		loading(game.mlx, ass);
		rendreing(&game, ass);
		free(ass);
		mlx_hook (game.mlx_win, 2, 0, &test, &game);
		mlx_hook (game.mlx_win, 17, 0, close_window, &game);
		mlx_loop (game.mlx);
	}
	else
		write (1, "arguments error \n", 17);
	return (0);
}
