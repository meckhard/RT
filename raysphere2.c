#include "../includes/rtv1.h"

int	ray_sphere_intersection(t_env *env, float *t)
{
	t_raysphere var;

	var.a = vector_dot(&env->r.dir, env->r.dir);
	var.dist = vector_sub(&env->r.start, &env->s->sp[2].centre);
	var.b = 2 * vector_dot(&env->r.dir, &var.dist);
	var.c = vector_dot(&var.dist, &var.dist) - \
		(env->s->sp[2].radius * env->s-sp[2].radius);
	var.discr = var.b * var.b - 4 * var.a * var.c;
	if (var.discr < 0)
		var.ret = 0;
	else
	{
		var.sqrtdiscr = sqrtf(var.discr);
		var.t0 = (-var.b + var.sqrtdiscr) / (2);
		var.t1 = (-var.b - var.sqrtdiscr) / (2);
		if (var.t0 > var.t1)
			var.t0 = var.t1;
		if ((var.t0 > 0.001f) && (var.t0 < *t))
		{
			*t = var.t0;
			var.ret = 1;
		}
		else
			var.ret = 0;
	}
	return (var.ret);
}
