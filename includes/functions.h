#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "rtv1.h"
# include "structs.h"

t_vec			vector_scale(float c, t_vec *v);
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

#endif
