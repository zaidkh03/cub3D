/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <zalkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 06:02:34 by zalkhali          #+#    #+#             */
/*   Updated: 2025/11/02 06:05:34 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_orientation(t_player *p, char dir)
{
	static const char		symbols[4] = {'N', 'S', 'E', 'W'};
	static const double		dirs[4][2] = {
	{0, -1}, {0, 1}, {1, 0}, {-1, 0}
	};
	static const double		planes[4][2] = {
	{0.66, 0}, {-0.66, 0},
	{0, 0.66}, {0, -0.66}
	};
	int						i;

	i = 0;
	while (i < 4)
	{
		if (symbols[i] == dir)
		{
			p->dir_x = dirs[i][0];
			p->dir_y = dirs[i][1];
			p->plane_x = planes[i][0];
			p->plane_y = planes[i][1];
			return ;
		}
		i++;
	}
}

void	init_player(t_cub *cub)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < cub->map.height)
	{
		x = 0;
		while (x < cub->map.width)
		{
			c = cub->map.grid[y][x];
			if (ft_strchr("NSEW", c))
			{
				cub->player.x = x + 0.5;
				cub->player.y = y + 0.5;
				set_orientation(&cub->player, c);
				cub->map.grid[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}
