#include "../includes/rtv1.h"

t_img	*init_img(void)
{
	t_win	*win;
	t_img	*img;

	win = init_env();
	img = (t_img *)malloc(sizeof(t_img));
	img->img = mlx_new_image(win->mlx, WIN_X, WIN_Y);
	img->data = mlx_get_data_addr(img->img, &img->bpp, \
		&img->size_line, &img->endian);
	return (img);
}

void	del_img(t_img *img)
{
	if (img)
	{
		if (img->img != NULL)
			free(img->img);
		free(img);
	}
}
