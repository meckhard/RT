#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_vec
{
	float x;
	float y;
	float z;
}				t_vec;

typedef struct  s_raysphere
{
	int		ret;
	float	a;
	float	b;
	float	c;
	float	discr;
	t_vec	dist;
	float	sqrtdiscr;
	float	t0;
	float	t1;
}				t_raysphere;

typedef struct	s_ray
{
	t_vec	start;
	t_vec	dir;
}				t_ray;

typedef struct	s_col
{
	float	red;
	float	green;
	float	blue;
}				t_col;

typedef struct	s_light
{
	t_vec	pos;
	t_col	intensity;
}				t_light;

typedef struct	s_mat
{
	t_col	diffuse;
	float	reflect;
}				t_mat;

typedef struct	s_shape
{
	t_vec	pos;
	int		material;
}				t_shape;

typedef struct	s_sphere
{
	t_shape	shape;
	float	rad;
	int		mat;
}				t_sphere;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			s;
	int			e;
	char		id;
	int			x;
	int			y;
}				t_img;

typedef struct	s_env
{
	t_mat		materials[3];
	t_sphere	spheres[3];
	t_light		lights[3];
	t_light		current_light;
	t_vec		new_start;
	t_mat		current_mat;
	int			current_sphere;
	float		coef;
	float		temp;
	t_vec		n;
	void		*mlx;
	void		*win;
	t_img		img;
}				t_env;

#endif
