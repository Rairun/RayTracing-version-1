/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 15:05:38 by psaprono          #+#    #+#             */
/*   Updated: 2018/05/27 15:05:41 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	cnv_to_view(int x, int y)
{
	return ((t_vector){x * D / WID, y * D / HGT, D});
}

t_vector	rotation(t_angles a, t_vector v)
{
	t_vector	t1;
	t_vector	t2;

	t1[0] = v[0];
	t1[1] = v[1] * cos(a[0]) - v[2] * sin(a[0]);
	t1[2] = v[1] * sin(a[0]) + v[2] * cos(a[0]);
	t2[0] = t1[2] * sin(a[1]) + t1[0] * cos(a[1]);
	t2[1] = t1[1];
	t2[2] = t1[2] * cos(a[1]) - t1[0] * sin(a[1]);
	v[0] = t2[0] * cos(a[2]) - t2[1] * sin(a[2]);
	v[1] = t2[0] * sin(a[2]) + t2[1] * cos(a[2]);
	v[2] = t2[2];
	return (v);
}

void		put_pix_to_img(t_canv *c, int x, int y, int color)
{
	if (x >= 0 && x < WID && y >= 0 && y < HGT)
		*(int *)(c->ims + ((x + y * WID) * 4)) = color;
}

double		ft_to_rad(double degr)
{
	return (M_PI * (double)degr / 180);
}

t_vector	to_rad(t_vector v)
{
	v[0] = ft_to_rad(v[0]);
	v[1] = ft_to_rad(v[1]);
	v[2] = ft_to_rad(v[2]);
	return (v);
}
