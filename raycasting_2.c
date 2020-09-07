#include "cub3d.h"

int     rgb_int(int red, int green, int blue)
{
    int rgb;
    rgb = red;
    rgb = (rgb << 8) + green;
    rgb = (rgb << 8) + blue;
    return (rgb);
}

int     drawline(t_mlx *mlx, int x, int text_x)
{
    int     i;
    int     *txt;
    double  step;
    double  pos;

    i = -1;
    step = 1.0 * mlx->txt_h / mlx->l_h;
    pos = (mlx->l_start - mlx->screen_h / 2 + mlx->l_h / 2) * step;
	txt = mlx->txt_d;
	while (++i < mlx->l_start)
	{
		*(mlx->d_ad + x + i * mlx->sl / 4) = rgb_int(mlx->sr, mlx->sg, mlx->sb);
	}
	while (i <= mlx->l_end)
	{
		*(mlx->d_ad + x + i++ * mlx->sl / 4) = *(txt + text_x +
		(int)pos * mlx->text_sl / 4);
		pos += step;
	}
	while (i < mlx->screen_h)
		*(mlx->d_ad + x + i++ * mlx->sl / 4) =
		rgb_int(mlx->fr, mlx->fg, mlx->fb);
	return (1);
}

void    choose_text(t_mlx *mlx, t_r *r)
{
    if (r->wall_dir == 'N')
    {
        mlx->txt_d = mlx->txt->txt1_d;
        mlx->text_sl = mlx->txt->txt1_sl;
        mlx->txt_h = mlx->txt->txt1_h;
    }
    if (r->wall_dir == 'S')
    {
        mlx->txt_d = mlx->txt->txt2_d;
        mlx->text_sl = mlx->txt->txt2_sl;
        mlx->txt_h = mlx->txt->txt2_h;
    }
    if (r->wall_dir == 'E')
    {
        mlx->txt_d = mlx->txt->txt3_d;
        mlx->text_sl = mlx->txt->txt3_sl;
        mlx->txt_h = mlx->txt->txt3_h;
    }
    if (r->wall_dir == 'W')
    {
        mlx->txt_d = mlx->txt->txt4_d;
        mlx->text_sl = mlx->txt->txt4_sl;
        mlx->txt_h = mlx->txt->txt4_h;
    }
}

void    define_line(t_mlx *mlx, t_r *r)
{
    mlx->l_h = (int)(mlx->screen_h / r->wall_dist);
    mlx->l_start = (mlx->l_h * -1) / 2 + mlx->screen_h / 2;
    if (mlx->l_start < 0)
        mlx->l_start = 0;
    mlx->l_end = mlx->l_h / 2 + mlx->screen_h / 2;
    if (mlx->l_end >= mlx->screen_h)
        mlx->l_end = mlx->screen_h -1;
}