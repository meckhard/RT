#include "../includes/rtv1.h"

int		close_window(void)
{
	exit(0);
}

int		key_press(int keycode)
{
	if (keycode == 53)
	{
		exit(0);
	}
	return (0);
}
