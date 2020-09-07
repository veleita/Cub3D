#include "cub3d.h"

int rungame(t_p *p)
{
  move(p);
  raycasting(p->pl, p->mlx, p->map, p->r);
  drawspr(p->mlx, p->pl, p->r);
  if(!p->screenshot)
    mlx_put_image_to_window(p->mlx->ptr, p->mlx->win, p->mlx->img, 0, 0);
  return (0);

}

int close_game(t_p *p)
{
  int i;

  i = 0;
  if(p->lines){
    while(p->lines[i]){
      free(p->lines[i]);
      i++;
    }
    free(p->lines);
  }
  return 0;
}

int start_game(t_p *p, int argc, char **argv)
{
  t_txt text;

  p->mlx->txt = &text;
  parse(argv[1], p);
  if (!(p->mlx->ptr = mlx_init()))
    error("Error. MLX can't init", p);
  txt_init(p->mlx->txt, p->mlx);
  p->mlx->img = mlx_new_image(p->mlx->ptr, p->mlx->screen_w, p->mlx->screen_h);
  p->mlx->d_ad = (int *)mlx_get_data_addr(p->mlx->img, &(p->mlx->bit), &(p->mlx->sl), &(p->mlx->ed));
  if (argc == 3)
    make_screenshot(p, argv[2]);
  if(!(p->mlx->win = mlx_new_window(p->mlx->ptr, p->mlx->screen_w, p->mlx->screen_h, "cub3d")))
    error("Error. Mlx fail", p);
  mlx_hook(p->mlx->win, 2, 1, keypress, (void *)p);
  mlx_key_hook(p->mlx->win, keyrelease, (void *)p);
	mlx_hook(p->mlx->win, 17, 1, close_game, (void *)p);
	mlx_loop_hook(p->mlx->ptr, rungame, (void *)p);
	mlx_loop(p->mlx->ptr);
	return (1);
}

int main(int argc, char **argv)
{
  t_mlx mlx;
  t_pl  pl;
  t_m   map;
  t_r   r;
  t_p   p;
    
  p.mlx = &mlx;
  p.pl = &pl;
  p.map = &map;
  p.r = &r;
  p.lines = 0;

  if(argc > 3)
    error("Error, incorrect arguments", &p);
  if (argc < 2)
    error("Error, incorrect arguments", &p);
    
  start_game(&p, argc, argv);

}