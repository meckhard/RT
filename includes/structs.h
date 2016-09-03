#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_vec
{
	float x;
	float y;
	float z;
}				t_vec;

typedef struct	s_section
{
	float	a;
	float	b;
	float	c;
	float	discr;
	float	sqrtdiscr;
}				t_section;

typedef struct	s_ray
{
	t_vec	start;
	t_vec	dir;
}				t_ray;

typedef struct	s_col
{
	float	r;
	float	g;
	float	b;
}				t_col;

typedef struct	s_light
{
	t_vec			pos;
	t_col			intensity;
	struct s_light	*next;
}				t_light;

typedef struct	s_material
{
	t_col				diffuse;
	float				reflect;
	struct s_material	*next;
}				t_material;

typedef struct	s_sphere
{
	t_vec			centre;
	float			radius;
	t_material		m;
	struct s_sphere	*next;
}				t_sphere;

typedef struct	s_cylinder
{
	t_vec				centre;
	t_vec				normal;
	float				height;
	float				radius;
	t_material			m;
	struct s_cylinder	*next;
}				t_cylinder;

typedef struct	s_cone
{
	t_vec			centre;
	float			radius;
	float			height;
	t_material		m;
	struct s_cone	*next;
}				t_cone;

typedef struct	s_plane
{
	t_vec			centre;
	t_vec			normal;
	t_material		m;
	struct s_plane	*next;
}				t_plane;

typedef struct	s_shape
{
	t_sphere	*sp[3];
	t_cylinder	*cy[3];
	t_cone		*co[3];
	t_plane		*p[3];
}				t_shape;

typedef struct	s_current_ray
{
	float		index;
	t_sphere	sp;
	t_cylinder	cy;
	t_cone		co;
	t_plane		p;
	t_material	m;
}				t_current_ray;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_win
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_win;

typedef struct	s_intersect
{
	t_vec	normal;
	t_vec	intersect;
	float	norm_check;
}				t_intersect;

typedef struct	s_env
{
	float			coef;
	float			reflect;
	t_ray			r;
	t_col			c;
	t_light			*l[3];
	t_shape			s;
	t_vec			centre;
}				t_env;

#endif
