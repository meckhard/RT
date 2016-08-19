#include "../includes/rtv1.h"

int		validate_shape(char *shape)
{
	if (ft_strcmp(shape, "cone") == 0)
		return (1);
	if (ft_strcmp(shape, "sphere") == 0)
		return (2);
	if (ft_strcmp(shape, "plane") == 0)
		return (3);
	if (ft_strcmp(shape, "cylinder") == 0)
		return (4);
	else
	{
		ft_putstr(R_MESS11);
		return (0);
	}
}

int		validate_coordinates(char **command, int shape)
{	
	int		i;

	if (shape == 1)
		i = validate_points(command, 6);
	if (shape == 2)
		i = validate_points(command, 5);
	if (shape == 3)
		i = validate_points(command, 6);
	if (shape == 4)
		i = validate_points(command, 6);
	return (i);
}

int		validate_points(char **command, unsigned int i)
{
	unsigned int	j;

	j = 1;
	while (command[j] && (ft_strcmp(command[j], "\0") != 0)  && j < i)
	{
		if (ft_atoi_shape(command[j]) == -1)
		{
			ft_putstr(R_MESS07);
			return (0);
		}
		j++;
	}
	if (command[j] != NULL || j < i)
	{
		ft_putstr(R_MESS12);
		ft_putstr(R_MESS07);
		return (0);
	}
	return (1);
}

void	free_commands(t_objects *ob)
{
	if (ob->commands != NULL)
	{
		free(ob->commands);
		ob->commands = NULL;
	}
	if (ob->lighting != NULL)
	{
		free(ob->lighting);
		ob->lighting = NULL;
	}
	if (ob->colours != NULL)
	{
		free(ob->colours);
		ob->colours = NULL;
	}
}