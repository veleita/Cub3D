#include "cub3d.h"

void error(char *str,t_p *p)
{
    write(1, str, ft_strlen(str));
    write(1,"\n",1);
    close_game(p);
}