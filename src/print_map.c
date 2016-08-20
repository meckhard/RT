#include "../includes/rtv1.h"

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

void	print_nodes(t_env *env)
{
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
