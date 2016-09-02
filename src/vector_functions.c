#include "../includes/rtv1.h"

t_vec		vector_sub(t_vec *v1, t_vec *v2)
{
	t_vec	v3;
   	
	v3.x = v1->x - v2->x;
	v3.y = v1->y - v2->y;
	v3.z = v1->z - v2->z;
	return (v3);
}

float		vector_dot(t_vec *v1, t_vec *v2)
{
//	printf("%f\t %f\t %f", v1->x, v1->y, v1->z);	
	return ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
}

t_vec		vector_scale(float c, t_vec *v)
{
	t_vec	result;
	
	result.x = v->x * c;
	result.y = v->y * c;
	result.z = v->z * c;
	return (result);
}

t_vec		vector_add(t_vec *v1, t_vec *v2)
{
	t_vec	result;
   
	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	return (result);
}

t_vec		normalize(t_vec *v)
{
	float	m;

	m = sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2));
	v->x /= m;
	v->y /= m;
	v->z /= m;
	return (*v);
}
