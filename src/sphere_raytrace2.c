/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_raytrace2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 12:28:09 by meckhard          #+#    #+#             */
/*   Updated: 2016/08/10 14:35:16 by meckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	save_col(t_env *env, t_col *col, int x, int y)
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
	env->img.data[(x + y * WIN_X) * 4 + 0] = (unsigned char)temp.red;
	env->img.data[(x + y * WIN_X) * 4 + 1] = (unsigned char)temp.green;
	env->img.data[(x + y * WIN_X) * 4 + 2] = (unsigned char)temp.blue;
}

void	light_ray(t_env *env, t_col *col, float t, t_vec *dist)
{
	t_ray	light_ray;
	float	lambert;

	light_ray.start = env->new_start;
	light_ray.dir = vector_scale((1 / t), dist);
	lambert = vector_dot(&light_ray.dir, &env->n) * env->coef;
	col->red += lambert * env->current_light.intensity.red
	* env->current_mat.diffuse.red;
	col->green += lambert * env->current_light.intensity.green
	* env->current_mat.diffuse.green;
	col->blue += lambert * env->current_light.intensity.blue
	* env->current_mat.diffuse.blue;
}

void	light_point(t_env *env, t_col *col)
{
	int		j;
	float	t;
	t_vec	dist;

	env->current_mat =
	env->materials[env->spheres[env->current_sphere].shape.material];
	j = 0;
	while (j < 3)
	{
		env->current_light = env->lights[j];
		dist = vector_sub(&env->current_light.pos, &env->new_start);
		if (vector_dot(&env->n, &dist) <= 0.0f)
		{
			j++;
			continue;
		}
		t = sqrtf(vector_dot(&dist, &dist));
		if (t <= 0.0f)
		{
			j++;
			continue;
		}
		light_ray(env, col, t, &dist);
		j++;
	}
}

void	linda(t_env *env, t_ray *r, t_col *col)
{
	float	reflect;
	t_vec	tmp;

	env->temp = 1.0f / sqrtf(env->temp);
	env->n = vector_scale(env->temp, &env->n);
	light_point(env, col);
	env->coef *= env->current_mat.reflect;
	r->start = env->new_start;
	reflect = 2.0f * vector_dot(&r->dir, &env->n);
	tmp = vector_scale(reflect, &env->n);
	r->dir = vector_sub(&r->dir, &tmp);
}

void	scale(t_env *env, t_ray *r, float t)
{
	t_vec	scaled;

	scaled = vector_scale(t, &r->dir);
	env->new_start = vector_add(&r->start, &scaled);
	env->n =
	vector_sub(&env->new_start, &env->spheres[env->current_sphere].shape.pos);
	env->temp = vector_dot(&env->n, &env->n);
}

void	main_sphere_loop(t_env *env, t_ray *r, t_col *col)
{
	int		i;
	float	t;

	env->coef = 1.0;
	get_input(env);
	while (env->coef > 0.0f)
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
}
