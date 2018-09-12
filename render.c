/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 14:02:53 by psaprono          #+#    #+#             */
/*   Updated: 2018/05/27 14:02:55 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	render(t_canv *cnv)
{
	t_vector	d;
	t_it		it;
	int			col;

	it.x = -WID / 2 - 1;
	while (++it.x <= WID / 2)
	{
		it.y = -HGT / 2 - 1;
		while (++it.y <= HGT / 2)
		{
			d = rotation(cnv->angles, cnv_to_view(it.x, it.y));
			col = trace_ray(cnv, cnv->cam, d);
			put_pix_to_img(cnv, WID / 2 + it.x, HGT / 2 - it.y, col);
		}
	}
	mlx_put_image_to_window(cnv->mlx, cnv->wnd, cnv->imp, 0, 0);
}

int		trace_ray(t_canv *cnv, t_vector o, t_vector d)
{
	t_clos	clos;
	t_mass	mass;

	init_minmax(cnv, 1.0, INF);
	if ((clos = find_clos(cnv, o, d)).obj == NULL)
		return (0);
	mass.p = o + MULT(d, clos.t);
	mass.o = o;
	mass.d = d;
	mass.v = -d;
	find_normal(&mass, &clos);
	return (find_light(cnv, &mass, clos));
}

t_clos	find_clos(t_canv *cnv, t_vector o, t_vector d)
{
	t_clos	clos;
	t_list	*obj;
	t_dot	inter;

	clos = init_clos(NULL, INF);
	obj = cnv->objs;
	while (obj)
	{
		inter = inter_ray_obj(o, d, obj);
		if (inter[0] >= cnv->min && inter[0] <= cnv->max && inter[0] < clos.t)
			clos = init_clos(obj, inter[0]);
		if (inter[1] >= cnv->min && inter[1] <= cnv->max && inter[1] < clos.t)
			clos = init_clos(obj, inter[1]);
		obj = obj->next;
	}
	return (clos);
}
