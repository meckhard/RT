#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "rtv1.h"
# include "structs.h"

/*t_vec			vector_scale(float c, t_vec *v);
t_vec			vector_add(t_vec *v1, t_vec *v2);
void			sphere_raytrace(t_env *env);
t_vec			new_vec(float x, float y, float z);
t_vec			vector_sub(t_vec *v1, t_vec *v2);
float			vector_dot(t_vec *v1, t_vec *v2);
int				raysphere(t_ray *ray, t_sphere *sphere, float *t);
void			set_mat(t_mat *materials);
void			set_light(t_light *lights);
void			set_sphere(t_sphere *spheres);
void			reset_col(t_col *col);
void			get_input(t_env *env);
void			main_sphere_loop(t_env *env, t_ray *r, t_col *col);
void			save_col(t_env *env, t_col *col, int x, int y);
int				key_press(int keycode);
int				close_window(void);
//int				cheak_shaddow(env, t, dist, &light_ray);*/

/*
 *light_list_functions.c
 */

t_light			*ft_light_new(t_vec *pos, t_col *intensity);
void			ft_light_add(t_light **alst, t_light *new);

/*
 * read_map.c
 */

void			read_map(const int fd, t_env *env);
void			search_map(const int fd, char *line, t_env *env, t_light *a, t_light *b, t_sphere *d, t_sphere *e);
void			get_camera(const int fd, char *line, t_env *env);
void			get_light(const int fd, char *line, t_light *l);
void			get_material(const int fd, char *line, t_material *m);
void			get_sphere(const int fd, char *line, t_sphere *sp);
void			print_environment(t_env *env);
void			free_temp(char ***temp);
void			store_lights(const int fd, char *line, t_light *a, t_light *b);
void			store_spheres(const int fd, char *line, t_sphere *a, t_sphere *b);
void			reverse_lights(t_env *env, t_light *a, t_light *b, t_light *c);
void			reverse_spheres(t_env *env, t_sphere *a, t_sphere *b, t_sphere *c);
//void			reverse_lights(t_env *env, t_light *l);
//void			reverse_spheres(t_env *env, t_sphere *sp);

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
