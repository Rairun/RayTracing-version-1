/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:13:19 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/21 16:59:46 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_col	conv_to_rgb(int rgb)
{
	t_col	color;

	color.b = rgb & 255;
	color.g = (rgb >> 8) & 255;
	color.r = (rgb >> 16) & 255;
	return (color);
}

int		conv_to_dec(t_col color)
{
	int	res;

	res = ((int)color.r << 16) + ((int)color.g << 8) + (int)color.b;
	return (res);
}

int		conv_to_dec_p(t_vector color)
{
	int	res;

	res = ((int)color[0] << 16) + ((int)color[1] << 8) + (int)color[2];
	return (res);
}

int		find_fig_col(t_list *obj)
{
	if (obj->content_size == PLANE)
		return (((t_plan *)(obj->content))->col);
	else if (obj->content_size == SPHERE)
		return (((t_sphr *)(obj->content))->col);
	else if (obj->content_size == CYLINDER)
		return (((t_cyl *)(obj->content))->col);
	else if (obj->content_size == CONE)
		return (((t_cone *)(obj->content))->col);
	return (0xFFFFFF);
}
