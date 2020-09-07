#include "cub3d.h"

static int  nlen(const char *str)
{
    int i;

    i = 0;
    while (ft_isdigit(*str))
    {
        i++;
        str++;
    }
    return (i);
}

int cubatoiR(const char *str)
{
    int    n;
    
    n = 0;
    while ((*str <= 13 && *str >= 9) || *str == 32)
        str++;
    if (nlen(str) > 4)
        return (42000);
    while (*str)
    {
        if (*str >= '0' && *str <= '9')
            n = n * 10 + (*str++ - '0');
        else
            break;      
    }
    return (n);
}

int cubatoiF(const char *str)
{
    int n;

    n = 0;
    while ((*str <= 13 && *str >= 9) || *str == 32)
        str++;
    if (nlen(str) > 3)
        return (-1);
    while (*str)
    {
        if (*str >= '0' && *str <= '9')
            n = n * 10  + (*str++ - '0');
        else
            break;    
    }
    if (n < 0 || n > 255)
        return (-1);
    return (n);
}
