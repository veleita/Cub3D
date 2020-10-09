#ifndef CUB3D_H
#define CUB3D_H

# include "mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# define BUFF_SIZE 21
# define MAPW 24
# define MAPH 24

typedef struct SPRITE{
    float   x;
    float   y;
}t_spr;

typedef struct SPRITETOOLS
{
    double  spr_x;
    double  spr_y;
    double  invdet;
    double  t_x;
    double  t_y;
    int     sprscreen;
    int     spr_h;
    int     spr_w;
    int     dr_start;
    int     dr_end;
    int     txt_x;
    int     txt_y;
    int     x;
    int     y;
    int     d;
}t_sprt;

typedef struct TEXT{
    void    *txt1;
    int     *txt1_d;
    int     txt1_h;
    int     txt1_w;
    int     txt1_sl;
    int     txt1_sb;
    int     txt1_ed;
    char    *txt1_p;
    void    *txt2;
    int     *txt2_d;
    int     txt2_h;
    int     txt2_w;
    int     txt2_sl;
    int     txt2_sb;
    int     txt2_ed;
    char    *txt2_p;
    void    *txt3;
    int     *txt3_d;
    int     txt3_h;
    int     txt3_w;
    int     txt3_sl;
    int     txt3_sb;
    int     txt3_ed;
    char    *txt3_p;
    void    *txt4;
    int     *txt4_d;
    int     txt4_h;
    int     txt4_w;
    int     txt4_sl;
    int     txt4_sb;
    int     txt4_ed;
    char    *txt4_p;
    void    *txt5;
    int     *txt5_d;
    int     txt5_h;
    int     txt5_w;
    int     txt5_sl;
    int     txt5_sb;
    int     txt5_ed;
    char    *txt5_p;
    char    *spr_p;
}t_txt;

//hasta el puto mapa tengo que manejar
typedef struct MAP{
    int x;
    int y;
    int max_x;
    int max_y;
    int **wmap;
    int step_x;
    int step_y;
}t_m;

//el muñeco que es inutil el chaval
typedef struct PLAYER{
    double  pos_x;
    double  pos_y;
    double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y;
    double  p_x;
    double  p_y;
    double  camera;
    char    forward;
    char    backward;
    char    left;
    char    right;
    char    leftrot;
    char    rightrot;
    char    pos;
}t_pl;

//el raycasting de los huevos 
typedef struct RAYCASTING{
    double  dir_x;
    double  dir_y;
    double  wall_x;
    double  side_x;
    double  side_y;
    int     wall_side;
    double  delta_x;
    double  delta_y;
    char    wall_dir;
    double  wall_dist;
    double  buffer[4000];
}t_r;

//para la puta mlx
typedef struct MLX{
    t_txt   *txt;
    void    *ptr;
    void    *img;
    void    *win;
    int     *d_ad;
    int     bit;
    int     sl;
    int     ed;
    int     screen_w;
    int     screen_h;
    int     fr;
    int     fg;
    int     fb;
    int     sr;
    int     sb;
    int     sg;
    int     spr_hit;
    int     spr_num;
    t_spr   *sprite;
    int     *spr_or;
    int     x;
    int     text_x;
    int     text_sl;
    int     *txt_d;
    int     txt_h;
    int     l_h;
    int     l_start;
    int     l_end;
}t_mlx;

//estructura general de parametros
typedef struct struct1{
    t_mlx   *mlx;
    t_pl    *pl;
    t_m     *map;
    t_r     *r; 
    char    **lines;
    int     screen;
    int     floor;
    int     sky;
    int     t1;
    int     t2;
    int     t3;
    int     t4;
    int     spr;
    int     screenshot;
}t_p;

int     rungame(t_p *p);
int     start_game(t_p *p, int argc, char **argv);
int     close_game(t_p *p);

void    error(char *str, t_p *p);

int     parse(char *name, t_p *p);
char    **get_lines(char **lines, char **tmp, int fd);
void    init_p(t_p *p);
char    **parse_parameters(t_p *p, char **lines);
void    verify_params(t_p *p);

void    parse_m(t_p *p, char **ml);
int     get_max_x(char **l, t_p *p);
int		get_max_y(char **l);
void    init_m(t_m *map);
void    make_m(char **l, t_m *map);

void    check_pl(t_p *p);
int     check_mvalue(int value, int x, int y, t_p *p);
void    check_m(t_p *p, int x, int y);

int     pl_init(int x, int y, char dir, t_p *p);
void    set_camera_ew(char dir, t_pl *pl);
void    set_camera_ns(char dir, t_pl *pl);

t_spr   *get_sprites(t_p *p);
int     countspr(t_m *map);

int     choose_p(char c, char *str, t_p *p);
void    more_error (char *str, t_p *p, char *s);
void	make_res(char *str, t_p *p);
void    build_floor(char *str, t_p *p);
void    build_sky(char *str, t_p *p);

void    make_txt(int dir, char *str, t_p *p);
void    check_txt(int dir, t_p *p);
void    check_txt_second(int dir, t_p *p);

int     cubatoiF(const char *str);
int     cubatoiR(const char *str);

void    txt_init(t_txt *txt, t_mlx *mlx);

void    make_screenshot(t_p *p, char *str);
int     take_screenshot(t_p *p);
int     bmp_dat(int fd, t_mlx *mlx, int size);
int     bmp_header(int fd, int screen_h, int screen_w, int size);
void    int_char(unsigned char *head, int i);

int     keyrelease(int k, t_p *p);
int     keypress(int k, t_p *p);

int     move(t_p *p);
void    rotation(t_pl *pl);
void    move_left_and_right(t_pl *pl, t_m *map, float speed);
int     can_move(int pos);
void    move_up_and_down(t_pl *pl, t_m *map, float speed);

void    raycasting(t_pl *pl, t_mlx *mlx, t_m *map, t_r *r);
void    get_step(t_m *map, t_r *r, t_pl *pl);
void    wallhit(t_m *map, t_r *r);
void    walldist_dir(t_mlx *mlx, t_m *map, t_pl *pl, t_r *r);
void    fov_and_pos(t_mlx *mlx, t_m *map, t_r *r, t_pl *pl);

int     rgb_int(int red, int green, int blue);
int     drawline(t_mlx *mlx, int x, int text_x);
void    choose_text(t_mlx *mlx, t_r *r);
void    define_line(t_mlx *mlx, t_r *r);

void    drawspr(t_mlx *mlx, t_pl *pl, t_r *r);
void    sort_spr(t_mlx *mlx, t_pl *pl);
void    spr_h(t_sprt *sprt, t_mlx *mlx);
void    spr_w(t_sprt *sprt, t_mlx *mlx);
void    draw_sprlines(t_sprt *sprt, t_mlx *mlx, t_r *r);

char	*ft_strdup_get(char const *src);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		joinline(int fd, char **str, char **line);
int		returnv(char **str, char **line, int re, int fd);
int		get_next_line(int fd, char **line);

void	ft_bzero(void *s, size_t n);
int	    ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int	    ft_strncmp(char *s1, char *s2, unsigned int n);

#endif