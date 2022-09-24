/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:32:20 by mmeziani          #+#    #+#             */
/*   Updated: 2022/09/24 20:35:19 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '.')
		i++;
	if (ft_strcmp(&map[i], ".ber") != 0)
		return (0);
	return (1);
}

char	**parse_map(char *map)
{
	int		fd;
	char	*tmp;
	char	*mp;

	if (!check_extension(map))
		return (0);
	fd = open(map, O_RDWR);
	tmp = malloc(sizeof(char));
	mp = malloc(sizeof(char));
	tmp[1] = '\0';
	if (fd < 0 || !(mp) || !(tmp))
		return (0);
	while (read(fd, tmp, 1))
	{
		mp = ft_strjoin(mp, tmp);
		free(tmp);
		tmp = malloc(sizeof(char));
	}
	free(tmp);
	close(fd);
	return (ft_split(mp, '\n'));
}

void	valid_map(game_info *game)
{
	int	c;
	int	e;
	int	p;

	c = 0;
	e = 0;
	p = 0;
	valid_rec(game);
	valid_wall(game);
	valid_char(game, c, e, p);
}
