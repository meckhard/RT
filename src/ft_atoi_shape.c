#include "../includes/rtv1.h"

static int		ft_atoi_m(const char *str, int nb, size_t cnt)
{
	while (str[cnt] != '\0')
	{
		if (str[cnt] >= 48 && str[cnt] <= 57)
		{
			nb = (nb * 10) + (str[cnt] - '0');
		}
		else
		{
			ft_putstr(E_MESS07);
			exit(EXIT_FAILURE);
		}
		cnt++;
	}
	if (nb > 2147483647 || nb < 0)
	{
		ft_putstr(E_MESS07);
		exit(EXIT_FAILURE);
	}
	return (nb);
}

int				ft_atoi_shape(const char *str)
{
	int		nb;
	int		check;
	size_t	cnt;

	nb = 0;
	cnt = 0;
	check = 0;
	if (str[cnt] == '-')
	{
		check = -1;
		cnt++;
	}
	if (str[cnt] == '+')
		cnt++;
	nb = ft_atoi_m(str, nb, cnt);
	if (check == -1)
		nb = nb * check;
	if (nb > WIN_Y || nb > WIN_X || nb < 0)
		return (-1);
	return (nb);
}
