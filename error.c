#include "cub3d.h"

void error(char *str,t_p *p)
{
    ft_printf("%s", &str);
    write(1,"\n",1);
    close_game(p);
    
}