#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

size_t          ft_strlen(const char *s);
int             ft_strncmp(const char *s1, const char *s2, size_t n);
char            *ft_strdup(const char *s1);
void            *ft_calloc(size_t count, size_t size);
void            *ft_memset(void *b, int c, size_t len);
void            ft_bzero(void *s, size_t n);
void            *ft_memcpy(void *dst, const void *src, size_t n);
char            *ft_substr(char const *s, unsigned int start, size_t len);
char            *ft_strjoin(char const *s1, char const *s2);
char            **ft_split(char const *s, char c);
int             ft_isdigit(int c);
int             ft_atoi(const char *str);
char            *ft_strchr(const char *s, int c);
void            ft_putstr_fd(char *s, int fd);
void            ft_putendl_fd(char *s, int fd);
char            *get_next_line(int fd);
void            gnl_cleanup(void);

#endif
