/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 09:12:40 by meckhard          #+#    #+#             */
/*   Updated: 2016/08/12 09:11:48 by meckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	set_mat(t_mat *materials)
{
	materials[0].diffuse.red = 1;
	materials[0].diffuse.green = 0;
	materials[0].diffuse.blue = 0;
	materials[0].reflect = 0.2;
	materials[1].diffuse.red = 0;
	materials[1].diffuse.green = 1;
	materials[1].diffuse.blue = 0;
	materials[1].reflect = 0.5;
	materials[2].diffuse.red = 0;
	materials[2].diffuse.green = 0;
	materials[2].diffuse.blue = 1;
	materials[2].reflect = 0.9;
}

void	set_light(t_light *lights)
{
	lights[0].pos.x = 0;
	lights[0].pos.y = 240;
	lights[0].pos.z = -100;
	lights[0].intensity.red = 1;
	lights[0].intensity.green = 1;
	lights[0].intensity.blue = 1;
	lights[1].pos.x = 3200;
	lights[1].pos.y = 3000;
	lights[1].pos.z = -1000;
	lights[1].intensity.red = 0.6;
	lights[1].intensity.green = 0.7;
	lights[1].intensity.blue = 1;
	lights[2].pos.x = 600;
	lights[2].pos.y = 0;
	lights[2].pos.z = -100;
	lights[2].intensity.red = 0.3;
	lights[2].intensity.green = 0.5;
	lights[2].intensity.blue = 1;
}

void	set_sphere(t_sphere *spheres)
{
	spheres[0].shape.pos.x = 200;
	spheres[0].shape.pos.y = 300;
	spheres[0].shape.pos.z = 0;
	spheres[0].rad = 100;
	spheres[0].shape.material = 0;
	spheres[1].shape.pos.x = 400;
	spheres[1].shape.pos.y = 400;
	spheres[1].shape.pos.z = 0;
	spheres[1].rad = 100;
	spheres[1].shape.material = 1;
	spheres[2].shape.pos.x = 500;
	spheres[2].shape.pos.y = 140;
	spheres[2].shape.pos.z = 0;
	spheres[2].rad = 100;
	spheres[2].shape.material = 2;
}

void	reset_col(t_col *col)
{
	col->red = 0;
	col->green = 0;
	col->blue = 0;
}

void	get_input(t_env *env)
{
	set_mat(env->obj.materials);
	set_sphere(env->obj.spheres);
	set_light(env->obj.lights);
}
