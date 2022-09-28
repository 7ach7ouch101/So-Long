/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:49:19 by mmeziani          #+#    #+#             */
/*   Updated: 2022/09/26 23:30:29 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h> 
# include <fcntl.h>
# include <stdlib.h>

typedef struct game
{
	char	**map;
	int		height;
	int		width;
	int		movements;
	int		coins;
	void	*mlx;
	void	*mlx_win;
}t_game_info;

typedef struct s_assets
{
	void	*wall;
	void	*player;
	void	*coin;
	void	*door;
	void	*floor;
}t_assets;

char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
void	loading(void *mlx, t_assets *ass);
void	rendreing(t_game_info *game, t_assets *ass);
char	**parse_map(char *map);
void	valid_map(t_game_info *game);
int		valid_rec(t_game_info *game);
int		valid_wall(t_game_info *game);
void	valid_char(t_game_info *game, int C, int E, int P);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memcpy(void	*dst, const void *src, size_t n);
void	*freee(char **p);
int		ft_strlen(char *s);
void	ft_putnbr(int n);

#endif
