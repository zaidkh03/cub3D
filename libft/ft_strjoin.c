#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t  len1;
    size_t  len2;
    char    *res;
    size_t  i;

    if (!s1 || !s2)
        return (NULL);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    res = (char *)malloc(len1 + len2 + 1);
    if (!res)
        return (NULL);
    i = 0;
    while (i < len1)
    {
        res[i] = s1[i];
        i++;
    }
    i = 0;
    while (i < len2)
    {
        res[len1 + i] = s2[i];
        i++;
    }
    res[len1 + len2] = '\0';
    return (res);
}
