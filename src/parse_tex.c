/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <zalkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 06:08:55 by zalkhali          #+#    #+#             */
/*   Updated: 2025/11/02 06:10:10 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*trim_path(const char *value)
{
	int	start;
	int	end;

	start = 0;
	while (value[start] == ' ' || value[start] == '\t')
		start++;
	end = ft_strlen(value + start);
	if (end == 0)
		return (NULL);
	while (end > 0 && (value[start + end - 1] == ' ' || value[start + end
				- 1] == '\t'))
		end--;
	return (ft_substr(value + start, 0, end));
}

void	set_texture_path(t_parse *parse, int index, const char *value)
{
	char	*path;

	if (parse->tex[index])
		fatal_parse(parse, "Duplicate texture identifier");
	path = trim_path(value);
	if (!path || path[0] == '\0')
	{
		free(path);
		fatal_parse(parse, "Invalid texture path");
	}
	parse->tex[index] = path;
}
