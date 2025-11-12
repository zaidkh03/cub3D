/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chatgpt <chatgpt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:34:56 by chatgpt           #+#    #+#             */
/*   Updated: 2024/05/20 12:34:56 by chatgpt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif
#ifndef FD_MAX
# define FD_MAX 1024
#endif

int             gnl_has_newline(char *s);
char            *gnl_join(char *s1, char *s2);
char            *gnl_extract(char *stash);
char            *gnl_trim(char *stash);

static char **stash_table(void)
{
    static char *stash[FD_MAX];

    return (stash);
}

static int  read_to_stash(int fd)
{
    char        buffer[BUFFER_SIZE + 1];
    int         bytes;
    char        *tmp;
    char        **stash;

    stash = stash_table();
    while (!gnl_has_newline(stash[fd]))
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes < 0)
        {
            gnl_cleanup(fd);
            return (-1);
        }
        if (bytes == 0)
            return (0);
        buffer[bytes] = '\0';
        tmp = gnl_join(stash[fd], buffer);
        if (!tmp)
        {
            stash[fd] = NULL;
            gnl_cleanup(fd);
            return (-1);
        }
        stash[fd] = tmp;
    }
    return (1);
}

static char *finish_line(int fd)
{
    char    **stash;
    char    *line;

    stash = stash_table();
    line = gnl_extract(stash[fd]);
    if (!line)
    {
        gnl_cleanup(fd);
        return (NULL);
    }
    stash[fd] = gnl_trim(stash[fd]);
    return (line);
}

char    *get_next_line(int fd)
{
    int     status;
    char    **stash;
    char    *line;

    if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
        return (NULL);
    stash = stash_table();
    status = read_to_stash(fd);
    if (status == -1)
        return (NULL);
    if (status == 0 && (!stash[fd] || !stash[fd][0]))
    {
        gnl_cleanup(fd);
        return (NULL);
    }
    line = finish_line(fd);
    if (!line)
        return (NULL);
    return (line);
}

void    gnl_cleanup(int fd)
{
    char    **stash;
    int     i;

    stash = stash_table();
    if (fd >= 0 && fd < FD_MAX)
    {
        if (stash[fd])
        {
            free(stash[fd]);
            stash[fd] = NULL;
        }
        return ;
    }
    i = 0;
    while (i < FD_MAX)
    {
        if (stash[i])
        {
            free(stash[i]);
            stash[i] = NULL;
        }
        i++;
    }
}
