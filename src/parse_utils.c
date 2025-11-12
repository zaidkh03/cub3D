/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chatgpt <chatgpt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:34:56 by chatgpt           #+#    #+#             */
/*   Updated: 2024/05/20 12:34:56 by chatgpt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_line_empty(const char *line)
{
    int i;

    if (!line)
        return (1);
    i = 0;
    while (line[i])
    {
        if (line[i] != ' ' && line[i] != '\t' &&
            line[i] != '\n' && line[i] != '\r')
            return (0);
        i++;
    }
    return (1);
}

void    free0(void **ptr)
{
    if (!ptr || !*ptr)
        return ;
    free(*ptr);
    *ptr = NULL;
}
