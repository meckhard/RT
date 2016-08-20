#include "../includes/rtv1.h"
#include <stdio.h>

void	read_map(const int fd, t_env *env)
{
	char			*line;

	get_next_line(fd, &line);
	if (ft_strcmp(line, "start") == 0)
	{
		search_map(fd, line, env);
	}
	print_environment(env);
}

void	search_map(const int fd, char *line, t_env *env)
{
	set_nodes(env);
	while (get_next_line(fd, &line) != 0)
	{
		line = rm_padding(line);
		if (ft_strcmp(line, "CAMERA") == 0)
		{
			get_camera(fd, line, env);
			continue;
		}
		if (ft_strcmp(line, "LIGHT") == 0)
		{
			light_list(fd, line, env);
			continue;
		}
//		if (ft_strcmp(line, "OBJECT") == 0)
//		{
//			get_shape(fd, line, env);
//			continue;
//		}
		if (ft_strcmp(line, "end") == 0)
			break;
	}
	reverse_lists(env);
	create_environment(env);
	print_nodes(env);
}

void	create_environment(t_env *env)
{
	env->l[2] = env->l[0];
//	env->s->sp[2] = env->s->sp[0];
}

void	set_nodes(t_env *env)
{
	env->l[1] = 0;
//	env->s->sp[1] = 0;
}
