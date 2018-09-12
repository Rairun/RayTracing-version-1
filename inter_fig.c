/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_fig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:00:20 by psaprono          #+#    #+#             */
/*   Updated: 2018/05/30 12:00:26 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_dot	inter_ray_obj(t_vector o, t_vector d, t_list *obj)
{
	if (obj->content_size == PLANE)
		return (inter_plane(o, d, (t_plan *)(obj->content)));
	else if (obj->content_size == SPHERE)
		return (inter_sphere(o, d, (t_sphr *)(obj->content)));
	else if (obj->content_size == CYLINDER)
		return (inter_cyl(o, d, (t_cyl *)(obj->content)));
	else if (obj->content_size == CONE)
		return (inter_cone(o, d, (t_cone *)(obj->content)));
	return (((t_dot){INF, INF}));
}

t_dot	inter_plane(t_vector o, t_vector d, t_plan *plan)
{
	t_dot		inter;
	t_vector	x;
	t_dot		k;

	inter = (t_dot){INF, INF};
	if ((k[0] = DOT(d, plan->v)) == 0)
		return (inter);
	x = plan->c - o;
	k[1] = DOT(x, plan->v);
	inter[0] = k[1] / k[0];
	// Для круга
	// t_vector p = o + MULT(d, inter[0]);
	// t_vector v = p - plan->c;
	// double d2 = DOT(v,v);
	// if (d2 >= 25)
	// 	inter[0] = INF;
	//
	return (inter);
}

t_dot	inter_sphere(t_vector o, t_vector d, t_sphr *sphr)
{
	t_dot		inter;
	t_vector	x;
	t_vector	k;
	double		discr;

	inter = (t_dot){INF, INF};
	x = o - sphr->c;
	k[0] = DOT(d, d);
	k[1] = 2 * DOT(x, d);
	k[2] = DOT(x, x) - sphr->rad * sphr->rad;
	discr = k[1] * k[1] - 4 * k[0] * k[2];
	if (discr < 0)
		return (inter);
	inter[0] = (-k[1] + sqrt(discr)) / (2 * k[0]);
	inter[1] = (-k[1] - sqrt(discr)) / (2 * k[0]);
	return (inter);
}

t_dot	inter_cyl(t_vector o, t_vector d, t_cyl *cyl)
{
	t_dot		inter;
	t_vector	x;
	t_vector	k;
	double		discr;

	inter = (t_dot){INF, INF};
	x = o - cyl->c;
	k[0] = DOT(d, d) - DOT(d, cyl->v) * DOT(d, cyl->v);
	k[1] = 2 * ((DOT(d, x) - DOT(d, cyl->v) * DOT(x, cyl->v)));
	k[2] = DOT(x, x) - DOT(x, cyl->v) * DOT(x, cyl->v) - cyl->rad * cyl->rad;
	discr = k[1] * k[1] - 4 * k[0] * k[2];
	if (discr < 0)
		return (inter);
	inter[0] = (-k[1] + sqrt(discr)) / (2 * k[0]);
	inter[1] = (-k[1] - sqrt(discr)) / (2 * k[0]);
	return (inter);
}

t_dot	inter_cone(t_vector o, t_vector d, t_cone *cone)
{
	t_dot		inter;
	t_vector	x;
	t_vector	k;
	double		discr;

	inter = (t_dot){INF, INF};
	x = o - cone->c;
	k[0] = DOT(d, d) - DOT(d, cone->v) * DOT(d, cone->v);
	k[1] = 2 * (DOT(d, x) - DOT(d, cone->v) * (DOT(x, cone->v) + 2 * cone->k));
	k[2] = DOT(x, x) - DOT(x, cone->v) * (DOT(x, cone->v) + 4 * cone->k);
	discr = k[1] * k[1] - 4 * k[0] * k[2];
	if (discr < 0)
		return (inter);
	inter[0] = (-k[1] + sqrt(discr)) / (2 * k[0]);
	inter[1] = (-k[1] - sqrt(discr)) / (2 * k[0]);
	return (inter);
}
