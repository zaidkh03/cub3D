#include "cub3d.h"

static void put_pixel(t_img *img, int x, int y, int color)
{
    char    *dst;

    if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
        return ;
    dst = img->addr + y * img->line_len + x * (img->bpp / 8);
    *(unsigned int *)dst = color;
}

static int  select_texture(t_ray *ray)
{
    if (ray->side == 0)
    {
        if (ray->dir_x > 0)
            return (TEX_WE);
        return (TEX_EA);
    }
    if (ray->dir_y > 0)
        return (TEX_NO);
    return (TEX_SO);
}

static int  texture_color(t_img *tex, int x, int y)
{
    char    *addr;

    addr = tex->addr + y * tex->line_len + x * (tex->bpp / 8);
    return (*(unsigned int *)addr);
}

static void draw_texture_pixels(t_cub *cub, int x, int start, int end,
        t_img *tex, int tex_x, int height)
{
    double  step;
    double  tex_pos;
    int     y;

    step = (double)tex->height / height;
    tex_pos = (start - WIN_H / 2 + height / 2) * step;
    y = start;
    while (y <= end)
    {
        if (tex_pos < 0)
            tex_pos = 0;
        if (tex_pos >= tex->height)
            tex_pos = tex->height - 1;
        put_pixel(&cub->mlx.img, x, y,
            texture_color(tex, tex_x, (int)tex_pos));
        tex_pos += step;
        y++;
    }
}

static void draw_background(t_cub *cub, int x, int start, int end)
{
    int y;

    y = 0;
    while (y < start)
    {
        put_pixel(&cub->mlx.img, x, y, cub->ceiling_color);
        y++;
    }
    y = end + 1;
    while (y < WIN_H)
    {
        put_pixel(&cub->mlx.img, x, y, cub->floor_color);
        y++;
    }
}

static void compute_bounds(int *start, int *end, int height)
{
    *start = WIN_H / 2 - height / 2;
    *end = WIN_H / 2 + height / 2;
    if (*start < 0)
        *start = 0;
    if (*end >= WIN_H)
        *end = WIN_H - 1;
}

static int  select_tex_x(t_ray *ray, t_img *tex)
{
    int tex_x;

    tex_x = (int)(ray->wall_x * tex->width);
    if (tex_x < 0)
        tex_x = 0;
    if (ray->side == 0 && ray->dir_x > 0)
        tex_x = tex->width - tex_x - 1;
    if (ray->side == 1 && ray->dir_y < 0)
        tex_x = tex->width - tex_x - 1;
    if (tex_x >= tex->width)
        tex_x = tex->width - 1;
    return (tex_x);
}

void    draw_column(t_cub *cub, int x, t_ray *ray, int height)
{
    t_img   *tex;
    int     draw_start;
    int     draw_end;

    if (height < 1)
        height = 1;
    compute_bounds(&draw_start, &draw_end, height);
    draw_background(cub, x, draw_start, draw_end);
    tex = &cub->textures[select_texture(ray)];
    draw_texture_pixels(cub, x, draw_start, draw_end, tex,
        select_tex_x(ray, tex), height);
}
