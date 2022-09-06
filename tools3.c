#include "so_long.h"

void    loading(void *mlx)
{
    int img_width;
    int img_height;

    img_height = 0;
    img_width = 0;
    assets->coin = mlx_xpm_file_to_image(mlx, "./coin.xpm", &img_width, &img_height);
    assets->wall = mlx_xpm_file_to_image(mlx, "./wall.xpm", &img_width, &img_height);
    assets->door = mlx_xpm_file_to_image(mlx, "./door.xpm", &img_width, &img_height);
    assets->player = mlx_xpm_file_to_image(mlx, "./player.xpm", &img_width, &img_height);
}

void rendreing(void *mlx, void *mlx_win, game_info *game)
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
                mlx_put_image_to_window(mlx, mlx_win, assets->wall, j * 56, i * 56);
            else if(game->map[i][j] == 'C')
                mlx_put_image_to_window(mlx, mlx_win, assets->coin, j * 56, i * 56);
            else if(game->map[i][j] == 'P')
                mlx_put_image_to_window(mlx, mlx_win, assets->player, j * 56, i * 56);
            else if(game->map[i][j] == 'E')
                mlx_put_image_to_window(mlx, mlx_win, assets->door, j * 56, i * 56);
            j++;
        }
        i++;
    }
}