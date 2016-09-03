#include "../includes/rtv1.h"

static int		dist_of_intersect(float *a, float *b)
{
	if (*a < *b)
		return (-1);
	else
	{
		a = b;
		return (0);
	}
}

void			loop_spheres(t_env *env, t_sphere *sp, float *hit, float *temp)
{
	while (sp)
	{
		*temp = 200000.0f;
		if (sphere_intersect(&env->r, sp, temp) == 1)
		{
			if ((dist_of_intersect(hit, temp) == -1) && sp->next != NULL)
			{
				sp = sp->next;
				continue;
			}
			else
			{
				reset_colour(&env->c, sp->m.diffuse.r, \
						sp->m.diffuse.g, sp->m.diffuse.b);
			}
		}
		if (*temp == 200000.0f)
			*hit = 200000.0f;
//			lighting();
		sp = sp->next;
	}
}

void			loop_cylinders(t_env *env, t_cylinder *cy, float *hit, float *temp)
{
	while (cy)
	{
		*temp = 200000.0f;
		if (cylinder_intersect(&env->r, cy, temp) == 1)
		{
//			if (dist_of_intersect(hit, temp) == -1)
//			{
//				cy = cy->next;
//				continue;
//			}
			if ((dist_of_intersect(hit, temp) == -1) && (cy->next != NULL))
			{
				cy = cy->next;
				continue;
			}
			reset_colour(&env->c, cy->m.diffuse.r, \
					cy->m.diffuse.g, cy->m.diffuse.b);
		}
		if (*temp == 200000.0f)
			*hit = 200000.0f;
//			lighting();
		cy = cy->next;
	}
}

/*void			loop_planes(t_env *env, t_plane *p, float *hit)
{
	while (p)
	{
		*hit = 200000.0f;
		if (plane_intersect(&env->r, p, hit) == 1)
		{
			reset_colour(&env->c, p->m.diffuse.r, \
					p->m.diffuse.g, p->m.diffuse.b);
		}
		p = p->next;
	}
}*/

/*void			loop_cones(t_env *env, t_cone *co, float *hit)
{
	while (co)
	{
		*hit = 200000.0f;
		if (cone_intersect(&env->r, co, hit) == 1)
		{
			reset_colour(&env->c, co->m.diffuse.r, \
					co->m.diffuse.g, co->m.diffuse.b);
		}
		co = co->next;
	}
}*/
