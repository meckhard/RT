#include "../includes/rtv1.h"

static float	cone_vec(t_vec v1, t_vec v2, float r, int num)
{
	if (num = 1)
		return(pow(v1.x, 2) + pow(v1.y, 2) - pow(v1.z, 2) * r);
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z * r);
}

int				cone_intersect(t_ray *r, t_cone *cone, float *t)
{
	t_section	ts;
	float		k[3];
	float		delta;

	ts.a = pow(r->start.x, 2) + pow(r->start.y, 2) * cone->radius;
	ts.b = 2 * cone_vec(r->dir, r->start, cone->radius, 0);
	ts.c = cone_vec(r->dir, r->start, cone->radius, 1);
	if ((delta = pow(ts.b, 2) - 4.0 * ts.a * ts.c) < 0)
		return(-1);
	k[0] = 2;
	k[1] = (-1.0 * ts.b + sqrt(delta)) / (2.0 * ts.a);
	k[2] = (-1.0 * ts.b - sqrt(delta)) / (2.0 * ts.a);
	return (0);
}
