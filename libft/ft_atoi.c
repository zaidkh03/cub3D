#include "libft.h"

int ft_atoi(const char *str)
{
    long    res;
    int     sign;

    res = 0;
    sign = 1;
    while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (ft_isdigit(*str))
    {
        res = res * 10 + (*str - '0');
        str++;
    }
    return ((int)(res * sign));
}
