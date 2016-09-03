/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 12:28:09 by meckhard          #+#    #+#             */
/*   Updated: 2016/09/03 12:31:22 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	lambert_diffusion(t_intersect *sct, t_env *env, float t, t_vec *dist)
{
	t_ray	light_ray;
	float	lambert;

	light_ray.dir = vector_scale((1 / t), dist);
	lambert = vector_dot(&light_ray.dir, &sct->normal) * env->coef;
	env->c.r += lambert * env->l[2]->intensity.r * env->c.r;
	env->c.g += lambert * env->l[2]->intensity.g * env->c.g;
	env->c.b += lambert * env->l[2]->intensity.b * env->c.b;
}

void	light_point(t_intersect *sct, t_env *env)
{
	float	t;
	t_vec	dist;

	while (env->l[2])
	{
		dist = vector_sub(&env->l[2]->pos, &env->r.start);
		if (vector_dot(&sct->normal, &dist) <= 0.0f)
		{
			env->l[2] = env->l[2]->next;
			continue;
		}
		t = sqrtf(vector_dot(&dist, &dist));
		if (t <= 0.0f)
		{
			env->l[2] = env->l[2]->next;
			continue;
		}
		lambert_diffusion(sct, env, t, &dist);
		env->l[2] = env->l[2]->next;
	}
}

void	lighting(t_intersect *sct, t_env *env, float *reflect)
{
	float	refl_ray;
	t_vec	tmp;
//	t_ray	r;

//	reset_ray(r, &env->r);
	sct->norm_check = 1.0f / sqrtf(sct->norm_check);
	sct->normal = vector_scale(sct->norm_check, &sct->normal);
	light_point(sct, env);
	env->coef *= *reflect;
	refl_ray = 2.0f * vector_dot(&env->r.dir, &sct->normal);
	tmp = vector_scale(refl_ray, &sct->normal);
	env->r.dir = vector_sub(&env->r.dir, &tmp);
}

void	scale(t_vec *centre, t_env *env, float t)
{
	t_vec		scaled_hit;
	t_intersect	sct;

	scaled_hit = vector_scale(t, &env->r.dir);
	sct.intersect = vector_add(&env->r.start, &scaled_hit);
	sct.normal = vector_sub(&sct.intersect, centre);
	sct.norm_check = vector_dot(&sct.normal, &sct.normal);
}

void	reset_ray(t_ray *r, t_ray *env)
{
	r->start.x = env->start.x;
	r->start.y = env->start.y;
	r->start.z = env->start.z;
	r->dir.x = env->dir.x;
	r->dir.y = env->dir.y;
	r->dir.z = env->dir.z;
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
