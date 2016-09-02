/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhamlyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 10:57:54 by lhamlyn           #+#    #+#             */
/*   Updated: 2016/09/02 16:37:25 by ehansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/rtv1.h"
#define		SQR(X) (X * X)

int		cylinder_intersect(t_ray *ray, t_cylinder *cyl, float *t)
{
//	ft_putendl(">>Enter cylinder_intersect");
	t_section 	rs;
	t_vec		dist;
	float		t0;
	float		t1;

	dist = vector_sub(&cyl->centre, &ray->start);
	rs.a = SQR(ray->dir.x) + SQR(ray->dir.z);
	rs.b = (2 * ray->dir.x * dist.x) + (2 * ray->dir.z * dist.z);
	rs.c = SQR(dist.x) + SQR(dist.z) - SQR(cyl->radius);
	rs.discr = SQR(rs.b) - (4 * rs.a * rs.c);
	if (rs.discr < 0)
	{
		//ft_putendl("<<Returning 0.0");//maybe discr not discrqrt
		return (0);
	}
	else
	{
		t0 = (-rs.b - sqrt(rs.discr)) / (2 * rs.a);
		t1 = (-rs.b + sqrt(rs.discr)) / (2 * rs.a);
		if (t0 > t1 && t1 > 0)
			t0 = t1;
		if ((t0 > 0.001) && (t0 < *t))
		{
			*t = t0;
			//ft_putendl("<<Returning 1");
			return (1);
		}
		else
		{
			//ft_putendl("<<Returning 0.1");
			return (0);
		}
	}
	//ft_putendl("<<Returning 0.2");
	return (0);
}
