/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <zalkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 05:59:44 by zalkhali          #+#    #+#             */
/*   Updated: 2025/11/02 05:59:45 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split(char **arr)
{
	int	i;

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

static void	free_map(t_cub *cub)
{
	int	i;

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

static void	free_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub->textures[i].img && cub->mlx.ptr)
			mlx_destroy_image(cub->mlx.ptr, cub->textures[i].img);
		free(cub->tex_path[i]);
		i++;
	}
}

void	destroy_cub(t_cub *cub)
{
	free_textures(cub);
	if (cub->mlx.img.img && cub->mlx.ptr)
		mlx_destroy_image(cub->mlx.ptr, cub->mlx.img.img);
	if (cub->mlx.win)
		mlx_destroy_window(cub->mlx.ptr, cub->mlx.win);
	if (cub->mlx.ptr)
	{
		mlx_destroy_display(cub->mlx.ptr);
		free(cub->mlx.ptr);
	}
	free_map(cub);
}
