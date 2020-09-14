#include "cub3d.h"

char **get_lines(char **lines, char **tmp, int fd)
{
    char    *c;
    int     i;
    int     j;
    int     r;

    r = 1;
    i = 1;
    while(r){
        r = get_next_line(fd, &c);
        tmp = lines;
        j = 0;
        lines = malloc((i + 1) * sizeof(char *));
        if (tmp){
            while (tmp[j]){
                lines[j] = tmp [j];
                j++; 
            }
        }
        free(tmp);
        lines[j++] = c;
        lines[j] = 0;
        i++;
    }
    return (lines);
}

void init_p(t_p *p)
{
    p->screen = 0;
    p->floor = 0;
    p->mlx->fr = -1;
    p->mlx->fg = -1;
    p->mlx->fb = -1;
    p->mlx->sr = -1;
    p->mlx->sg = -1;
    p->mlx->sb = -1;
    p->t1 = 0;
    p->t2 = 0;
    p->t3 = 0;
    p->t4= 0;
    p->spr = 0;
}

char    **parse_parameters(t_p *p, char **lines)
{
    int i;
    int j;
    int m;

    i = 0;
    m= 0;
    while(lines[i]){
        j = 0;
        while(lines[i][j] == ' ')
            j++;
        if(!choose_p(lines[i][j], lines[i], p))
            return (&lines[i]);
        i++;
    }
    error("Error. Map not found", p);
    return (lines);
}

void    verify_params(t_p *p)
{
    if (!(p->screen))
        error("Error. No resolution", p);
    if (!(p->floor))
        error("Error. No floor color", p);
    if (!(p->sky))
        error("Error. No sky color", p);
    if (!p->t1 || !p->t2 || !p->t3 || !p->t4 || !p->spr)
        error("Error. Missing texture path", p);
}

int     parse(char *name, t_p *p)
{
    int     fd;
    char    **tmp;
    char    **ml; //maplines

    tmp = NULL;
    if((fd = open(name, O_RDONLY)) < 0)
        error("Error, map file not found", p);
    p->lines = 0;
    p->lines = get_lines(p->lines, tmp, fd);
    close(fd);
    init_p(p);
    ml = parse_parameters(p, p->lines);
    verify_params(p);
    parse_m(p, ml);
    p->mlx->sprite = get_sprites(p);
    p->mlx->spr_hit = 0;
    
    return (1);
}