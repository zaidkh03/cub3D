#include "cub3d.h"

static void write_error(const char *msg)
{
    ft_putstr_fd("Error\n", 2);
    ft_putendl_fd((char *)msg, 2);
}

void    fatal_parse(t_parse *parse, const char *msg)
{
    int i;

    write_error(msg);
    free0((void **)&parse->current_line);
    i = 0;
    while (i < 4)
    {
        free(parse->tex[i]);
        i++;
    }
    free_split(parse->map_lines);
    gnl_cleanup();
    exit(1);
}

void    fatal_cub(t_cub *cub, const char *msg)
{
    write_error(msg);
    gnl_cleanup();
    destroy_cub(cub);
    exit(1);
}
