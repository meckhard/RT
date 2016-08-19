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
//	t_objects	ob;
	t_env 		env;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		read_map(fd, &env);
	}
//	get_commands(&ob);
//	get_commands2(&ob);
//	env.mlx = mlx_init();
//	env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, "rtv1");
//	env.img.img = mlx_new_image(env.mlx, WIN_X, WIN_Y);
//	env.img.data =
//	mlx_get_data_addr(env.img.img, &env.img.bpp, &env.img.s, &env.img.e);
//	sphere_raytrace(&env);
//	mlx_put_image_to_window(env.mlx, env.win, env.img.img, 0, 0);
//	free_commands(&ob);
//	mlx_hook(env.win, 2, (1L << 0), &key_press, &env);
//	mlx_hook(env.win, 17, 0L, &close_window, &env);
//	mlx_loop(env.mlx);
	return (0);
}
