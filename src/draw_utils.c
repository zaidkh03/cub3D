/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <zalkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 06:00:33 by zalkhali          #+#    #+#             */
/*   Updated: 2025/11/02 06:00:34 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	select_texture(t_ray *ray)
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

int	select_tex_x(t_ray *ray, t_img *tex)
{
	int	tex_x;

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
