#include "../includes/rtv1.h"

void	sphere_list(const int fd, char *line, t_env *env)
{
	env->s->sp[0] = (t_sphere *)malloc(sizeof(t_sphere));
	get_sphere(fd, line, env->s->sp[0]);
	env->s->sp[0]->next = env->s->sp[1];
	env->s->sp[1] = env->s->sp[0];
}

void	cylinder_list(const int fd, char *line, t_env *env)
{
	env->s->cy[0] = (t_cylinder *)malloc(sizeof(t_cylinder));
	get_cylinder(fd, line, env->s->cy[0]);
	env->s->cy[0]->next = env->s->cy[1];
	env->s->cy[1] = env->s->cy[0];
}

void	cone_list(const int fd, char *line, t_env *env)
{
	env->s->co[0] = (t_cone *)malloc(sizeof(t_cone));
	get_cone(fd, line, env->s->co[0]);
	env->s->co[0]->next = env->s->co[1];
	env->s->co[1] = env->s->co[0];
}

void	plane_list(const int fd, char *line, t_env *env)
{
	env->s->p[0] = (t_plane *)malloc(sizeof(t_plane));
	get_plane(fd, line, env->s->p[0]);
	env->s->p[0]->next = env->s->p[1];
	env->s->p[1] = env->s->p[0];
}

void	light_list(const int fd, char *line, t_env *env)
{
	env->l[0] = (t_light *)malloc(sizeof(t_light));
	get_light(fd, line, env->l[0]);
	env->l[0]->next = env->l[1];
	env->l[1] = env->l[0];
}
