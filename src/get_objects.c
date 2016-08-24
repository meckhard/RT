#include "../includes/rtv1.h"

void	get_shape(const int fd, char *line, t_env *env)
{
	get_next_line(fd, &line);
	line = rm_padding(line);
	if (ft_strcmp(line, "SPHERE") == 0)
		sphere_list(fd, line, env);
//	if (ft_strcmp(line, "CYLINDER") == 0)
//		cylinder_list(fd, line, env);
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
			env->r->start.z = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "R.D.X") == 0)
			env->r->dir.x = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "R.D.Y") == 0)
			env->r->dir.y = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "R.D.Z") == 0)
			env->r->dir.z = ft_atof(temp[1]);
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
	char	**temp;

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
			get_material(fd, line, &sp->m);
			break;
		}
	}
	free_map(&temp);
}

void	get_cylinder(const int fd, char *line, t_cylinder *cy)
{
	char	**temp;
	
	while (ft_strcmp(line, "MATERIAL") != 0)
	{
		get_next_line(fd, &line);
		line = rm_padding(line);
		temp = ft_strsplit(line, ' ');
		if (ft_strcmp(temp[0], "P.X") == 0)
			cy->centre.x = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "P.Y") == 0)
			cy->centre.y = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "P.Z") == 0)
			cy->centre.z = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "N.X") == 0)
			cy->normal.x = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "N.Y") == 0)
			cy->normal.y = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "N.Z") == 0)
			cy->normal.z = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "HEIGHT") == 0)
			cy->height = ft_atof(temp[1]);
		if (ft_strcmp(temp[0], "RADIUS") == 0)
			cy->radius = ft_atof(temp[1]);
		if (ft_strcmp(line, "MATERIAL") == 0)
		{
			get_material(fd, line, &cy->m);
			break;
		}
	}
	free_map(&temp);
}
