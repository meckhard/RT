#include "../includes/rtv1.h"

void	print_environment(t_env *env)
{
	unsigned int	i;

	i = 0;
	printf("env->ray.start.z:		%f\n", env->r.start.z);
	printf("env->ray.dir.x:			%f\n", env->r.dir.x);
	printf("env->ray.dir.y:			%f\n", env->r.dir.y);
	printf("env->ray.dir.z:			%f\n", env->r.dir.z);
	printf(".\n");

}

void	print_nodes(t_env *env)
{
	if (env->l[2] != NULL)
	{
		while (env->l[2])
		{
			printf("env->l[2]->pos.x:		%f\n", env->l[2]->pos.x);
			printf("env->l[2]->pos.y:		%f\n", env->l[2]->pos.y);
			printf("env->l[2]->pos.z:		%f\n", env->l[2]->pos.z);
			printf("env->l[2]->intensity.r:		%f\n", env->l[2]->intensity.r);
			printf("env->l[2]->intensity.g:		%f\n", env->l[2]->intensity.g);
			printf("env->l[2]->intensity.b:		%f\n", env->l[2]->intensity.b);
			printf(".\n");
			env->l[2] = env->l[2]->next;
		}
	}
	if (env->s.sp[2] != NULL)
	{
		while (env->s.sp[2])
		{
			printf("env->s->sp[2]->pos.x:		%f\n", env->s.sp[2]->centre.x);
			printf("env->s->sp[2]->pos.y:		%f\n", env->s.sp[2]->centre.y);
			printf("env->s->sp[2]->pos.z:		%f\n", env->s.sp[2]->centre.z);
			printf("env->s->sp[2]->radius:		%f\n", env->s.sp[2]->radius);
			printf("env->s->sp[2]->m.diffuse.r:	%f\n", env->s.sp[2]->m.diffuse.r);
			printf("env->s->sp[2]->m.diffuse.g:	%f\n", env->s.sp[2]->m.diffuse.g);
			printf("env->s->sp[2]->m.diffuse.b:	%f\n", env->s.sp[2]->m.diffuse.b);
			printf("env->s->sp[2]->m.reflect:	%f\n", env->s.sp[2]->m.reflect);
			printf(".\n");
			env->s.sp[2] = env->s.sp[2]->next;
		}
	}
	if (env->s.cy[2] != NULL)
	{
		while (env->s.cy[2])
		{
			printf("env->s->cy[2]->pos.x:		%f\n", env->s.cy[2]->centre.x);
			printf("env->s->cy[2]->pos.y:		%f\n", env->s.cy[2]->centre.y);
			printf("env->s->cy[2]->pos.z:		%f\n", env->s.cy[2]->centre.z);
//			printf("env->s->cy[2]->normal.x:	%f\n", env->s.cy[2]->normal.x);
//			printf("env->s->cy[2]->normal.y:	%f\n", env->s.cy[2]->normal.y);
//			printf("env->s->cy[2]->normal.z:	%f\n", env->s.cy[2]->normal.z);
			printf("env->s->cy[2]->radius:		%f\n", env->s.cy[2]->radius);
//			printf("env->s->cy[2]->height:		%f\n", env->s.cy[2]->height);
			printf("env->s->cy[2]->m.diffuse.r:	%f\n", env->s.cy[2]->m.diffuse.r);
			printf("env->s->cy[2]->m.diffuse.g:	%f\n", env->s.cy[2]->m.diffuse.g);
			printf("env->s->cy[2]->m.diffuse.b:	%f\n", env->s.cy[2]->m.diffuse.b);
			printf("env->s->cy[2]->m.reflect:	%f\n", env->s.cy[2]->m.reflect);
			printf(".\n");
			env->s.cy[2] = env->s.cy[2]->next;
		}
	}
}
