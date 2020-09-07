#include "cub3d.h"

void more_error (char *str, t_p *p, char *s)
{
	while(ft_isdigit(*str))
		str++;
	while(*str == ' ')
		str++;
	if (*str)
		error(s, p);
}

void	make_res(char *str, t_p *p)
{
	if(p->screen)
		error("Error. Multiple resolutions", p);
	p->screen = 1;
	while (*str == ' ')
		str++;
	p->mlx->screen_w = cubatoiR(&(*str));
	while (ft_isdigit(*str))
		str++;
	if (*str != ' ')
		error("Error. Wrong height", p);
	while (*str == ' ')
		str++;
	p->mlx->screen_h = cubatoiR(str);
	more_error(str, p, "Error. A lot of resolutions");
	if (p->mlx->screen_w <= 0 || p->mlx->screen_h <= 0)
		error("Error. Incorrect resolution", p);
	p->mlx->screen_w = (p->mlx->screen_w > 2560 ? 2560 : p->mlx->screen_w);
	p->mlx->screen_h = (p->mlx->screen_h < 1440 ? 1440 : p->mlx->screen_h);
}

void build_floor(char *str, t_p *p)
{
	if (p->floor)
		error("Multiple colors for floor", p);
	while(*str == ' ')
		str++;
	p->mlx->fr = cubatoiF(str);
	while (ft_isdigit(*str) || *str == ' ')
		str++;
	if(*(str++) != ',')
		error("Error. Wrong floor color", p);
	while (*str == ' ')
		str++;
	p->mlx->fb = cubatoiF(str);
	if (p->mlx->fb == -1 || p->mlx->fr == -1 || p->mlx->fg == -1)
		error("Error. Wrong values", p);
	more_error(str, p, "Error. A lot of resolution");
	p->floor = 1;
}

void build_sky(char *str, t_p *p)
{
	if (p->sky)
		error("Error. Multiple sky color", p);
	while(*str == ' ')
		str++;
	p->mlx->sr = cubatoiF(str);
	while (ft_isdigit(*str) || *str == ' ')
		str++;
	if (*(str++) != ',')
		error("Error. Wrong sky color", p);
	while (*str == ' ')
		str++;
	p->mlx->sg = cubatoiF(str);
	while (ft_isdigit(*str) || *str == ' ')
		str++;
	if (*(str++) != ',')
		error("Error. Wrong sky color", p);
	while (*str == ' ')
		str++;
	p->mlx->sb = cubatoiF(str);
	while (ft_isdigit(*str) || *str == ' ')
		str++;
	if (*str || p->mlx->sb == -1 || p->mlx->sr == -1 || p->mlx->sg == -1)
		error("Error. Wrong sky color", p);
	p->sky = 1;
}

int choose_p(char c, char *str, t_p *p)
{
    while (*str == ' ')
        str++;
    if (c == 'R' && *(str + 1) == ' ')
		make_res(str + 1, p);
	else if (c == 'F' && *(str + 1) == ' ')
		build_floor(str + 1, p);
	else if (c == 'C' && *(str + 1) == ' ')
		build_sky(str + 1, p);
	else if (c == 'N' && *(str + 1) == 'O' && *(str + 2) == ' ')
		make_txt(1, str + 2, p);
	else if (c == 'S' && *(str + 1) == 'O' && *(str + 2) == ' ')
		make_txt(2, str + 2, p);
	else if (c == 'W' && *(str + 1) == 'E' && *(str + 2) == ' ')
		make_txt(4, str + 2, p);
	else if (c == 'E' && *(str + 1) == 'A' && *(str + 2) == ' ')
		make_txt(3, str + 2, p);
	else if (c == 'S' && *(str + 1) == ' ')
		make_txt(5, str + 1, p);
	else if (c == '1' || c == '0' || c == '2')
		return (0);
	else if (c)
		error("Error", p);
	return (1);
}