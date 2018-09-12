/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:30:25 by psaprono          #+#    #+#             */
/*   Updated: 2018/05/29 15:30:28 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	find_normal(t_mass *mass, t_clos *clos)
{
	if (clos->obj->content_size == PLANE)
		norm_plane(mass, (t_plan *)(clos->obj->content));
	else if (clos->obj->content_size == SPHERE)
		norm_sphr(mass, (t_sphr *)(clos->obj->content));
	else if (clos->obj->content_size == CYLINDER)
		norm_cyl(mass, clos->t, (t_cyl *)(clos->obj->content));
	else if (clos->obj->content_size == CONE)
		norm_cone(mass, clos->t, (t_cone *)(clos->obj->content));
}

void	norm_plane(t_mass *mass, t_plan *plan)
{
	if (DOT(mass->d, plan->v) < 0)
		mass->n = plan->v;
	else
		mass->n = -plan->v;
}

void	norm_sphr(t_mass *mass, t_sphr *sphr)
{
	t_vector	v;

	v = mass->p - sphr->c;
	mass->n = NORM(v, LEN(v));
}

void	norm_cyl(t_mass *mass, double t, t_cyl *cyl)
{
	double		m;
	t_vector	x;

	x = mass->o - cyl->c;
	m = DOT(mass->d, MULT(cyl->v, t)) + DOT(x, cyl->v);
	mass->n = mass->p - cyl->c - MULT(cyl->v, m);
	mass->n = NORM(mass->n, LEN(mass->n));
}

void	norm_cone(t_mass *mass, double t, t_cone *cone)
{
	double		m;
	t_vector	x;

	x = mass->o - cone->c;
	t_vector pc = mass->p - cone->c;
	m = DOT(mass->d, MULT(cone->v, t)) + DOT(x, cone->v);
	mass->n = mass->p - cone->c - MULT(cone->v, m + cone->k);
	mass->n = NORM(mass->n, LEN(mass->n));
}
