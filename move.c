#include "cub3d.h"

void    rotation(t_pl *pl)
{
    double	old_dir;
	double	old_p;
	double	speed;

	old_dir = pl->dir_x;
	old_p = pl->p_x;
	speed = 0.02;
	if (pl->rightrot)
	{
		pl->dir_x = (pl->dir_x * cos(-speed) - pl->dir_y * sin(-speed));
		pl->dir_y = (old_dir * sin(-speed) + pl->dir_y * cos(-speed));
		pl->p_x = (pl->p_x * cos(-speed) - pl->p_y * sin(-speed));
		pl->p_y = (old_p * sin(-speed) + pl->p_y * cos(speed));
	}
	if (pl->leftrot)
	{
		pl->dir_x = (pl->dir_x * cos(speed) - pl->dir_y * sin(speed));
		pl->dir_y = (old_dir * sin(speed) + pl->dir_y * cos(speed));
		pl->p_x = (pl->p_x * cos(speed) - pl->p_y * sin(speed));
		pl->p_y = (old_p * sin(speed) + pl->p_y * cos(speed));
	}
}

void    move_left_and_right(t_pl *pl, t_m *map, float speed)
{
    if (pl->left)
	{
		if (can_move(map->wmap[(int)(pl->pos_x)]
			[(int)(pl->pos_y + pl->dir_x * speed)]))
			pl->pos_y += pl->dir_x * speed * 0.5;
		if (can_move(map->wmap[(int)(pl->pos_x - pl->dir_y * speed)]
			[(int)(pl->pos_y)]))
			pl->pos_x -= pl->dir_y * speed * 0.5;
	}
	if (pl->right)
	{
		if (can_move(map->wmap[(int)(pl->pos_x)]
			[(int)(pl->pos_y - pl->dir_x * speed)]))
			pl->pos_y -= pl->dir_x * speed * 0.5;
		if (can_move(map->wmap[(int)(pl->pos_x + pl->dir_y * speed)]
			[(int)(pl->pos_y)]))
			pl->pos_x += pl->dir_y * speed * 0.5;
	}
}

int     can_move(int pos)
{
    if (pos == 1 || pos == 4)
        return (0);
    return (1);
}

void    move_up_and_down(t_pl *pl, t_m *map, float speed)
{
    if (pl->forward)
    {
        if (can_move(map->wmap[(int)(pl->pos_x + pl->dir_x * speed)][(int)(pl->pos_y)]))
            pl->pos_x += pl->dir_x * speed * 0.5;
        if (can_move(map->wmap[(int)(pl->pos_x)][(int)(pl->pos_y + pl->dir_y * speed)]))
			pl->pos_y += pl->dir_y * speed * 0.5;
    }
    if(pl->backward)
    {
        if (can_move(map->wmap[(int)(pl->pos_x - pl->dir_x * speed)][(int)(pl->pos_y)]))
			pl->pos_x -= pl->dir_x * speed * 0.5;
		if (can_move(map->wmap[(int)(pl->pos_x)][(int)(pl->pos_y - pl->dir_y * speed)]))
			pl->pos_y -= pl->dir_y * speed * 0.5;
    }        
}

int     move(t_p *p)
{
    float speed;

    speed = 0.2;
    move_up_and_down(p->pl, p->map, speed);
    move_left_and_right(p->pl, p->map, speed);
    rotation(p->pl);
    return (0);
}