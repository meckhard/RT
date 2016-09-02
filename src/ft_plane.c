#include "../includes/rtv1.h"

double      ft_plane(t_env *env, t_plane *p, t_ray dir, t_ray start)
{
    t_vec   a;
    t_vec   b;
    double  t;

    a.x = plane->normal.x * (start.x - plane->center.x);
    a.y = plane->normal.y * (start.y - plane->center.y);
    a.z = plane->normal.z * (start.z - plane->center.z);
    b.x = plane->normal.x * dir.x;
    b.y = plane->normal.y * dir.y;
    b.z = plane->normal.z * dir.z;
    return (-(a.x + a.y + a.z) / (b.x + b.y + b.z));
}