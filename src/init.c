#include "cub3d.h"

static void set_orientation(t_player *player, char dir)
{
    if (dir == 'N')
    {
        player->dir_x = 0;
        player->dir_y = -1;
        player->plane_x = 0.66;
        player->plane_y = 0;
    }
    if (dir == 'S')
    {
        player->dir_x = 0;
        player->dir_y = 1;
        player->plane_x = -0.66;
        player->plane_y = 0;
    }
    if (dir == 'E')
    {
        player->dir_x = 1;
        player->dir_y = 0;
        player->plane_x = 0;
        player->plane_y = 0.66;
    }
    if (dir == 'W')
    {
        player->dir_x = -1;
        player->dir_y = 0;
        player->plane_x = 0;
        player->plane_y = -0.66;
    }
}

void    init_player(t_cub *cub)
{
    int y;
    int x;
    char    c;

    y = 0;
    while (y < cub->map.height)
    {
        x = 0;
        while (x < cub->map.width)
        {
            c = cub->map.grid[y][x];
            if (ft_strchr("NSEW", c))
            {
                cub->player.x = x + 0.5;
                cub->player.y = y + 0.5;
                set_orientation(&cub->player, c);
                cub->map.grid[y][x] = '0';
            }
            x++;
        }
        y++;
    }
}
