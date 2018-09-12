/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:56:09 by psaprono          #+#    #+#             */
/*   Updated: 2018/05/28 17:56:10 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	find_light(t_canv *cnv, t_mass *mas, t_clos clos)
{
	t_dot	k;
	t_list	*light;
	int		s;

	k[0] = 0;
	light = cnv->light;
	init_minmax(cnv, 0.001, 1.0);
	while (light)
	{
		mas->l = ((t_light *)(light->content))->pos - mas->p;
		if (find_clos(cnv, mas->p, mas->l).obj == NULL)
		{
			k[0] += find_diffuse(mas, ((t_light *)(light->content))->intns);
			if ((s = get_spec(clos.obj)) > 0)
				k[1] += find_spec(mas, ((t_light *)(light->content))->intns, s);
		}
		light = light->next;
	}
	return (get_color(find_fig_col(clos.obj), k));
}

double	find_spec(t_mass *mas, double intns, int spec)
{
	double	i;
	double	dot;

	mas->r = MULT(mas->n, 2 * DOT(mas->n, mas->l)) - mas->l;
	dot = DOT(mas->r, mas->v);
	i = 0.0;
	if (dot > 0)
		i += intns * pow(dot / (LEN(mas->r) * LEN(mas->v)), spec);
	return (i);
}

int		get_spec(t_list *obj)
{
	if (obj->content_size == PLANE)
		return (((t_plan *)(obj->content))->spec);
	else if (obj->content_size == SPHERE)
		return (((t_sphr *)(obj->content))->spec);
	else if (obj->content_size == CYLINDER)
		return (((t_cyl *)(obj->content))->spec);
	else if (obj->content_size == CONE)
		return (((t_cone *)(obj->content))->spec);
	return (-1);
}

double	find_diffuse(t_mass *mass, double ints)
{
	double	i;
	double	dot;

	i = 0;
	dot = DOT(mass->n, mass->l);
	if (dot > 0)
		i = ints * dot / (LEN(mass->n) * LEN(mass->l));
	return (i);
}

double	get_color(int color, t_dot k)
{
	t_col	col;

	col = conv_to_rgb(color);
	col.r += k[1] * 200;
	col.g += k[1] * 200;
	col.b += k[1] * 200;
	if ((col.r *= k[0]) > 255)
		col.r = 255;
	if ((col.g *= k[0]) > 255)
		col.g = 255;
	if ((col.b *= k[0]) > 255)
		col.b = 255;
	return (conv_to_dec(col));
}
