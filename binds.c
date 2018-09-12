/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:23:45 by psaprono          #+#    #+#             */
/*   Updated: 2018/05/28 10:23:47 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_binds(t_canv *cnv)
{
	mlx_hook(cnv->wnd, 17, 1L << 17, exit_press, cnv);
	mlx_hook(cnv->wnd, 2, 5, choice, cnv);
}

int		exit_press(void)
{
	exit(1);
	return (1);
}

int		choice(int k)
{
	if (k == 53)
		exit(1);
	return (1);
}
