#include "../includes/rtv1.h"

/*void	sphere_raytrace(t_env *env)
{
	t_ray		r;
	int			x;
	int			y;
	t_col		col;

	y = 0;
	while (y <= WIN_Y)
	{
		x = 0;
		while (x <= WIN_X)
		{
			reset_col(&col);
			r.start.x = x;
			r.start.y = y;
			r.start.z = -2000;
			r.dir.x = 0;
			r.dir.y = 0;
			r.dir.z = 1;
			main_sphere_loop(env, &r, &col);
			save_col(env, &col, x, y);
			x++;
		}
		y++;
	}
}*/

int		main(int argc, char **argv)
{
	int			fd;

	t_env		env;
//	t_win		window;
//	t_objects	ob;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		read_map(fd, &env);
	}
//	get_commands(&ob);
//	get_commands2(&ob);
//	window.mlx = mlx_init();
//	window.win = mlx_new_window(window.mlx, WIN_X, WIN_Y, "Ray Tracer");
//	mlx.img = mlx_new_image(mlx.mlx, WIN_X, WIN_Y);
//	env.img.data =
//	mlx_get_data_addr(env.img.img, &env.img.bpp, &env.img.s, &env.img.e);
//	sphere_raytrace(&env);
//	mlx_put_image_to_window(env.mlx, env.win, env.img.img, 0, 0);
//	free_commands(&ob);

//	mlx_loop(window.mlx);
	return (0);
}
