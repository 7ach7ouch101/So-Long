/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:37:14 by mmeziani          #+#    #+#             */
/*   Updated: 2022/09/26 22:01:07 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loading(void *mlx, t_assets *ass)
{
	int	img_width;
	int	img_height;

	img_height = 0;
	img_width = 0;
	ass->coin = mlx_xpm_file_to_image(mlx, "./assets/coin.xpm",
			&img_width, &img_height);
	ass->wall = mlx_xpm_file_to_image(mlx, "./assets/wall.xpm",
			&img_width, &img_height);
	ass->door = mlx_xpm_file_to_image(mlx, "./assets/door.xpm",
			&img_width, &img_height);
	ass->player = mlx_xpm_file_to_image(mlx, "./assets/player.xpm",
			&img_width, &img_height);
	ass->floor = mlx_xpm_file_to_image(mlx, "./assets/floor.xpm",
			&img_width, &img_height);
	if (!ass->coin || !ass->door || !ass->floor || !ass->player || !ass->wall)
	{
		write(1, "FILE NOT FOUND", 14);
		exit(0);
	}
}

void	put_img(t_game_info *game, char *ptr, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, ptr, j * 60, i * 60);
}

void	rendreing(t_game_info *game, t_assets *ass)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				put_img(game, ass->wall, i, j);
			else if (game->map[i][j] == 'C')
				put_img(game, ass->coin, i, j);
			else if (game->map[i][j] == 'P')
				put_img(game, ass->player, i, j);
			else if (game->map[i][j] == 'E')
				put_img(game, ass->door, i, j);
			else
				put_img(game, ass->floor, i, j);
			j++;
		}
		i++;
	}
}
