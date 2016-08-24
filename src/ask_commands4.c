#include "../includes/rtv1.h"

void	ft_objects(t_objects *ob)
{
	ob->objects = (char ****)malloc(sizeof(char ***) * 2);
	ob->objects[0] = ob->commands;
	ob->objects[1] = ob->lighting;
}
