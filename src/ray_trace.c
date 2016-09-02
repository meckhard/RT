#include "../includes/rtv1.h"

void		reset_colour(t_col *col, int r, int g, int b)
{
	col->r = r;
	col->g = g;
	col->b = b;
}

void		cast_ray(t_env *env)
{
	float		hit;
	t_sphere	*sphere;
	t_cylinder	*cylinder;
	t_plane		*plane;
	t_cone		*cone;

	sphere = env->s->sp[2];
	cylinder = env->s->cy[2];
	plane = env->s->p[2];
	cone = env->s->co[2];
	env->coef = 1.0;
	while (env->coef > 0.0f)
	{
		loop_spheres(env, sphere, &hit);
		loop_cylinders(env, cylinder, &hit);
//		loop_planes(env, plane, &hit);
//		loop_cones(env, cone, &hit);
		env->coef -= 0.1f;
	}
}

void			save_pixel_to_image(t_env *env, t_win *win, int x, int y)
{
	t_col temp;

	if (env->c.r / 255.0f < 255.0f)
		temp.r = env->c.r;
	else
		temp.r = 255.0f;
	if (env->c.g / 255.0f < 255.0f)
		temp.g = env->c.g;
	else
		temp.g = 255.0f;
	if (env->c.b / 255.0f < 255.0f)
		temp.b =  env->c.b;
	else
		temp.b = 255.0f;
	win->img.data[(x + y * WIN_X) * 4 + 2] = (unsigned char)temp.r;
	win->img.data[(x + y * WIN_X) * 4 + 1] = (unsigned char)temp.g;
	win->img.data[(x + y * WIN_X) * 4 + 0] = (unsigned char)temp.b;
}

void		ray_trace(t_env *env, t_win *win)
{
	int		x;
	int		y;
//	t_col	c;

	y = 0;
	while (y < WIN_Y)
	{
		env->r.start.y = y;
		x = 0;
		while (x < WIN_X)
		{
			env->r.start.x = x;
			normalize(&env->r.dir);
			reset_colour(&env->c, 0, 0, 0);
			cast_ray(env);
			save_pixel_to_image(env, win, x, y);
			x++;
		}
		y++;
	}
}
