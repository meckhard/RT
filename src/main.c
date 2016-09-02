#include "../includes/rtv1.h"

int		main(int argc, char **argv)
{
	int				fd;
	char			**temp;
	t_env			env;
	t_win			window;

	if (argc == 2)
	{
		if ((temp = ft_strsplit(argv[1], '/')))
		{
			if ((ft_strcmp(temp[0], "maps") == 0) && (ft_strcmp(temp[1], "\0") != 0))
			{
				fd = open(argv[1], O_RDONLY);
				if (fd == -1)
				{
					ft_putstr(R_MESS01);
					return (0);
				}
				read_map(fd, &env);
				window.mlx = mlx_init();
				window.win = mlx_new_window(window.mlx, WIN_X, WIN_Y, "Ray Tracer");
				window.img.img = mlx_new_image(window.mlx, WIN_X, WIN_Y);
				window.img.data = mlx_get_data_addr(window.img.img, &window.img.bpp, \
						&window.img.size_line, &window.img.endian);
				ray_trace(&env, &window);
				mlx_put_image_to_window(window.mlx, window.win, window.img.img, 0, 0);
				mlx_hook(window.win, 2, (1L << 0), &key_press, &env);
				mlx_hook(window.win, 17, 0L, &close_window, &env);
				mlx_loop(window.mlx);
			}
			else
				ft_putstr(R_MESS01);
		}
	}
	else
		ft_putstr(R_MESS01);
	return (0);
}
