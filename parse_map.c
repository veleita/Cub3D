#include "cub3d.h"

int    get_max_x(char **l, t_p *p)
{
    int i;
    int j;
    int empty_line;

    i = 0;
    empty_line = 0;
    while(l[i])
    {
        j = 0;
        while (l[i][j] == ' ')
            j++;
        if(!l[i][j])
            empty_line = 1;
        if(l[i][j] && empty_line)
            error("Error. Additional input after map", p);
        i++;
    }
    return (i);
} 

int		get_max_y(char **l)
{
	int i;
	int j;
	int len;
	int big_len;

	i = 0;
	j = 0;
	big_len = 0;
	while (l[i])
	{
		len = 0;
		j = 0;
		while (l[i][j])
		{
			if (l[i][j] != ' ')
				len++;
			j++;
		}
		if (len > big_len)
			big_len = len;
		i++;
	}
	return (big_len);
}

void    init_m(t_m *map)
{
    int i;
    int j;

    i = 0;
    map->wmap = malloc((map->max_x + 1) * sizeof(int *));
    while (i <= map->max_x)
    {
        map->wmap[i] = malloc((map->max_x + 1) * sizeof(int));
        j = 0;
        while(j <= map->max_y)
        {
            map->wmap[i][j] = -1;
            j++;
        }
        i++;
    }
}

void    make_m(char **l, t_m *map)
{
    int		i;
	int		j;
	int		x;
	int		y;

	x = 0;
	i = 0;
	while (l[i])
	{
		y = 0;
		j = 0;
		while (l[i][j])
		{
			while (l[i][j] == ' ')
				j++;
			if (l[i][j])
				map->wmap[x][y++] = l[i][j++] - '0';
		}
		j = 0;
		i++;
		x++;
	}
}

void    parse_m(t_p *p, char **ml)
{
    p->map->max_x = get_max_x(ml, p);
    p->map->max_y = get_max_y(ml);
    init_m(p->map);
    make_m(ml, p->map);
    check_pl(p);
    check_m(p, p->pl->pos_x, p->pl->pos_y);
}