#include "../includes/rtv1.h"

void	sphere_raytrace(t_env *env, t_win *win)
{
	t_col		col;

	win->img = NULL;
	env->r->start.y = 0;
	while (env->r->start.y <= WIN_Y)
	{
		env->r->start.x = 0;
		while (env->r->start.x <= WIN_X)
		{
			reset_col(&col);
			main_sphere_loop(env, &col);
//			save_col(win, &col, x, y);
//			printf("%d\n", x);
			env->r->start.x++;
		}
//		printf("%f\n", env->r->start.y);
		env->r->start.y++;
	}
}

void	reset_col(t_col *col)
{
	col->r = 0;
	col->g = 0;
	col->b = 0;
}

int		main(int argc, char **argv)
{
	int			fd;

	t_env		env;
	t_win		window;
//	t_objects	ob;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		read_map(fd, &env);
	}
//	get_commands(&ob);
//	get_commands2(&ob);
//	window = (t_win *)malloc(sizeof(t_win));
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, WIN_X, WIN_Y, "Ray Tracer");
//	window->img = (t_img *)malloc(sizeof(t_img));
//	window.img = mlx_new_image(window.mlx, WIN_X, WIN_Y);
//	window.img->data = mlx_get_data_addr(window.img->img, &window.img->bpp, \
//			&window.img->size_line, &window.img->endian);
	sphere_raytrace(&env, &window);
//	mlx_put_image_to_window(window.mlx, window.win, window.img->img, 0, 0);
//	free_commands(&ob);
	mlx_hook(window.win, 2, (1L << 0), &key_press, &env);
	mlx_hook(window.win, 17, 0L, &close_window, &env);
	mlx_loop(window.mlx);
	return (0);
}
