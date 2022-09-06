#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stdio.h>
#include <unistd.h> 
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct game
{
    char **map;
    int height;
    int width;

}game_info;

typedef struct s_assets
{
    void *wall;
    void *player;
    void *coin;
    void *door;
}t_assets;


char	**ft_split(const char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
void    loading(void *mlx, t_assets *ass);
void    rendreing(void *mlx, void *mlx_win, game_info *game, t_assets *ass);



#endif