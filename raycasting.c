#include "cub3d.h"

void    get_step(t_m *map, t_r *r, t_pl *pl)
{
    if(r->dir_x < 0)
    {
        map->step_x = -1;
        r->side_x = (pl->pos_x - map->x) * r->delta_x;
    }
    else
    {
        map->step_x = 1;
        r->side_x = (map->x + 1.0 - pl->pos_x) * r->delta_x;
    }
    if (r->dir_y < 0)
    {
        map->step_y = -1;
        r->side_y = (pl->pos_y - map->y) * r->delta_y;
    }
    else
    {
        map->step_y = 1;
        r->side_y = (map->y + 1.0 - pl->pos_y) * r->delta_y;
    }
}

void    wallhit(t_m *map, t_r *r)
{
    int h;

    h = 0;
    while(!h)
    {
        if(r->side_x < r->side_y)
        {
            r->side_x += r->delta_x;
            map->x += map->step_x;
            r->wall_side = 0;
        }
        else
        {
            r->side_y += r->delta_y;
            map->y += map->step_y;
            r->wall_side = 1;
        }
        if(map->wmap[map->x][map->y] == 1)
            h = 1;
    }
}

void    walldist_dir(t_mlx *mlx, t_m *map, t_pl *pl, t_r *r)
{
    if (r->wall_side == 1)
    {
        if(map->y < pl->pos_y)
            r->wall_dir = 'W';
        else
            r->wall_dir = 'E';
    }
    else
    {
        if (map->x < pl->pos_x)
            r->wall_dir = 'N';
        else
            r->wall_dir = 'S';
        r->wall_dist = (map->x - pl->pos_x + (1 - map->step_x) / 2) / r->dir_x; 
        r->wall_x = pl->pos_y + r->wall_dist * r->dir_y;
    }
    r->buffer[mlx->x] = r->wall_dist;
}

void    fov_and_pos(t_mlx *mlx, t_m *map, t_r *r, t_pl *pl)
{
    pl->camera = 2 * mlx->x /(double)mlx->screen_w - 1;
    r->dir_x = pl->dir_x + pl->plane_x * pl->camera;
    r->dir_y = pl->dir_y + pl->plane_y * pl->camera;
    map->x = (int)(pl->pos_x);
    map->y= (int)(pl->pos_y);
    r->delta_x = fabs(1/r->dir_x);
    r->delta_y = fabs(1 / r->dir_y);

}

void    raycasting(t_pl *pl, t_mlx *mlx, t_m *map, t_r *r)
{
    mlx->x = 0;
    while(mlx->x < mlx->screen_w)
    {
        fov_and_pos(mlx, map, r, pl);
		get_step(map, r, pl);
		wallhit(map, r);
		walldist_dir(mlx, map, pl, r);
		define_line(mlx, r);
		choose_text(mlx, r);
		r->wall_x -= floor(r->wall_x);
		mlx->text_x = r->wall_x * (mlx->text_sl / 4);
		if (r->wall_side == 0 && r->dir_x > 0)
			mlx->text_x = (mlx->text_sl / 4) - mlx->text_x - 1;
		else if (r->wall_side == 1 && r->dir_y < 0)
			mlx->text_x = (mlx->text_sl / 4) - mlx->text_x - 1;
		drawline(mlx, mlx->x, mlx->text_x);
		mlx->x++;
    }
}