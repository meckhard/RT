#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_vec
{
	float x;
	float y;
	float z;
}				t_vec;

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

typedef struct	s_shape
{
	t_sphere	*sp;
}				t_shape;

typedef struct	s_nodes
{
	t_light		l[3];
	t_sphere	sp[3];

	...'and other shapes nodes'
}				t_nodes;

typedef struct	s_env
{
	t_ray		r;
	t_light		*l;
	t_material	*m;
	t_shape		*s;
}				t_env;

#endif
