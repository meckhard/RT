#include "../includes/rtv1.h"

void	free_map(char ***temp)
{
	if (*temp != NULL)
	{
		free(*temp);
		*temp = NULL;
	}
}

void	free_mat(t_material *m)
{
	if (m != NULL)
	{
		free(m);
		m = NULL;
	}
}
