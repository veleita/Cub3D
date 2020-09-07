#include "cub3d.h"

void    set_camera_ns(char dir, t_pl *pl)
{
    if (dir == 'N')
    {
        pl->dir_x = -1;
        pl->dir_y = 0;
        pl->plane_x = 0;
        pl->plane_y = 0.66;
    }
    else if (dir == 'S')
    {
        pl->dir_x = 1;
        pl->dir_y = 0;
        pl->plane_x = 0;
        pl->plane_y = -0.66;
    }
}

void    set_camera_ew(char dir, t_pl *pl)
{
    if (dir == 'W')
    {
        pl->dir_x = 0;
        pl->dir_y = -1;
        pl->plane_x = -0.66;
        pl->plane_y = 0;
    }
    else if (dir == 'E')
    {
        pl->dir_x = 0;
        pl->dir_y = 1;
        pl->plane_x = 0.66;
        pl->plane_y = 0;
    }
}

int     pl_init(int x, int y, char dir, t_p *p)
{
    if(dir != 'N' && dir != 'S' && dir != 'E' && dir != 'W')
        error("Error. Invalid map", p);
    if(p->pl->pos > 0)
        error("Error. Multiple spawn points", p);
    p->pl->pos_x = x + 0.5;
    p->pl->pos_y = y + 0.5;
    if (dir == 'N' || dir == 'S')
        set_camera_ns(dir, p->pl);
    else
        set_camera_ew(dir, p->pl);
    p->pl->forward = 0;
    p->pl->backward = 0;
    p->pl->left = 0;
    p->pl->right = 0;
    p->pl->rightrot = 0;
    p->pl->leftrot = 0;
    return (1);   
}