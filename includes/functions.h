#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "rtv1.h"
# include "structs.h"

/*
 * ray_trace.c
 */

void			ray_trace(t_env *env, t_win *win);
void			reset_colour(t_col *col, int r, int g, int b);
void			save_pixel_to_image(t_env *env, t_win *win, int x, int y);
void			cast_ray(t_env *env);

/*
 * loop_objects.c
 */

void			reset_centre(t_vec *centre, float x, float y, float z);
void			loop_spheres(t_env *env, t_sphere *sp, float *hit, float *temp);
void			loop_cylinders(t_env *env, t_cylinder *cy, float *hit, float *temp);
void			loop_planes(t_env *env, t_plane *p, float *hit, float *temp);
void			loop_cones(t_env *env, t_cone *co, float *hit, float *temp);

/*
 * lighting.c
 */

void			lambert_diffusion(t_intersect *sct, t_env *env, float t, t_vec *dist);
void			scale(t_vec *centre, t_env *env, float t);
void			lighting(t_intersect *sct, t_env *env, float *reflect);
void			light_point(t_intersect *sct, t_env *env);


/*
 * ft_sphere.c
 */

int				sphere_intersect(t_ray *r, t_sphere *sp, float *t);

/*
 * ft_cylinder.c
 */

int				cylinder_intersect(t_ray *r, t_cylinder *cyl, float *t);

/*
 * ft_plane.c
 */

int				plane_intersect(t_ray *r, t_plane *p, float *t);

/*
 * ft_cone.c
 */

int				cone_intersect(t_ray *r, t_cone *co, float *t);

/*
 * vector_functions.c
 */

t_vec			vector_scale(float c, t_vec *v);
t_vec			vector_add(t_vec *v1, t_vec *v2);
t_vec			vector_sub(t_vec *v1, t_vec *v2);
float			vector_dot(t_vec *v1, t_vec *v2);
t_vec			normalize(t_vec *v);

/*
 * key_hook.c
 */

int				key_press(int keycode);
int				close_window(void);

/*
 * read_map.c
 */

void			read_map(const int fd, t_env *env);
void			search_map(const int fd, char *line, t_env *env);
void			create_environment(t_env *env);
void			set_nodes(t_env *env);

/*
 * get_objects.c
 */

void			get_shape(const int fd, char *line, t_env *env);
void			get_camera(const int fd, char *line, t_env *env);
void			get_light(const int fd, char *line, t_light *l);
void			get_material(const int fd, char *line, t_material *m);
void			get_sphere(const int fd, char *line, t_sphere *sp);
void			get_cylinder(const int fd, char *line, t_cylinder *cy);
void			get_cone(const int fd, char *line, t_cone *co);
void			get_plane(const int fd, char *line, t_plane *p);

/*
 * reverse_lists.c
 */

void			reverse_lists(t_env *env);
void			reverse_light(t_env *env);
void			reverse_sphere(t_env *env);
void			reverse_cylinder(t_env *env);
void			reverse_cone(t_env *env);
void			reverse_plane(t_env *env);

/*
 * object_lists.c
 */

void			light_list(const int fd, char *line, t_env *env);
void			sphere_list(const int fd, char *line, t_env *env);
void			cylinder_list(const int fd, char *line, t_env *env);
void			cone_list(const int fd, char *line, t_env *env);
void			plane_list(const int fd, char *line, t_env *env);

/*
 * print_map.c
 */

void			print_nodes(t_env *env);
void			print_environment(t_env *env);

/*
 * free_map.c
 */

void			free_map(char ***temp);
void			free_mat(t_material *m);

#endif
