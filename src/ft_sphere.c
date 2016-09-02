/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 09:10:33 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/09/02 13:29:14 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		sphere_intersect(t_ray *r, t_sphere *sp, float *t)
{
	t_section		ts;
	t_vec			dist;
	float			t0;
	float			t1;

//	printf("hit2:	%f\n", *t);
	ts.a = vector_dot(&r->dir, &r->dir);
//	printf("ray:	%f	%f	%f\n", r->dir.x, r->dir.y, r->dir.z);
//	printf("ts.a:	%f\n", ts.a);
	dist = vector_sub(&r->start, &sp->centre);
	ts.b = 2 * vector_dot(&dist, &r->dir);
//	printf("ts.dist:	%f	%f	%f\n", ts.dist.x, ts.dist.y, ts.dist.z);
//	printf("ts.b = %f\n", ts.b);
	ts.c = vector_dot(&dist, &dist) - (sp->radius * sp->radius);
	ts.discr = ts.b * ts.b - (4 * ts.a * ts.c);
//	printf("ts.discr:	%f\n", ts.discr);
//	if (ts.discr < 0)
//		return (-1);
	if (ts.discr < 0 && ts.discr > -50000000)
		return (0);
	if (ts.discr < 0)
		return (-1);
	else
	{
		ts.sqrtdiscr = sqrtf(ts.discr);
		t0 = (-ts.b + ts.sqrtdiscr) / 2;
		t1 = (-ts.b - ts.sqrtdiscr) / 2;
		if (t1 > 0.001f && t1 > t0 && t1 < *t)
		{
			t0 = t1;
			printf("yes");
			return (0);
		}
		if (t0 > 0.001f && t0 < *t)
		{
			*t = t0;
			//printf("yes");
			return (1);
		}
		else
			return (0);
	}
}
