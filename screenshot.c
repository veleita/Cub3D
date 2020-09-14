#include "cub3d.h"

void    int_char(unsigned char *head, int i)
{
    head[0] = (unsigned char)(i);
    head[1] = (unsigned char)(i >> 8);
    head[2] = (unsigned char)(i >> 16);
    head[3] = (unsigned char)(i >> 24);
    
}
int     bmp_header(int fd, int screen_h, int screen_w, int size)
{
    unsigned char head[54];
    int     sizee;

    sizee = 54 + (screen_w * screen_h * 3) + (size * screen_h);
    ft_bzero(head, 54);
    head[0] = (unsigned char) 'B';
    head[1] = (unsigned char) 'M';
    int_char(head + 2, sizee);
    head[10] = (unsigned char) 54;
    head[14] = (unsigned char) 40;
    int_char(head + 18, screen_w);
    int_char(head + 22, screen_h);
    head[26] = (unsigned char) 1;
    head[28] = (unsigned char) 24;
    return (!(write(fd, head, 54) < 0));
}

int     bmp_dat(int fd, t_mlx *mlx, int size)
{
    unsigned char   zero[3];
    int             x;
    int             y;
    int             pix;

    y = mlx->screen_h - 1;
    ft_bzero(zero, 3);
    while (y >= 0)
    {
        x = 0;
        while (x < mlx->screen_w)
        {
            pix = *(mlx->d_ad + x + y * mlx->sl / 4);
            if (write(fd, &pix, 3) < 0)
                return (0);
            if (size > 0 && write(fd, &zero, size) < 0)
                return (0);
            x++;
        }
        y--;
    }
    return (1);
}

int     take_screenshot(t_p *p)
{
    int size;
    int fd;

    rungame(p);
    size = (4 - ((int)p->mlx->screen_w *3) % 4) % 4;
    if ((fd = open("screenshot.bmp", O_WRONLY |
	O_CREAT, 0777 | O_TRUNC | O_APPEND)) < 0)
        return (0);
    bmp_header(fd, p->mlx->screen_h, p->mlx->screen_w, size);
    bmp_dat(fd, p->mlx, size);
    close(fd);
    return (1);
}

void    make_screenshot(t_p *p, char *str)
{
    if(ft_strncmp("--save", str, 7) != 0)
        error("Unrecognized 2nd argument", p);
    p->screenshot = 1;
    if(!take_screenshot(p))
        error("Error. Couldnt create a .bmp", p);
    write(1,"Screenshoot now it is safe", 27);
    close_game(p);
}