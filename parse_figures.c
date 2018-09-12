/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:41:10 by psaprono          #+#    #+#             */
/*   Updated: 2018/06/06 11:41:13 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_plane(t_canv *cnv)
{
	t_plan	plan;
	t_list	*new;

	if (get_col_p(cnv->fd, &(plan.col)) && get_spec_p(cnv->fd, &(plan.spec))
		&& get_norm_p(cnv->fd, &(plan.v)) && get_cntr_p(cnv->fd, &(plan.c)))
	{
		if ((new = ft_lstnew(&plan, sizeof(plan))) == NULL)
			return ;
		new->content_size = PLANE;
		ft_lstadd(&(cnv->objs), new);
	}
	else
		ft_putendl("plane parse fail");
}

void	parse_sphere(t_canv *cnv)
{
	t_sphr	sphr;
	t_list	*new;

	if (get_col_p(cnv->fd, &(sphr.col)) && get_spec_p(cnv->fd, &(sphr.spec))
		&& get_rad_p(cnv->fd, &(sphr.rad)) && get_cntr_p(cnv->fd, &(sphr.c)))
	{
		if ((new = ft_lstnew(&sphr, sizeof(sphr))) == NULL)
			return ;
		new->content_size = SPHERE;
		ft_lstadd(&(cnv->objs), new);
	}
	else
		ft_putendl("sphere parse fail");
}

void	parse_cylinder(t_canv *cnv)
{
	t_cyl	cyl;
	t_list	*new;

	if (get_col_p(cnv->fd, &(cyl.col)) && get_spec_p(cnv->fd, &(cyl.spec))
		&& get_rad_p(cnv->fd, &(cyl.rad)) && get_norm_p(cnv->fd, &(cyl.v))
			&& get_cntr_p(cnv->fd, &(cyl.c)))
	{
		if ((new = ft_lstnew(&cyl, sizeof(cyl))) == NULL)
			return ;
		new->content_size = CYLINDER;
		ft_lstadd(&(cnv->objs), new);
	}
	else
		ft_putendl("cylinder parse fail");
}

void	parse_cone(t_canv *cnv)
{
	t_cone	cone;
	t_list	*new;

	if (get_col_p(cnv->fd, &(cone.col)) && get_spec_p(cnv->fd, &(cone.spec))
		&& get_angle_p(cnv->fd, &(cone.k)) && get_norm_p(cnv->fd, &(cone.v))
			&& get_cntr_p(cnv->fd, &(cone.c)))
	{
		if ((new = ft_lstnew(&cone, sizeof(cone))) == NULL)
			return ;
		new->content_size = CONE;
		ft_lstadd(&(cnv->objs), new);
	}
	else
		ft_putendl("cone parse fail");
}

void	parse_light(t_canv *cnv)
{
	t_light	light;
	t_list	*new;

	if (get_ints_p(cnv->fd, &(light.intns)) && get_pos_p(cnv->fd, &(light.pos)))
	{
		if ((new = ft_lstnew(&light, sizeof(light))) == NULL)
			return ;
		new->content_size = POINT;
		ft_lstadd(&(cnv->light), new);
	}
	else
		ft_putendl("light parse fail");
}
