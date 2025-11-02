#include "cub3d.h"

void    free_split(char **arr)
{
    int i;

    if (!arr)
        return ;
    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

static void write_error(const char *msg)
{
    ft_putstr_fd("Error\n", 2);
    ft_putendl_fd((char *)msg, 2);
}

void    fatal_parse(t_parse *parse, const char *msg)
{
    int i;

    write_error(msg);
    i = 0;
    while (i < 4)
    {
        free(parse->tex[i]);
        i++;
    }
    free_split(parse->map_lines);
    exit(1);
}

static void free_map(t_cub *cub)
{
    int i;

    if (!cub->map.grid)
        return ;
    i = 0;
    while (i < cub->map.height)
    {
        free(cub->map.grid[i]);
        i++;
    }
    free(cub->map.grid);
}

static void free_textures(t_cub *cub)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (cub->textures[i].img)
            mlx_destroy_image(cub->mlx.ptr, cub->textures[i].img);
        free(cub->tex_path[i]);
        i++;
    }
}

void    destroy_cub(t_cub *cub)
{
    free_textures(cub);
    if (cub->mlx.img.img)
        mlx_destroy_image(cub->mlx.ptr, cub->mlx.img.img);
    if (cub->mlx.win)
        mlx_destroy_window(cub->mlx.ptr, cub->mlx.win);
    if (cub->mlx.ptr)
    {
#ifdef __linux__
        mlx_destroy_display(cub->mlx.ptr);
#endif
        free(cub->mlx.ptr);
    }
    free_map(cub);
}

void    fatal_cub(t_cub *cub, const char *msg)
{
    write_error(msg);
    destroy_cub(cub);
    exit(1);
}
