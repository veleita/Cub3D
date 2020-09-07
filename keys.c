#include "cub3d.h"

int     keypress(int k, t_p *p)
{
    if (k == 1)
        p->pl->backward = 1;
    else if (k == 13)
        p->pl->forward = 1;
    else if (k == 0)
        p->pl->left = 1;
    else if (k == 2)
        p->pl->right = 1;
    else if (k == 123)
        p->pl->leftrot = 1;
    else if (k == 124)
        p->pl->rightrot = 1;
    else if (k == 53)
        close_game(p);
    return (0);
}

int keyrelease(int k, t_p *p)
{
    if (k == 1)
        p->pl->backward = 0;
     else if (k == 13)
        p->pl->forward = 0;
    else if (k == 0)
        p->pl->left = 0;
    else if (k == 2)
        p->pl->right = 0;
    else if (k == 123)
        p->pl->leftrot = 0;
    else if (k == 124)
        p->pl->rightrot = 0;
    return (0);
}