#include "cub3d.h"

void    rotate_player(t_cub *cub, double angle)
{
    double  old_dir_x;
    double  old_plane_x;

    old_dir_x = cub->player.dir_x;
    old_plane_x = cub->player.plane_x;
    cub->player.dir_x = cub->player.dir_x * cos(angle)
        - cub->player.dir_y * sin(angle);
    cub->player.dir_y = old_dir_x * sin(angle)
        + cub->player.dir_y * cos(angle);
    cub->player.plane_x = cub->player.plane_x * cos(angle)
        - cub->player.plane_y * sin(angle);
    cub->player.plane_y = old_plane_x * sin(angle)
        + cub->player.plane_y * cos(angle);
}
