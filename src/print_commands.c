#include "../includes/rtv1.h"

void	put_2d_array(char **array)
{
	unsigned int			j;

	j = 0;
	while (array[j] && array[j] != NULL)
	{
		ft_putstr(array[j]);
		j++;
	}
	ft_putchar('\n');
}
