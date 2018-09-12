/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_fig1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:11:51 by psaprono          #+#    #+#             */
/*   Updated: 2018/06/06 12:11:55 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_cntr_p(int fd, t_vector *c)
{
	char	*find;
	int		res;

	if ((res = get_next_line(fd, &find)) <= 0
		|| ft_strnstr(find, "center:", 8) == NULL)
	{
		if (res >= 0)
			ft_strdel(&find);
		return (0);
	}
	*c = parse_vector(find);
	ft_strdel(&find);
	return (1);
}

int		get_angle_p(int fd, double *angle)
{
	char	*find;
	char	*find1;
	int		res;

	if ((res = get_next_line(fd, &find)) <= 0
		|| ft_strnstr(find, "angle:", 8) == NULL)
	{
		if (res >= 0)
			ft_strdel(&find);
		return (0);
	}
	find1 = ft_strrchr(find, ':');
	*angle = tan(ft_to_rad((double)ft_atoi(find1 + 1) / 2.0));
	ft_strdel(&find);
	return (1);
}

int		get_ints_p(int fd, double *ints)
{
	char	*find;
	char	*find1;
	int		res;

	if ((res = get_next_line(fd, &find)) <= 0 ||
		ft_strnstr(find, "intense:", 10) == NULL)
	{
		if (res >= 0)
			ft_strdel(&find);
		return (0);
	}
	find1 = ft_strrchr(find, ':');
	*ints = ft_atoi(find1 + 1) / 10.0;
	ft_strdel(&find);
	return (1);
}

int		get_pos_p(int fd, t_vector *pos)
{
	char	*find;
	int		res;

	if ((res = get_next_line(fd, &find)) == 0
		|| ft_strnstr(find, "position:", 10) == NULL)
	{
		if (res >= 0)
			ft_strdel(&find);
		return (0);
	}
	*pos = parse_vector(find);
	ft_strdel(&find);
	return (1);
}
