#include "../includes/rtv1.h"

void	read_map(const int fd, t_env *env)
{
	char			*line;

	get_next_line(fd, &line);
	if (ft_strcmp(line, "start") == 0)
		search_map(fd, line, env);
//	print_environment(env);
//	print_nodes(env);
}

void	search_map(const int fd, char *line, t_env *env)
{
	env->s = (t_shape *)malloc(sizeof(t_shape));
	set_nodes(env);
	while (get_next_line(fd, &line) != 0)
	{
		line = rm_padding(line);
		if (ft_strcmp(line, "CAMERA") == 0)
		{
			env->r = (t_ray *)malloc(sizeof(t_ray));
			get_camera(fd, line, env);
			continue;
		}
		if (ft_strcmp(line, "LIGHT") == 0)
		{
			light_list(fd, line, env);
			continue;
		}
		if (ft_strcmp(line, "OBJECT") == 0)
		{
			get_shape(fd, line, env);
			continue;
		}
		if (ft_strcmp(line, "end") == 0)
			break;
	}
	reverse_lists(env);
	create_environment(env);
}

void	create_environment(t_env *env)
{
	env->l[2] = env->l[0];
	env->s->sp[2] = env->s->sp[0];
//	env->s->cy[2] = env->s->cy[0];
//	env->s->co[2] = env->s->co[0];
}

void	set_nodes(t_env *env)
{
	env->l[1] = 0;
	env->s->sp[1] = 0;
//	env->s->cy[1] = 0;
//	env->s->co[1] = 0;
}
