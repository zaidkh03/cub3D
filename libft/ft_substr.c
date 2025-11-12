#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  i;
    size_t  slen;
    char    *str;

    if (!s)
        return (NULL);
    slen = ft_strlen(s);
    if (start >= slen)
        return (ft_strdup(""));
    if (len > slen - start)
        len = slen - start;
    str = (char *)malloc(len + 1);
    if (!str)
        return (NULL);
    i = 0;
    while (i < len)
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
