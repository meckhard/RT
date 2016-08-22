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

typedef struct	s_shape
{
	t_sphere	*sp[3];
	t_cylinder	*cy[3];
	t_cone		*co[3];
//	t_pyramid	*pyramids;
//	t_cube		*cubes;
//	t_cone		*cones;
//	t_plane		*planes;
}				t_shape;

/*
typedef struct	s_objects
{
	char	****objects;
	char	***commands;
	char	***lighting;
	char	**colours;
}				t_objects;*/

/*typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct    s_obj
{
	t_material	materials[3];
	t_light		lights[3];
	t_sphere	spheres[3];
	int			num_mats;
	int			num_lights;
	int			num_spheres;
	int         current_sphere;
	t_material	current_mat;
	t_light		current_light;
	t_vec		n;
	t_vec		new_start;
}				t_obj;

typedef struct	s_win
{
	void	*mlx;
	void	*win;
	t_img	*img;
}				t_win;*/

typedef struct	s_env
{
	float		coef;
	t_ray		r;
	t_light		*l[3];
	t_shape		*s;
}				t_env;

#endif
