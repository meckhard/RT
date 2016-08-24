#include "../includes/rtv1.h"

int		close_window(void)
{
//	printf("BUTTON PRESS:	%d\n", );
	exit(0);
}

int		key_press(int keycode)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
