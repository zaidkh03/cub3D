/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <zalkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 06:17:16 by zalkhali          #+#    #+#             */
/*   Updated: 2025/11/02 06:17:17 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_cub *cub)
{
	int		x;
	t_ray	ray;
	int		height;

	x = 0;
	while (x < WIN_W)
	{
		height = perform_raycast(cub, x, &ray);
		draw_column(cub, x, &ray, height);
		x++;
	}
	mlx_put_image_to_window(cub->mlx.ptr, cub->mlx.win, cub->mlx.img.img, 0, 0);
}
