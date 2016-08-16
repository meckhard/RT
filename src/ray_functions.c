#include "../includes/rtv1.h"

t_vec	new_vec(float x, float y, float z)
{
	t_vec	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vec	vector_sub(t_vec *v1, t_vec *v2)
{
	t_vec	res;

	res = new_vec(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
	return (res);
}

float	vector_dot(t_vec *v1, t_vec *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vec	vector_scale(float c, t_vec *v)
{
	t_vec	res;

	res.x = v->x * c;
	res.y = v->y * c;
	res.z = v->z * c;
	return (res);
}

t_vec	vector_add(t_vec *v1, t_vec *v2)
{
	t_vec res;

	res.x = v1->x + v2->x;
	res.y = v1->y + v2->y;
	res.z = v1->z + v2->z;
	return (res);
}
