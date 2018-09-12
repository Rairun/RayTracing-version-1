/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_fig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:50:21 by psaprono          #+#    #+#             */
/*   Updated: 2018/06/05 11:50:58 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_col_p(int fd, int *col)
{
	char	*find;
	int		res;

	if ((res = get_next_line(fd, &find)) <= 0
		|| ft_strnstr(find, "color:", 7) == NULL)
	{
		if (res >= 0)
			ft_strdel(&find);
		return (0);
	}
	*col = conv_to_dec_p(parse_vector(find));
	ft_strdel(&find);
	return (1);
}

int		get_spec_p(int fd, double *spec)
{
	char	*find;
	char	*find1;
	int		res;

	if ((res = get_next_line(fd, &find)) <= 0 ||
		ft_strnstr(find, "specular:", 10) == NULL)
	{
		if (res >= 0)
			ft_strdel(&find);
		return (0);
	}
	find1 = ft_strrchr(find, ':');
	*spec = ft_atoi(find1 + 1);
	ft_strdel(&find);
	return (1);
}

int		get_rad_p(int fd, double *rad)
{
	char	*find;
	char	*find1;
	int		res;

	if ((res = get_next_line(fd, &find)) <= 0
		|| ft_strnstr(find, "radius:", 8) == NULL)
	{
		if (res >= 0)
			ft_strdel(&find);
		return (0);
	}
	find1 = ft_strrchr(find, ':');
	*rad = ft_atoi(find1 + 1) / 10.0;
	ft_strdel(&find);
	return (1);
}

int		get_norm_p(int fd, t_vector *norm)
{
	char		*find;
	int			res;
	t_vector	v;
	double		len;

	if ((res = get_next_line(fd, &find)) <= 0
		|| ft_strnstr(find, "normal:", 8) == NULL)
	{
		if (res >= 0)
			ft_strdel(&find);
		return (0);
	}
	v = parse_vector(find);
	if ((len = LEN(v)) == 0.0)
		*norm = (t_vector){0, 1, 0};
	else
		*norm = NORM(v, len);
	ft_strdel(&find);
	return (1);
}
