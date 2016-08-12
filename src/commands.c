/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 09:30:50 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/08/12 13:04:33 by meckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	do_command(t_shapes *sh)
{
	t_cone		co;
	t_cylinder	c;
	t_sphere	s;
	t_plane		p;

	static unsigned int	i;

	while (sh->commands[i] && sh->commands[i] != NULL)
	{
		if (validate_shape(sh->commands[i][0]) == 1)
			ft_cone(sh->commands[i], &co);
		if (validate_shape(sh->commands[i][0]) == 2)
			ft_sphere(sh->commands[i], &s);
		if (validate_shape(sh->commands[i][0]) == 3)
			ft_plane(sh->commands[i], &p);	
		if (validate_shape(sh->commands[i][0]) == 4)
			ft_cylinder(sh->commands[i], &c);
		i++;
	}
}
