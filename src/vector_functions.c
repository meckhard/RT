#include "../includes/rtv1.h"

t_vec	vector_sub(t_vec *v1, t_vec *v2)
{
	t_vec v3 = {v1->x - v2->x, v1->y - v2->y, v1->z - v2->z};
	return (v3);
}

float		vector_dot(t_vec *v1, t_vec *v2)
{
	return ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
}

t_vec	vector_scale(float c, t_vec *v)
{
	t_vec result = {v->x * c, v->y * c, v->z * c};
	return (result);
}

t_vec	vector_add(t_vec *v1, t_vec *v2)
{
	t_vec result = {v1->x + v2->x, v1->y + v2->y, v1->z + v2->z};
	return (result);
}
