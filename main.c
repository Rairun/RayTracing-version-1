/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 16:23:21 by psaprono          #+#    #+#             */
/*   Updated: 2018/05/27 16:23:24 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int argc, char **argv)
{
	t_canv	cnv;

	if (check_arg(argc, argv, &(cnv.fd)))
	{
		init_cnv(&cnv);
		readfile(&cnv);
		render(&cnv);
		mlx_loop(cnv.mlx);
	}
	return (0);
}
