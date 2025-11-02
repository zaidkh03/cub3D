/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <zalkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 05:56:19 by zalkhali          #+#    #+#             */
/*   Updated: 2025/11/02 05:56:20 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

int			gnl_has_newline(char *s);
char		*gnl_join(char *s1, char *s2);
char		*gnl_extract(char *stash);
char		*gnl_trim(char *stash);

static int	read_to_stash(int fd, char **stash)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes;
	char	*tmp;

	while (!gnl_has_newline(*stash))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (bytes >= 0);
		buffer[bytes] = '\0';
		tmp = gnl_join(*stash, buffer);
		if (!tmp)
			return (0);
		*stash = tmp;
	}
	return (1);
}

static char	*finish_line(char **stash)
{
	char	*line;

	line = gnl_extract(*stash);
	if (!line)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	*stash = gnl_trim(*stash);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_to_stash(fd, &stash))
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	return (finish_line(&stash));
}
