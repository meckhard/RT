/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 11:03:23 by meckhard          #+#    #+#             */
/*   Updated: 2016/08/11 14:59:47 by meckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	s_sphere(t_env *env, t_ray *light_ray, float t)
{
	int i;

	i = 0;
	while (i < env->obj.num_spheres)
	{
		if (raysphere(light_ray, &OBJ.spheres[i], &t))
			return (1);
		i++;
	}
	return (0);
}
