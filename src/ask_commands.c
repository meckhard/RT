/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 14:42:07 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/08/12 16:45:35 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	instructions(void)
{
	ft_putstr("Please follow the instructions to get the desired output!\n");
	ft_putstr("Coordinates should be specified as such...\n");
	ft_putstr("Shape, centre coordinates(x, y, z), radius, height eg: sphere "
			"42 42 42 20 30\n\n");
	ft_putstr("Please enter the coordinates as specified for the "
			"specific shapes.\n\n");
	ft_putstr("For a sphere:		'sphere x y z radius'.\n");
	ft_putstr("For a cylinder:		'cylinder x y z radius height'.\n");
	ft_putstr("For a plane:		'plane x y angle'.\n");
	ft_putstr("For a cone:		'cone x y z radius height'.\n\n");
	ft_putstr("Insert finish to continue.\n\n");
}

int		get_commands(t_objects *ob)
{
	char				*line;
	static unsigned int	i;

	instructions();
	ob->commands = NULL;
	line = NULL;
	while (42)
	{
		get_line(0, &line);
		if (line != NULL)
		{
			if (ft_strcmp(line, "finish") == 0)
				break ;
			if (i + 1 % 10 == 0 || i == 0)
				ob->commands = re_3d_malloc(ob->commands, i);
			ob->commands[i] = check_commands(line);
			put_2d_array(ob->commands[i]);
			if (ob->commands[i] != NULL)
				i++;
		}
	}
	if (i > 0)
	{
		i = 0;
		return (1);
	}
	else
		ob->commands = NULL;
	return (0);
}

int		get_line(int fd, char **line)
{
	static unsigned int	k;
	char				buff;
	char				*l;

	l = NULL;
	read(fd, &buff, 1);
	while (buff != '\n' && buff != '\0')
	{
		if (k + 1 % 50 == 0 || k == 0)
			l = re_malloc(l, k);
		l[k] = buff;
		if (buff != 0)
			k++;
		read(fd, &buff, 1);
	}
	if (k + 1 % 50 == 0 || k == 0)
		l = re_malloc(l, k);
	l[k] = '\0';
	*line = l;
	if (k > 0)
	{
		k = 0;
		return (1);
	}
	else
		line = NULL;
	return (0);
}

char	**check_commands(char *line)
{
	char	**command;

	command = ft_strsplit(line, ' ');
	if (command[0] != NULL)
	{
		if (validate_shape(command[0]) == 0)
			command[0] = "non_valid";
		if (validate_coordinates(command, 
				validate_shape(command[0])) == 0)
			command[0] = "non_valid";
	}
	return (command);
}
