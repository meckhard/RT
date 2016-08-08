/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_raytrace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 08:44:00 by meckhard          #+#    #+#             */
/*   Updated: 2016/08/08 11:38:06 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void sphere_raytrace(t_env *env)
{
	t_sphere    s;
	t_ray       r;
	int         x;
	int         y;
	int         hit;
	
	s.shape.pos.x = 400;
	s.shape.pos.y = 400;
	s.shape.pos.z = 400;
	s.rad = 200;
	r.dir.x = 0;
	r.dir.y = 0;
	r.dir.z = -2000;
	r.start.z = 0;
	x = 0;
	y = 0;
	while (y <= WIN_Y)
	{
		r.start.y = y;
		while (x <= WIN_X)
		{
			r.start.x = x;
			hit = raysphere(&r, &s);
			if (hit == 1)
			{
				env->img.data[(x + y*WIN_X)*4 + 0] = 255;
				env->img.data[(x + y*WIN_X)*4 + 1] = 0;
				env->img.data[(x + y*WIN_X)*4 + 2] = 0;
			}
			else
			{
				env->img.data[(x + y*WIN_X)*4 + 0] = 0;
				env->img.data[(x + y*WIN_X)*4 + 1] = 0;
				env->img.data[(x + y*WIN_X)*4 + 2] = 0;
			}
			x++;
		}
	y++;
	x = 0;
	}
}
