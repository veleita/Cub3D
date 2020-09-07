#include "cub3d.h"


void    txt_init(t_txt *txt, t_mlx *mlx)
{
    txt->txt1 = mlx_xpm_file_to_image(mlx->ptr, txt->txt1_p, &(txt->txt1_w), &(txt->txt1_h));
    txt->txt2 = mlx_xpm_file_to_image(mlx->ptr, txt->txt2_p, &(txt->txt2_w), &(txt->txt2_h));
    txt->txt3 = mlx_xpm_file_to_image(mlx->ptr, txt->txt3_p, &(txt->txt3_w), &(txt->txt3_h));
    txt->txt4 = mlx_xpm_file_to_image(mlx->ptr, txt->txt4_p, &(txt->txt4_w), &(txt->txt4_h));
	txt->txt5 = mlx_xpm_file_to_image(mlx->ptr, txt->spr_p, &(txt->txt5_w), &(txt->txt5_h));
	txt->txt1_d = (int *)mlx_get_data_addr(txt->txt1, &txt->txt1_sb, &txt->txt1_sl, &txt->txt1_ed);
	txt->txt2_d = (int *)mlx_get_data_addr(txt->txt2, &txt->txt2_sb, &txt->txt2_sl, &txt->txt2_ed);
    txt->txt3_d = (int *)mlx_get_data_addr(txt->txt3, &txt->txt3_sb, &txt->txt3_sl, &txt->txt3_ed);
	txt->txt4_d = (int *)mlx_get_data_addr(txt->txt4, &txt->txt4_sb, &txt->txt4_sl, &txt->txt4_ed);
	txt->txt5_d = (int *)mlx_get_data_addr(txt->txt5, &txt->txt5_sb, &txt->txt5_sl, &txt->txt5_ed); 
}

