#include "../includes/rtv1.h"

int		check_in_shadow(t_env *env, float t, t_vector dist, t_ray *light_ray)
{
	int			s;

	light_ray->start = env->obj.new_start;
	light_ray->dir = vector_scale((1 / t), &dist);
	s = s_spheres(env, light_ray, t);
	// build more shadow shaddow mapping for other shapes from here
	return (s);
}

int	s_sphere(t_env *env, t_ray *light_ray, float t)
{
	int i;

	i = 0;
	while (i < env->obj.num_spheres)
	{
		if (raysphere(light_ray, &OBJ.spheres[i], &t))
			return (1);
		i++;
	}
	return (0);
}
