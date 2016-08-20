#include "../includes/rtv1.h"

void	sphere_list(const int fd, char *line, t_env *env)
{
	env->s->sp[0] = (t_sphere *)malloc(sizeof(t_sphere));
	get_sphere(fd, line, env->s->sp[0]);
	env->s->sp[0]->next = env->s->sp[1];
	env->s->sp[1] = env->s->sp[0];
}

void	light_list(const int fd, char *line, t_env *env)
{
	env->l[0] = (t_light *)malloc(sizeof(t_light));
	get_light(fd, line, env->l[0]);
	env->l[0]->next = env->l[1];
	env->l[1] = env->l[0];
}
