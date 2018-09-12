/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 11:58:38 by psaprono          #+#    #+#             */
/*   Updated: 2018/05/27 11:58:55 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include "get_next_line.h"
# define WID 1000
# define HGT 1000
# define D 1.0
# define INF 10000000000.0
# define PLANE 0
# define SPHERE 1
# define CYLINDER 2
# define CONE 3
# define POINT 1
# define DOT(v1, v2) (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2])
# define LEN(v) (sqrt(DOT(v, v)))
# define NORM(v, n) (v / (t_vector){n, n, n})
# define MULT(v, n) (v * (t_vector){n, n, n})

typedef double	t_vector __attribute__((vector_size(sizeof(double)*3)));
typedef double	t_angles __attribute__((vector_size(sizeof(double)*3)));
typedef double	t_dot __attribute__((vector_size(sizeof(double)*2)));

typedef struct	s_it
{
	int			x;
	int			y;
}				t_it;

typedef struct	s_col
{
	double		r;
	double		g;
	double		b;
}				t_col;

typedef struct	s_light
{
	double		intns;
	t_vector	pos;
}				t_light;

typedef struct	s_clos
{
	t_list		*obj;
	double		t;
}				t_clos;

typedef struct	s_plan
{
	int			col;
	double		spec;
	t_vector	v;
	t_vector	c;
}				t_plan;

typedef struct	s_sphr
{
	int			col;
	double		spec;
	double		rad;
	t_vector	c;
}				t_sphr;

typedef struct	s_cyl
{
	int			col;
	double		spec;
	double		rad;
	t_vector	v;
	t_vector	c;
}				t_cyl;

typedef struct	s_cone
{
	int			col;
	double		spec;
	double		k;
	t_vector	v;
	t_vector	c;
}				t_cone;

typedef struct	s_objs
{
	t_sphr		*sphr;
	t_plan		*plan;
	t_cyl		*cyl;
	t_cone		*cone;
}				t_objs;

typedef struct	s_mass
{
	t_vector	o;
	t_vector	d;
	t_vector	p;
	t_vector	n;
	t_vector	v;
	t_vector	l;
	t_vector	r;
}				t_mass;

typedef struct	s_canv
{
	void		*mlx;
	void		*wnd;
	void		*imp;
	char		*ims;
	int			fd;
	double		min;
	double		max;
	t_vector	cam;
	t_angles	angles;
	t_list		*objs;
	t_list		*light;
}				t_canv;

void			init_binds(t_canv *cnv);
int				exit_press(void);
int				choice(int k);

void			put_pix_to_img(t_canv *c, int x, int y, int color);
t_vector		cnv_to_view(int x, int y);
t_vector		rotation(t_angles a, t_vector v);

void			init_cnv(t_canv *cnv);
void			init_binds(t_canv *cnv);
t_clos			init_clos(t_list *obj, double t);
void			init_minmax(t_canv *cnv, double min, double max);

void			render(t_canv *cnv);
int				trace_ray(t_canv *cnv, t_vector o, t_vector d);
int				find_fig_col(t_list *obj);
t_col			conv_to_rgb(int rgb);
int				conv_to_dec(t_col color);
int				conv_to_dec_p(t_vector color);
t_clos			find_clos(t_canv *cnv, t_vector o, t_vector d);

t_dot			inter_ray_obj(t_vector o, t_vector d, t_list *obj);
t_dot			inter_plane(t_vector o, t_vector d, t_plan *plan);
t_dot			inter_sphere(t_vector o, t_vector d, t_sphr *sphr);
t_dot			inter_cyl(t_vector o, t_vector d, t_cyl *cyl);
t_dot			inter_cone(t_vector o, t_vector d, t_cone *cone);

double			find_light(t_canv *cnv, t_mass *mass, t_clos clos);
double			find_diffuse(t_mass *mass, double ints);
double			get_color(int color, t_dot k);

void			find_normal(t_mass *mass, t_clos *clos);
void			norm_plane(t_mass *mass, t_plan *plan);
void			norm_sphr(t_mass *mass, t_sphr *sphr);
void			norm_cyl(t_mass *mass, double t, t_cyl *cyl);
void			norm_cone(t_mass *mass, double t, t_cone *cone);

int				get_spec(t_list *obj);
double			find_spec(t_mass *mass, double intns, int s);

double			ft_to_rad(double degr);
t_vector		to_rad(t_vector v);

int				check_arg(int argc, char **argv, int *fd);
void			readfile(t_canv *cnv);
void			find_inf(char *line, t_canv *cnv);
t_vector		parse_vector(char *line);
t_vector		get_vector(char *line);

void			parse_plane(t_canv *cnv);
void			parse_sphere(t_canv *cnv);
void			parse_cylinder(t_canv *cnv);
void			parse_cone(t_canv *cnv);
void			parse_light(t_canv *cnv);

int				get_col_p(int fd, int *col);
int				get_spec_p(int fd, double *spec);
int				get_rad_p(int fd, double *rad);
int				get_norm_p(int fd, t_vector *norm);
int				get_cntr_p(int fd, t_vector *c);
int				get_angle_p(int fd, double *angle);
int				get_ints_p(int fd, double *ints);
int				get_pos_p(int fd, t_vector *pos);

double			ft_atoid(char *str);

#endif
