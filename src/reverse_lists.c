#include "../includes/rtv1.h"

void	reverse_lists(t_env *env)
{
	reverse_light(env);
	reverse_sphere(env);
//	reverse_cylinder(env);
}

void	reverse_light(t_env *env)
{
	env->l[0] = 0;	
	while (env->l[1])
	{
		env->l[2] = env->l[1]->next;
		env->l[1]->next = env->l[0];
		env->l[0] = env->l[1];
		env->l[1] = env->l[2];
	}
}

void	reverse_sphere(t_env *env)
{
	env->s->sp[0] = 0;
	while (env->s->sp[1])
	{
		env->s->sp[2] = env->s->sp[1]->next;
		env->s->sp[1]->next = env->s->sp[0];
		env->s->sp[0] = env->s->sp[1];
		env->s->sp[1] = env->s->sp[2];
	}
}

void	reverse_cylinder(t_env *env)
{
	env->s->cy[0] = 0;
	while (env->s->cy[1])
	{
		env->s->cy[2] = env->s->cy[1]->next;
		env->s->cy[1]->next = env->s->cy[0];
		env->s->cy[0] = env->s->cy[1];
		env->s->cy[1] = env->s->cy[2];
	}
}
