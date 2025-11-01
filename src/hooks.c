#include "cub3d.h"

static int  match_key(int keycode, int mac_code, int linux_code)
{
    if (keycode == mac_code)
        return (1);
    if (keycode == linux_code)
        return (1);
    return (0);
}

int handle_key_press(int keycode, t_cub *cub)
{
    if (match_key(keycode, 13, 119))
        cub->keys.w = 1;
    if (match_key(keycode, 1, 115))
        cub->keys.s = 1;
    if (match_key(keycode, 0, 97))
        cub->keys.a = 1;
    if (match_key(keycode, 2, 100))
        cub->keys.d = 1;
    if (match_key(keycode, 123, 65361))
        cub->keys.left = 1;
    if (match_key(keycode, 124, 65363))
        cub->keys.right = 1;
    if (match_key(keycode, 53, 65307))
        handle_close(cub);
    return (0);
}

int handle_key_release(int keycode, t_cub *cub)
{
    if (match_key(keycode, 13, 119))
        cub->keys.w = 0;
    if (match_key(keycode, 1, 115))
        cub->keys.s = 0;
    if (match_key(keycode, 0, 97))
        cub->keys.a = 0;
    if (match_key(keycode, 2, 100))
        cub->keys.d = 0;
    if (match_key(keycode, 123, 65361))
        cub->keys.left = 0;
    if (match_key(keycode, 124, 65363))
        cub->keys.right = 0;
    return (0);
}

int handle_close(t_cub *cub)
{
    destroy_cub(cub);
    exit(0);
    return (0);
}
