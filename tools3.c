#include "so_long.h"

void    loading(void *mlx, t_assets *ass)
{
    int img_width;
    int img_height;

    img_height = 0;
    img_width = 0;
    ass->coin = mlx_xpm_file_to_image(mlx, "./coin.xpm", &img_width, &img_height);
    ass->wall = mlx_xpm_file_to_image(mlx, "./wall.xpm", &img_width, &img_height);
    ass->door = mlx_xpm_file_to_image(mlx, "./door.xpm", &img_width, &img_height);
    ass->player = mlx_xpm_file_to_image(mlx, "./player.xpm", &img_width, &img_height);
}

void rendreing(void *mlx, void *mlx_win, game_info *game, t_assets *ass)
{
    int i;
    int j;

    i = 0;
    while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
            if(game->map[i][j] == '1')
                mlx_put_image_to_window(mlx, mlx_win, ass->wall, j * 60, i * 60);
            else if(game->map[i][j] == 'C')
                mlx_put_image_to_window(mlx, mlx_win, ass->coin, j * 60, i * 60);
            else if(game->map[i][j] == 'P')
                mlx_put_image_to_window(mlx, mlx_win, ass->player, j * 60, i * 60);
            else if(game->map[i][j] == 'E')
                mlx_put_image_to_window(mlx, mlx_win, ass->door, j * 60, i * 60);
            j++;
        }
        i++;
    }
}