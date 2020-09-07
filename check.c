#include "cub3d.h"

void    check_pl(t_p *p)
{
    int i;
    int j;

    i = 0;
    p->pl->pos = 0;
    while(i <= p->map->max_x)
    {
        j = 0;
        while(j <= p->map->max_y)
        {
            p->pl->pos += check_mvalue(p->map->wmap[i][j], i, j, p);
            j++;
        }
        i++;
    }
    if(p->pl->pos == 0)
        error("Error. No spawn point", p);
}

int     check_mvalue(int value, int x, int y, t_p *p)
{
    if (value != 1 && value != 2 && value != 0 && value != -1)
    {
        pl_init(x, y, (value + 48), p);
        return (1);
    }
    return (0);
}

void    check_m(t_p *p, int x, int y)
{
    int **map;

    p->pl->pos = 0;
    map = p->map->wmap;
    if(map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 4)
        return ;
    if(x == 0 || y == 0 || x == p->map->max_x)
        error("Error. Map not closed", p);
    if(map[x][y] == -1)
        error("Error. Map not closed", p);
    if(map[x][y] == 0)
        map[x][y] = 3;
    if(map[x][y] == 2)
        map[x][y] = 4;
    check_m(p, x + 1, y);
    check_m(p, x, y + 1);
    check_m(p, x - 1, y);
    check_m(p, x, y - 1);
}