#include "../includes/rtv1.h"
#include <stdio.h>

void	read_map(const int fd, t_env *env)
{
	char *line;

	get_next_line(fd, &line);
	if (ft_strcmp(line, "start") == 0)
		search_map(fd, line);
	print_environment(env);
}

void	search_map(const int fd, char *line, t_env *env)
{
	t_light		*l;
	t_sphere	*sp;

	while (get_next_line(fd, &line) != 0)
	{
		line = rm_padding(line);
		if (ft_strcmp(line, "CAMERA") == 0)
		{
			get_camera(fd, line, env);
			continue;
		}
		if (ft_strcmp(line, "end") == 0)
			break;
	}
}

void	get_camera(const int fd, char *line, t_env *env)
{
	char	**temp;

	while (ft_strcmp(line, ".") == 0)
	{
		get_next_line(fd, &line);
		line = rm_padding(line);
		temp = ft_strsplit(line, ' ');
		if (ft_strcmp(temp[0], "R.Z") == 0)
			env->r.start.z = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "R.D.X") == 0)
			env->r.dir.x = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "R.D.Y") == 0)
			env->r.dir.y = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "R.D.Z") == 0)
			env->r.dir.z = ft_atof(temp[1]);
	}
	free_temp(&temp);
}

void	print_environment(t_env *env)
{
	printf("env->r.start.z:			%f\n", env->r.start.z);
	printf("env->r.dir.x:			%f\n", env->r.dir.x);
	printf("env->r.dir.y:			%f\n", env->r.dir.y);
	printf("env->r.dir.z:			%f\n", env->r.dir.z);
	printf(".\n");
//	while (env->l)
//	{
	printf("env->l->pos.x:			%f\n", env->l->pos.x);
	printf("env->l->pos.y:			%f\n", env->l->pos.y);
	printf("env->l->pos.z:			%f\n", env->l->pos.z);
	printf("env->l->intensity.r:		%f\n", env->l->intensity.r);
	printf("env->l->intensity.g:		%f\n", env->l->intensity.g);
	printf("env->l->intensity.b:		%f\n", env->l->intensity.b);
	printf(".\n");
	env->l = env->l->next;
//	}
