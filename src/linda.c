#include "../includes/rtv1.h"

void	save_col(t_win *win, t_col *col, int x, int y)
{
	t_col *temp;

	x = 0;
	y = 0;
//	win->img->data = NULL;
	temp = (t_col *)malloc(sizeof(t_col));
	if (col->r * 255.0f < 255.0f)
		temp->r = col->r * 255.0f;
	else
		temp->r = 255.0f;
	if (col->g * 255.0f < 255.0f)
		temp->g = col->g * 255.0f;
	else
		temp->g = 255.0f;
	if (col->b * 255.0f < 255.0f)
		temp->b = col->b * 255.0f;
	else
		temp->b = 255.0f;
	win->img->data[(x + y * WIN_X) * 4 + 0] = (unsigned char)temp->r;
	win->img->data[(x + y * WIN_X) * 4 + 1] = (unsigned char)temp->g;
	win->img->data[(x + y * WIN_X) * 4 + 2] = (unsigned char)temp->b;
}

void	light_ray(t_env *env, t_col *col, float t, t_vec *dist)
{
	t_ray	light_ray;
	float	lambert;

	light_ray.start = env->r->new_start;
	printf("new_start:	%f\n", env->r->new_start.x);
	light_ray.dir = vector_scale((1 / t), dist);
	lambert = vector_dot(&light_ray.dir, &env->normal) * env->coef;
	col->r += lambert * env->l[0]->intensity.r * env->s->sp[0]->m.diffuse.r;
//	printf("red:	%f\n",env->s->sp[0]->m.diffuse.r);
	col->g += lambert * env->l[0]->intensity.g * env->s->sp[0]->m.diffuse.g;
	col->b += lambert * env->l[0]->intensity.b * env->s->sp[0]->m.diffuse.b;
}

void	light_point(t_env *env, t_col *col)
{
	float			t;
	t_vec			dist;

	env->l[0] = env->l[2];
	while (env->l[0])
	{
		dist = vector_sub(&env->l[0]->pos, &env->r->new_start);
//		printf("new_start:	%f\n", env->r->new_start.x);
		if (vector_dot(&env->normal, &dist) <= 0.0f)
		{
			env->l[0] = env->l[0]->next;	
			continue;
		}
		t = sqrtf(vector_dot(&dist, &dist));
		if (t <= 0.0f)
		{
			env->l[0] = env->l[0]->next;
			continue;
		}
//		reset_col(col);
//		if (cheak_shaddow(env, t, dist, &light_ray) == 0)
		light_ray(env, col, t, &dist);
		env->l[0] = env->l[0]->next;
	}
}

void	linda(t_env *env, t_col *col)
{
	float	reflect;
	float	point;
	t_vec	tmp;

	point = vector_dot(&env->normal, &env->normal);
	point = 1.0f / sqrtf(point);
//	printf("point:	%f\n", point);
	env->normal = vector_scale(point, &env->normal);
	light_point(env, col);
//	reset_col(col);
	env->coef *= env->s->sp[0]->m.reflect;
//	printf("env->coef:	%f\n", env->coef);
	env->r->start = env->r->new_start;
	reflect = 2.0f * vector_dot(&env->r->dir, &env->normal);
	tmp = vector_scale(reflect, &env->normal);
	env->r->dir = vector_sub(&env->r->dir, &tmp);
}

void	scale(t_env *env, float t)
{
	t_vec	scaled;

	scaled = vector_scale(t, &env->r->dir);
	env->r->new_start = vector_add(&env->r->start, &scaled);
	env->normal = vector_sub(&env->r->new_start, &env->s->sp[1]->centre);
}

void	main_sphere_loop(t_env *env, t_col *col)
{
	float		t;

	env->s->sp[0] = env->s->sp[2];
//	printf("%f\n", env->r->start.y);
//	printf("%f\n", env->s->sp[0]->centre.x);
	env->coef = 1.0;
	while (env->coef > 0.0f)
	{
		t = 20000.0f;
		while (env->s->sp[0])
		{
			if (sphere_intersect(env, &t) == 1)
			{
//				env->s->sp[1] = env->s->sp[0];	
//				printf("%f\n", t);
				break ;
			}
			else
				env->s->sp[1] = env->s->sp[0];
//			printf("%f\n", env->s->sp[0]->centre.x);
			env->s->sp[0] = env->s->sp[0]->next;
		}
		scale(env, t);
		if (env->s->sp[0] == NULL)
			break ;
		if (vector_dot(&env->normal, &env->normal) == 0)
			break ;
		linda(env, col);
//		printf("t:	%f\n", t);
		break ;
	}
}
