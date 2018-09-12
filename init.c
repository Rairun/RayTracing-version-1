/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 13:18:45 by psaprono          #+#    #+#             */
/*   Updated: 2018/05/27 13:18:47 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		init_cnv(t_canv *cnv)
{
	int		a[3];

	a[0] = 32;
	cnv->mlx = mlx_init();
	cnv->wnd = mlx_new_window(cnv->mlx, WID, HGT, "RTv1");
	cnv->imp = mlx_new_image(cnv->mlx, WID, HGT);
	cnv->ims = mlx_get_data_addr(cnv->imp, &a[0], &a[1], &a[2]);
	cnv->objs = NULL;
	cnv->light = NULL;
	cnv->angles = to_rad((t_angles){0, 0, 0});
	cnv->cam = (t_vector){0, 0, 0};
	init_binds(cnv);
}

void		init_minmax(t_canv *cnv, double min, double max)
{
	cnv->min = min;
	cnv->max = max;
}

t_clos		init_clos(t_list *obj, double t)
{
	t_clos	clos;

	clos.obj = obj;
	clos.t = t;
	return (clos);
}
