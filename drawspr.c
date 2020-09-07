#include "cub3d.h"

void    sort_spr(t_mlx *mlx, t_pl *pl)
{
    double  d[mlx->spr_num];
    int     tmp;
    int     dtmp;
    int     i;

    i = -1;
    while(++i < mlx->spr_num)
    {
        d[i] = ((pl->pos_x - mlx->sprite[i].x) * (pl->pos_x - mlx->sprite[i].x) + (pl->pos_y - mlx->sprite[i].y) * (pl->pos_y - mlx->sprite[i].y));
        mlx->spr_or[i] = i;
    }
    i = -1;
    while(++i < mlx->spr_num - 1)
    {
        if(d[i] < d[i + 1])
        {
            dtmp = d[i];
            d[i] = d[i + 1];
            d[i + 1] = dtmp;
            tmp = mlx->spr_or[i];
            mlx->spr_or[i] = mlx->spr_or[i + 1];
            mlx->spr_or[i + 1] = tmp;
            i = -1;
        }
    }
}

void    spr_h(t_sprt *sprt, t_mlx *mlx)
{
    sprt->spr_h = ((int)(mlx->screen_h / (sprt->t_y)));
    if (sprt->spr_h < 0)
        sprt->spr_h *= -1;
    sprt->dr_start = -sprt->spr_h / 2 + mlx->screen_h / 2;
    if (sprt->dr_start < 0)
        sprt->dr_start = 0;
    sprt->dr_end = sprt->spr_h / 2 + mlx->screen_h / 2;
    if(sprt->dr_end >= mlx->screen_h)
        sprt->dr_end = mlx->screen_h;
}

void    spr_w(t_sprt *sprt, t_mlx *mlx)
{
    sprt->spr_w = ((int)(mlx->screen_w / (sprt->t_y)));
    if (sprt->spr_w < 0)
        sprt->spr_w *= -1;
    sprt->dr_start = -sprt->spr_w / 2 + sprt->sprscreen;
    if (sprt->dr_start < 0)
        sprt->dr_start = 0;
    sprt->dr_end = sprt->spr_w / 2 + sprt->sprscreen;
    if (sprt->dr_end >= mlx->screen_w)
        sprt->dr_end = mlx->screen_w;
}

void    draw_sprlines(t_sprt *sprt, t_mlx *mlx, t_r *r)
{
    sprt->x = sprt->dr_start;
    while (sprt->x < sprt->dr_end)
    {
        sprt->txt_x = (int)((sprt->x - (-sprt->spr_w / 2 + sprt->sprscreen)) * mlx->txt->txt5_w / sprt->spr_w);
        sprt->y = sprt->dr_start;
        if (sprt->t_y > 0 && sprt->x >= 0 && sprt->x < mlx->screen_w && sprt->t_y < (float)r->buffer[sprt->x])
            while (sprt->y < sprt->dr_end)
            {
                sprt->d = sprt->y * 256 - mlx->screen_h * 128 + sprt->spr_h * 128;
                sprt->txt_y = ((sprt->d * mlx->txt->txt5_h) / sprt->spr_h) / 256;
                if (*(mlx->txt->txt5_d + sprt->txt_x + sprt->txt_y * mlx->txt->txt5_sl / 4))
                    *(mlx->d_ad + sprt->x + sprt->y * mlx->sl / 4) = *(mlx->txt->txt5_d + sprt->txt_x + sprt->txt_y * mlx->txt->txt5_sl / 4);
                sprt->y++;
            }
        sprt->x++;
    }
}

void    drawspr(t_mlx *mlx, t_pl *pl, t_r *r)
{
    int     i;
    t_spr   spr;
    t_sprt  sprt;

    i = 0;
    sort_spr(mlx, pl);
    while (i < mlx->spr_num)
    {
        spr = mlx->sprite[mlx->spr_or[i++]];
        sprt.spr_x = (spr.x + 0.5) - pl->pos_x;
        sprt.spr_y = (spr.y + 0.5) - pl->pos_y;
        sprt.invdet = 1.0 / (pl->plane_x * pl->dir_y - pl->dir_x * pl->plane_y);
        sprt.t_x = sprt.invdet * (-pl->plane_y * sprt.spr_x + pl->plane_x * sprt.spr_y);
        sprt.t_y = sprt.invdet * (-pl->plane_y * sprt.spr_x + pl->plane_x * sprt.spr_y);
        sprt.sprscreen = (int)((mlx->screen_w / 2) * (1 + sprt.t_x / sprt.t_y));
        spr_h(&sprt, mlx);
        spr_w(&sprt, mlx);
        draw_sprlines(&sprt, mlx, r);
    }
}