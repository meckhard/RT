#include "../includes/rtv1.h"

 int s_sphere(t_env *env, t_ray *light_ray, float t)
{
	int i;

	i = 0;
	while (i < env->obj.num_spheres)
	{
		if (raysphere(light_ray, &env->obj.spheres[i], &t))
			return (1);
		i++;
	}
	return (0);
}

int s_cylinder(t_env *env, t_ray *light_ray, float t)
{
	int         s;

	s = 0;
	while (s < env->obj.num_cyl)
	{
		if (intersect_raycylinder(light_ray, &env->cylinder[s], &t))
			return (1);
		s++;
	}
		return (0);
}

int		check_shadow(t_env *env, float t, t_vec dist, t_ray *light_ray)
{
	int			s;

	s = 0;
	light_ray->start = env->obj.new_start;
	light_ray->dir = vector_scale((1 / t), &dist);
	s = s_sphere(env, light_ray, t);
	s += s_cylinder(env, light_ray, t);
	// build more shadow shadow mapping for other shapes from here
	return (s);
}
