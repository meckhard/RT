/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask_commands2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 13:53:35 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/08/12 16:48:37 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	instructions2(void)
{
	ft_putendl("\nNow the lighting effects need to be specified.");
	ft_putendl("Coordinates should be specified as such...");
	ft_putendl("Intensity of the light (r,g,b), Position of the light (x,y,z)");
	ft_putendl("(r,g,b) intensities must be between 0 and 255.");
	ft_putendl("eg: 255 255 255 x y z.\n");
	ft_putendl("Insert finish to continue.\n");
}

int		get_commands2(t_objects *ob)
{
	char			*line;
	unsigned int	i;

	i = 0;
	instructions2();
	ob->lighting = NULL;
	line = NULL;
	if (ob->commands != NULL)
	{
		while (42)
		{
			get_line(0, &line);
			if (line != NULL)
			{
				if (ft_strcmp(line, "finish") == 0)
					break;
				if (i + 1 % 10 == 0 || i == 0)
					ob->lighting = re_3d_malloc(ob->lighting, i);
				ob->lighting[i] = check_commands2(line);
				put_2d_array(ob->lighting[i]);
			}
			i++;
		}
	}
	else
		return (-1);
	return (0);
}

char	**check_commands2(char *line)
{
	char			**command;
	unsigned int	i;

	i = 0;
	command = ft_strsplit(line, ' ');
	if (validate_points(command, 7) == 0)
		command[0] = "non_valid";
	while (i < 3)
	{
		if (ft_atoi_shape(command[i]) < 255 || 
				ft_atoi_shape(command[i]) == -1)
		{
			command[0] = "non-valid";
			return (command);
		}
		i++;
	}
	return (command);
}
