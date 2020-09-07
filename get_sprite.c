#include "cub3d.h"

int countspr(t_m *map)
{
    int x;
    int y;
    int i;

    x = 0;
    i = 0;
    while (x < map->max_x){
        y = 0;
        while (y < map->max_y)
        {
            if (map->wmap[x][y] == 4)
                i++;
            y++;
        }
        x++;
    }
    return (i);

}

t_spr *get_sprites(t_p *p)
{
    t_spr   *spr;
    int     x;
    int     y;
    int     i;

    x = 0;
    i = 0;
    p->mlx->spr_num = countspr(p->map);
    spr = (malloc(p->mlx->spr_num * sizeof(t_spr)));
    p->mlx->spr_or = (malloc(p->mlx->spr_num * sizeof(int)));
    while (x < p->map->max_x)
    {
        y = 0;
        while (y < p->map->max_y)
        {
            if (p->map->wmap[x][y] == 4){
                spr[i].x = x;
                spr[i++].y = y;
            }
            y++;
        }
        x++;
    }
    return (spr);
}