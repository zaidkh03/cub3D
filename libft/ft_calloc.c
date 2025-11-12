#include "libft.h"

void    *ft_calloc(size_t count, size_t size)
{
    size_t  total;
    void    *ptr;

    if (size != 0 && count > ((size_t)-1) / size)
        return (NULL);
    total = count * size;
    ptr = malloc(total);
    if (!ptr)
        return (NULL);
    ft_memset(ptr, 0, total);
    return (ptr);
}
