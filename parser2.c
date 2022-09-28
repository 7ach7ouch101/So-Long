/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:32:20 by mmeziani          #+#    #+#             */
/*   Updated: 2022/09/28 20:49:21 by mmeziani         ###   ########.fr       */
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

	fd = open(map, O_RDONLY);
	tmp = malloc(sizeof(char) + 1);
	mp = malloc(sizeof(char) + 1);
	if (fd < 0 || !(mp) || !(tmp) || !check_extension(map))
		return (0);
	tmp[1] = '\0';
	while (read(fd, tmp, 1))
	{
		mp = ft_strjoin(mp, tmp);
		if ((!(mp[ft_strlen(mp)]) && mp[ft_strlen(mp) - 1] == '\n'
				&& mp[ft_strlen(mp) - 2] == '\n') || mp[0] != '1')
			return (0);
		free(tmp);
		tmp = malloc(sizeof(char));
	}
	if (mp[ft_strlen(mp) - 1] != '1' || !(tmp))
		return (0);
	free(tmp);
	close(fd);
	return (ft_split(mp, '\n'));
}

void	valid_map(t_game_info *game)
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
