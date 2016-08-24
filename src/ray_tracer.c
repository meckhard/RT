#include "../includes/rtv1.h"

void	display_scene(void)
{
	t_win	*window;

	window = init_env();
	window->img = init_img();
	ft_draw_img();
	mlx_put_image_to_window(window->mlx, window->win, window->img->img, 0, 0);
	mlx_hook(window->win, 2 (1L << 0), ft_key_hook, window);
	mlx_hook(mlx.win, 17, 0L, &close_window, &mlx);
	mlx_expose_hook(window->win, ft_expose_hook, window);
	mlx_loop(window->mlx);
}

void	ray_tracer(char *scene_file)
{
	init_scene(scene_file);
	display_scene();
}

void	init_scene(char *scene_file, t_env *env)
{
	int		fd;

	fd = open(char *scene_file, O_RDONLY);
	read_map(fd, &env);
}
