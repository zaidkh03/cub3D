/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <zalkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 06:01:49 by zalkhali          #+#    #+#             */
/*   Updated: 2025/11/02 06:25:39 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	show_error(const char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd((char *)msg, 2);
}

void	fatal_parse(t_parse *parse, const char *msg)
{
	int	i;

	show_error(msg);
	i = 0;
	while (i < 4)
	{
		free(parse->tex[i]);
		i++;
	}
	free_split(parse->map_lines);
	exit(1);
}

void	fatal_cub(t_cub *cub, const char *msg)
{
	show_error(msg);
	destroy_cub(cub);
	exit(1);
}
