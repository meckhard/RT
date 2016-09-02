#include "../includes/rtv1.h"

int		plane_intersect(t_ray *r)
{
	float		k[3];

	k[0] = 1;
	if (fabs(r->start.z) < 0.00001)
		return (0xFFFFFFFF);
	k[1] = -r->dir.z / r->start.z;
	return (0);
}
