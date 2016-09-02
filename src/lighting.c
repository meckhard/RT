/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 12:28:09 by meckhard          #+#    #+#             */
/*   Updated: 2016/09/02 14:51:37 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*void	save_col(t_env *env, t_col *col, int x, int y)
{
	t_col temp;

	if (col->red * 255.0f < 255.0f)
		temp.red = col->red * 255.0f;
	else
		temp.red = 255.0f;
	if (col->green * 255.0f < 255.0f)
		temp.green = col->green * 255.0f;
	else
		temp.green = 255.0f;
	if (col->blue * 255.0f < 255.0f)
		temp.blue = col->blue * 255.0f;
	else
		temp.blue = 255.0f;
	env->img.data[(x + y * WIN_X) * 4 + 0] = (unsigned char)temp.r;
	env->img.data[(x + y * WIN_X) * 4 + 1] = (unsigned char)temp.g;
	env->img.data[(x + y * WIN_X) * 4 + 2] = (unsigned char)temp.b;
} */

void	light_ray(t_env *env, t_col *col, float t, t_vec *dist)
{
	t_ray	light_ray;
	float	lambert;

	light_ray.start = env->r.start;
	light_ray.dir = vector_scale((1 / t), dist);
	lambert = vector_dot(&light_ray.dir, &env->n) * env->coef;
	col->r += lambert * env->l[2]->intensity.r
	* env->s->sp[2]->m.diffuse.r;
	col->g += lambert * env->l[2]->intensity.g
	* env->s->sp[2]->m.diffuse.g;
	col->b += lambert * env->l[2]->intensity.b
	* env->s->sp[2]->m.diffuse.b;
}

void	light_point(t_env *env, t_col *col)
{
//	int		j;
	float	t;
	t_vec	dist;

//	env->s->sp[2]->m =
//	env->materials[env->s[env->current_sphere].shape.material];
//	j = 0;
	while (env->l[2])
	{
//		env->l[2] = env->lights[j];
		dist = vector_sub(&env->l[2]->pos, &env->r.start);
		if (vector_dot(&env->n, &dist) <= 0.0f)
		{
			env->l[2] = env->l[2]->next;
//			j++;
			continue;
		}
		t = sqrtf(vector_dot(&dist, &dist));
		if (t <= 0.0f)
		{
			env->l[2] = env->l[2]->next;
//			j++;
			continue;
		}
		light_ray(env, col, t, &dist);
		env->l[2] = env->l[2]->next;
//		j++;
	}
}

void	linda(t_env *env, t_ray *r, t_col *col)
{
	float	reflect;
//	float	temp;
	t_vec	tmp;

	temp = 1.0f / sqrtf(temp);
	env->n = vector_scale(temp, &env->n);
	light_point(env, col);
	env->coef *= env->s->sp[2]->m.reflect;
	r->start = env->r.start;
	reflect = 2.0f * vector_dot(&r->dir, &env->n);
	tmp = vector_scale(reflect, &env->n);
	r->dir = vector_sub(&r->dir, &tmp);
}

void	scale(t_env *env, t_ray *r, float t)
{
	t_vec	scaled;

	scaled = vector_scale(t, &r->dir);
	env->r.start = vector_add(&r->start, &scaled);
	env->n =
	vector_sub(&env->r.start, &env->s->sp[2]->centre);
	env->temp = vector_dot(&env->n, &env->n);
}

/*void	main_sphere_loop(t_env *env, t_ray *r, t_col *col)
{
	int		i;
	int		level;
	float	t;

	env->coef = 1.0;
	level = 0;
	get_input(env);
	while ((env->coef > 0.0f) && (level < 15))
	{
		t = 20000.0f;
		env->current_sphere = -1;
		i = 0;
		while (i < 3)
		{
			if (raysphere(r, &env->spheres[i], &t))
				env->current_sphere = i;
			i++;
		}
		if (env->current_sphere == -1)
			break ;
		scale(env, r, t);
		if (env->temp == 0)
			break ;
		linda(env, r, col);
	}
}*/
