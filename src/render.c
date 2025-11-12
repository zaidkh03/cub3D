#include "cub3d.h"

void    render(t_cub *cub)
{
    int     x;
    t_ray   ray;
    int     height;

    x = 0;
    while (x < WIN_W)
    {
        height = perform_raycast(cub, x, &ray);
        draw_column(cub, x, &ray, height);
        x++;
    }
    mlx_put_image_to_window(cub->mlx.ptr, cub->mlx.win,
        cub->mlx.img.img, 0, 0);
}
