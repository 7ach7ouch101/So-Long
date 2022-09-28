/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:47:59 by mmeziani          #+#    #+#             */
/*   Updated: 2022/09/28 17:56:40 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_rec(t_game_info *game)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	while (game->map[i][j])
		j++;
	i++;
	while (game->map[i])
	{
		x = 0;
		while (game->map[i][x])
			x++;
		if (x != j)
		{
			write (1, "MAP IS NOT RECTANGULAR\n", 23);
			exit(0);
		}
		i++;
	}
	game->height = i;
	game->width = j;
	return (0);
}

int	valid_line(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '1')
			i++;
		else
		{
			write (1, "THE MAP IS NOT SURROUNDED BY WALLS\n", 35);
			exit(0);
		}
	}
	return (0);
}

int	valid_wall(t_game_info *game)
{
	int	h;
	int	i;

	h = 0;
	i = 0;
	valid_line(game->map[i]);
	while (game->map[h])
		h++;
	while (i < (h - 1))
	{
		if (game->map[i][0] == '1' &&
			game->map[i][ft_strlen(&game->map[i][0]) - 1] == '1')
			i++;
		else
		{
			write(1, "THE MAP IS NOT SURROUNDED BY WALLS\n", 35);
			exit(0);
		}
	}
	valid_line(game->map[i]);
	return (0);
}

void	check(t_game_info *game, int E, int P, int C)
{
	if (P != 1 || C == 0 || E == 0)
	{
		write(1, "Error", 5);
		exit(0);
	}
	game->coins = C;
	game->movements = 0;
}

void	valid_char(t_game_info *game, int C, int E, int P)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1' || game->map[i][j] == '0')
				j = j + 0;
			else if (game->map[i][j] == 'C')
				C++;
			else if (game->map[i][j] == 'E')
				E++;
			else if (game->map[i][j] == 'P')
				P++;
			else
				return (write(1, "MAP CONTAINS DIFFRENT COMPONENT", 31)
					, exit(0));
			j++;
		}
		i++;
	}
	check(game, E, P, C);
}
