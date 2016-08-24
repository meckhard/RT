#include "../includes/rtv1.h"

t_col	*get_colour_at(int x, int y)
{
}

void	ft_draw_img(void)
{
	unsigned int	x;
	unsigned int	y;
	t_col			*c;

	x = 0;
	while (x < WIN_X)
	{
		y = 0;
		while (y < WIN_Y)
		{
			c = get_colour_at(x, y);
			mlx_put_pixel_to_image(x, y, get_color_number())
			y++;
		}
		x++;
	}
}
