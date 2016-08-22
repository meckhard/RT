#include "../includes/rtv1.h"

static void		mlx_endian(void *mlx, t_img *i, int pixel[2], t_col *c)
{
	if (img->endian)
	{
		i->data[p[1] * i->size + p[0] *
			i->bpp / 8] = mlx_get_color_value(mlx, c->r);
		i->data[p[1] * i->size + p[0] *
			i->bpp / 8 + 1] = mlx_get_color_value(mlx, c->g);
		i->data[p[1] * i->size + p[0] *
			i->bpp / 8 + 2] = mlx_get_color_value(mlx, c->b);
	}
	else
	{	
		i->data[p[1] * i->size + i->bpp / 8 * p[0]]
			= mlx_get_color_value(mlx, c->b);
		i->data[p[1] * i->size + i->bpp / 8 * p[0] + 1]
			= mlx_get_color_value(mlx, c->g); 
		i->data[p[1] * i->size + i->bpp / 8 * p[0] + 2]
			= mlx_get_color_value(mlx, c->r);
	}
}

void			draw_line(int x, t_env *env, t_col *c)
{
	int		pixel[2];

	pixel[0] = x;
	env->img.data = mlx_get_data_addr(env->img.img, \
		&env->img.bpp, &env->img.size, env->img.endian)
	pixel[1] = 0;
	while (pixel[1] < env->r)
}
