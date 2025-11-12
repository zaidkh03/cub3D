#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

int             gnl_has_newline(char *s);
char            *gnl_join(char *s1, char *s2);
char            *gnl_extract(char *stash);
char            *gnl_trim(char *stash);

static char     *g_stash;

static int      read_to_stash(int fd)
{
    char    buffer[BUFFER_SIZE + 1];
    int     bytes;
    char    *tmp;

    while (!gnl_has_newline(g_stash))
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes <= 0)
            return (bytes >= 0);
        buffer[bytes] = '\0';
        tmp = gnl_join(g_stash, buffer);
        if (!tmp)
            return (0);
        g_stash = tmp;
    }
    return (1);
}

static char     *finish_line(void)
{
    char    *line;

    line = gnl_extract(g_stash);
    if (!line)
    {
        free(g_stash);
        g_stash = NULL;
        return (NULL);
    }
    g_stash = gnl_trim(g_stash);
    return (line);
}

char    *get_next_line(int fd)
{
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!read_to_stash(fd))
    {
        free(g_stash);
        g_stash = NULL;
        return (NULL);
    }
    return (finish_line());
}

void    gnl_cleanup(void)
{
    if (!g_stash)
        return ;
    free(g_stash);
    g_stash = NULL;
}
