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
//	t_nodes	*node;

//	node = (t_nodes *)malloc(sizeof(t_nodes));
//	env->l = (t_light *)malloc(sizeof(t_light));
	env->l[1] = 0;
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
		if (ft_strcmp(line, "end") == 0)
			break;
	}
//	reverse_light(node, env);
	print_nodes(env);
}

void	light_list(const int fd, char *line, t_env *env)
{
	env->l[0] = (t_light *)malloc(sizeof(t_light));
	get_light(fd, line, env->l[0]);
	env->l[0]->next = env->l[1];
	env->l[1] = env->l[0];
//	print_nodes2(&node->l[1]);
//	print_nodes2(&node->l[0]);
}

void	reverse_light(t_env *env)
{
	ft_memset(&env->l[0], 0, 1);
	while (&(*env).l[1])
	{
		env->l[2] = env->l[1]->next;
		env->l[1]->next = env->l[0];
		env->l[0] = env->l[1];
		env->l[1] = env->l[2];
	}
//	print_nodes2(&n->l[1]);
}

void	print_nodes2(t_light *l)//, t_light *b)
{
	printf("l[1].pos.x:		%f\n", l->pos.x);
	printf("l[1].pos.y:		%f\n", l->pos.y);
	printf("l[1].pos.z:		%f\n", l->pos.z);
	printf("l[1].intensity.r:	%f\n", l->intensity.r);
	printf("l[1].intensity.g:	%f\n", l->intensity.g);
	printf("l[1].intensity.b:	%f\n", l->intensity.b);
	printf(".\n");
}

void	print_nodes(t_env *env)//t_nodes *node)//, t_light *b)
{
	env->l[2] = env->l[0];
	while (env->l[2])
	{
		printf("l[1].pos.x:		%f\n", env->l[2]->pos.x);
		printf("l[1].pos.y:		%f\n", env->l[2]->pos.y);
		printf("l[1].pos.z:		%f\n", env->l[2]->pos.z);
		printf("l[1].intensity.r:	%f\n", env->l[2]->intensity.r);
		printf("l[1].intensity.g:	%f\n", env->l[2]->intensity.g);
		printf("l[1].intensity.b:	%f\n", env->l[2]->intensity.b);
		printf(".\n");
		env->l[2] = env->l[2]->next;
	}
}

void	get_camera(const int fd, char *line, t_env *env)
{
	char	**temp;

	while (ft_strcmp(line, ".") != 0)
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
	free_map(&temp);
}

void	get_light(const int fd, char *line, t_light *l)
{
	char	**temp;

	while (ft_strcmp(line, ".") != 0)
	{
		get_next_line(fd, &line);
		line = rm_padding(line);
		temp = ft_strsplit(line, ' ');
		if (ft_strcmp(temp[0], "P.X") == 0)
			l->pos.x = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "P.Y") == 0)
			l->pos.y = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "P.Z") == 0)
			l->pos.z = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "I.R") == 0)
			l->intensity.r = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "I.G") == 0)
			l->intensity.g = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "I.B") == 0)
			l->intensity.b = ft_atof(temp[1]);
	}
	free_map(&temp);
}

void	get_material(const int fd, char *line, t_material *m)
{
	char	**temp;

	while (ft_strcmp(line, ".") != 0)
	{
		get_next_line(fd, &line);
		line = rm_padding(line);
		temp = ft_strsplit(line, ' ');
		if (ft_strcmp(temp[0], "D.R") == 0)
			m->diffuse.r = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "D.G") == 0)
			m->diffuse.g = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "D.B") == 0)
			m->diffuse.b = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "REFLECT") == 0)
			m->reflect = ft_atof(temp[1]);
	}
	free_map(&temp);
}

void	get_sphere(const int fd, char *line, t_sphere *sp)
{
	char		**temp;
	t_material	m;

	while (ft_strcmp(line, "MATERIAL") != 0)
	{
		get_next_line(fd, &line);
		line = rm_padding(line);
		temp = ft_strsplit(line, ' ');
		if (ft_strcmp(temp[0], "P.X") == 0)
			sp->centre.x = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "P.Y") == 0)
			sp->centre.y = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "P.Z") == 0)
			sp->centre.z = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "RADIUS") == 0)
			sp->radius = ft_atof(temp[1]);
		if (ft_strcmp(line, "MATERIAL") == 0)
		{
			get_material(fd, line, &m);
			printf("m->diffuse.r:		%f\n", m.diffuse.r);
			printf("m->diffuse.g:		%f\n", m.diffuse.g);
			printf("m->diffuse.b:		%f\n", m.diffuse.b);
			printf("m->reflect:		%f\n", m.reflect);
			printf(".\n");
			sp->m = m;
			break;
		}
	}
	free_map(&temp);
//	free_mat(&m);
}

void	free_map(char ***temp)
{
	if (*temp != NULL)
	{
		free(*temp);
		*temp = NULL;
	}
}

void	free_mat(t_material *m)
{
	if (m != NULL)
	{
		free(m);
		m = NULL;
	}
}

void	print_environment(t_env *env)
{
	unsigned int	i;

	i = 0;
	printf("env.ray.start.z:	%f\n", env->r.start.z);
	printf("env.ray.dir.x:		%f\n", env->r.dir.x);
	printf("env.ray.dir.y:		%f\n", env->r.dir.y);
	printf("env.ray.dir.z:		%f\n", env->r.dir.z);
	printf(".\n");

}
