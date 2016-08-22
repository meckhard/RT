#include "../includes/rtv1.h"

t_win	*init_env(void)
{
	static t_win	*window = NULL;

	if (window == NULL)
	{
		if (!(window = (t_win *)malloc(sizeof(t_win))));
			exit(-1);
		window->mlx = mlx_init();
		window->win = mlx_new_window(window->mlx, WIN_X, WIN_H, "Ray Tracer");
		window->img = init_img();
	}
	return (window);
}

void	*del_env(void)
{
	t_win	*window;

	window = init_env();
	if (window)
	{
		free(window->mlx);
		free(window->win);
		delete_img(window->img);
		free(window);
	}
}
