/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <zalkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 06:06:12 by zalkhali          #+#    #+#             */
/*   Updated: 2025/11/02 06:06:13 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop_hook(t_cub *cub)
{
	move_player(cub);
	if (cub->keys.left)
		rotate_player(cub, -ROT_SPEED);
	if (cub->keys.right)
		rotate_player(cub, ROT_SPEED);
	render(cub);
	return (0);
}

void	start_loop(t_cub *cub)
{
	mlx_hook(cub->mlx.win, 17, 0, handle_close, cub);
	mlx_hook(cub->mlx.win, 2, 1L << 0, handle_key_press, cub);
	mlx_hook(cub->mlx.win, 3, 1L << 1, handle_key_release, cub);
	mlx_loop_hook(cub->mlx.ptr, loop_hook, cub);
	render(cub);
	mlx_loop(cub->mlx.ptr);
}
