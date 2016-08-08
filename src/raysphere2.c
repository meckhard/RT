/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raysphere2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 11:48:29 by meckhard          #+#    #+#             */
/*   Updated: 2016/08/08 11:37:46 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int	raysphere(t_ray *ray, t_sphere *sphere, float *t)
{
	t_raysphere var;

	var.a = vector_dot(&ray->dir, &ray->dir);
	var.dist = vector_sub(&ray->start, &sphere->shape.pos);
	var.b = 2 * vector_dot(&ray->dir, &var.dist);
	var.c = vector_dot(&var.dist, &var.dist) - (sphere->rad * sphere->rad);
	var.discr = var.b * var.b - 4 * var.a * var.c;
	if (var.discr < 0)
		var.ret = 0;
	else
	{
		var.sqrtdiscr = sqrtf(var.discr);
		var.t0 = (-var.b + var.sqrtdiscr) / (2);
		var.t1 = (-var.b - var.sqrtdiscr) / (2);
		if (var.t0 > var.t1)
			var.t0 = var.t1;
		if ((var.t0 > 0.001f) && (var.t0 < *t))
		{
			*t = var.t0;
			var.ret = 1;
		}
		else
			var.ret = 0;
	}
	return (var.ret);
}
