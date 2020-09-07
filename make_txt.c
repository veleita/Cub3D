#include "cub3d.h"

void    check_txt_second(int dir, t_p *p)
{
    if (dir == 4)
    {
        if(p->t4)
            error("Error. E textuture set mora than once", p);
        else
            p->t4 = 1;
    }
    if (dir == 5)
    {
        if(p->spr)
            error("Error. SPR textuture set mora than once", p);
        else
            p->spr = 1;
    }
}

void    check_txt(int dir, t_p *p)
{
    if (dir == 1)
    {
        if(p->t1)
            error("Error. N textuture set mora than once", p);
        else
            p->t1 = 1;
    }
    if (dir == 2)
    {
        if(p->t2)
            error("Error. S textuture set mora than once", p);
        else
            p->t2 = 1;
    }
    if (dir == 3)
    {
        if(p->t3)
            error("Error. W textuture set mora than once", p);
        else
            p->t3 = 1;
    }
    if (dir == 4 || dir == 5)
        check_txt_second(dir, p);
}

void    make_txt(int dir, char *str, t_p *p)
{
    int fd;

    while (*str == ' ')
        str++;
    if ((fd = open(str, O_RDONLY)) < 0)
        error("Error. Fd couldnt be open", p);
    close (fd);
    if (dir == 1)
        p->mlx->txt->txt1_p = str;
    if (dir == 2)
        p->mlx->txt->txt2_p = str;
    if (dir == 3)
        p->mlx->txt->txt3_p = str;
    if (dir == 4)
        p->mlx->txt->txt4_p = str;
    if (dir == 5)
        p->mlx->txt->spr_p = str;
    check_txt(dir, p);
    
}