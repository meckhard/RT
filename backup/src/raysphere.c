#include "../includes/rtv1.h"

int		raysphere(t_ray *ray, t_sphere *sphere)
{
	float	a;
	float	b;
	float	c;
	float	discr;
	t_vec	dist;
	int		ret;

	a = vector_dot(&ray->dir, &ray->dir); 
	dist = vector_sub(&ray->start, &sphere->shape.pos);
	b = 2 * vector_dot(&ray->dir, &dist);
	c = vector_dot(&dist, &dist) - (sphere->rad * sphere->rad);
	discr = b * b - 4 * a * c;
	if (discr < 0)
		ret = 0;
	else
		ret = 1;
	return (ret);
}
