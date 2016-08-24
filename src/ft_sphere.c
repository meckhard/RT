#include "../includes/rtv1.h"

int	sphere_intersect(t_env *env, float *t)
{
	t_discriminant	var;
	t_vec			dist;
	float			pos;
	float			neg;

	var.a = vector_dot(&env->r->dir, &env->r->dir);
//	printf("ray.x:	%f\n", env->r->start.x);
	dist = vector_sub(&env->r->start, &env->s->sp[0]->centre);
	var.b = 2 * vector_dot(&env->r->dir, &dist);
	var.c = vector_dot(&dist, &dist) - (env->s->sp[0]->radius * env->s->sp[0]->radius);
	var.discr = var.b * var.b - (4 * var.a * var.c);
//	printf("var.discr:	%f\n", var.discr);
	if (var.discr < 0)
	{
//		printf("-2\n");
		return (-2);
	}
	else
	{
		var.sqrtdiscr = sqrtf(var.discr);
//		printf("%f\n", var.sqrtdiscr);
		pos = (-var.b + var.sqrtdiscr) / (2);
		neg = (-var.b - var.sqrtdiscr) / (2);
//		if (pos > neg)
//			pos = neg;
		if ((pos > 0.001f) && (pos < *t))
		{
			*t = pos;
//			printf("t:	%f\n", *t);
			return (1);
		}
//		printf("-1\n");
		return (-1);
	}
//	printf("0\n");
	return (0);
}
