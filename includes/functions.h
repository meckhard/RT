#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "rtv1.h"
# include "structs.h"


int				raysphere(t_sphere *sphere, float *t);
//void			set_mat(t_mat *materials);
void			set_light(t_light *lights);
void			set_sphere(t_sphere *spheres);
void			reset_col(t_col *col);
void			get_input(t_env *env);
//int				cheak_shaddow(env, t, dist, &light_ray);

/*
 * main.c
 */

void			sphere_raytrace(t_env *env, t_win *win);	
void			reset_col(t_col *col);

/*
 * linda.c
 */

void			save_col(t_win *win, t_col *col, int x, int y);
void			light_ray(t_env *env, t_col *col, float t, t_vec *dist);
void			light_point(t_env *env, t_col *col);
void			linda(t_env *env, t_col *col);
void			scale(t_env *env, float t);
void			main_sphere_loop(t_env *env, t_col *col);

/*
 * vector_functions.c
 */
 

/*
 * vector_functions.c
 */

t_vec			vector_scale(float c, t_vec *v);
t_vec			vector_add(t_vec *v1, t_vec *v2);
t_vec			vector_sub(t_vec *v1, t_vec *v2);
//t_vec			new_vec(float x, float y, float z);
float			vector_dot(t_vec *v1, t_vec *v2);


/*
 * ft_sphere.c
 */

int				sphere_intersect(t_env *env, float *t);

/*
 * ray_tracer.c
 */

//void			display_scene(void);
//void			ray_tracer(char *scene_file);
//void			init_scene(char *scene_file, t_env *env);

/*
 * set_window.c
 */

//t_win			*init_env(void);
//void			del_env(void);

/*
 * set_image.c
 */

//t_img			*init_img(void);
//void			del_img(t_img *img);

/*
 * draw.c
 */

//static void		mlx_endian(void *mlx, t_img *i, pixel, t_col *c);

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

/*
 * reverse_lists.c
 */

void			reverse_lists(t_env *env);
void			reverse_light(t_env *env);
void			reverse_sphere(t_env *env);
void			reverse_cylinder(t_env *env);

/*
 * object_lists.c
 */

void			light_list(const int fd, char *line, t_env *env);
void			sphere_list(const int fd, char *line, t_env *env);
void			cylinder_list(const int fd, char *line, t_env *env);

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

/*
 * ft_atoi_shape.c
 */

//int				ft_atoi_shape(const char *str);

/*
 * re_malloc.c
 */

//char			*re_malloc(char *line, size_t size);
//char			***re_3d_malloc(char ***arr, size_t size);

/*
 * ask_commands.c
 */

//void			intsructions(void);
//int				get_commands(t_objects *ob);
//int				get_line(int fd, char **line);
//char			**check_commands(char *line);

/*
 * ask_commands2.c
 */

//void			instructions2(void);
//int				get_commands2(t_objects *ob);
//char			**check_commands2(char *line);

/*
 * ask_commands4.c
 */

//void			ft_objects(t_objects *ob);

/*
 * validate_commands.c
 */

//int				validate_shape(char *shape);
//int				validate_coordinates(char **command, int shape);
//int				validate_points(char **command, unsigned int i);
//void			free_commands(t_objects *ob);

/*
 * print_commands.c
 */

//void			put_2d_array(char **array);

#endif
