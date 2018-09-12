/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 12:08:35 by psaprono          #+#    #+#             */
/*   Updated: 2018/06/05 12:08:42 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

static double	ft_atof(char *s)
{
	double	i;
	int		a;
	int		l;

	i = ft_atoi(s);
	a = -1;
	l = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
	{
		l = *s == '-' && !i ? -1 : 1;
		s++;
	}
	while (ft_isdigit(*s))
		s++;
	if (*s == '.')
		s++;
	while (ft_isdigit(*s))
	{
		i += (*s - 48) * pow(10, a);
		s++;
		a--;
	}
	return (i * l);
}

t_vector		parse_vector(char *line)
{
	char	*find;

	if ((find = ft_strchr(line, ':')) == NULL)
		return ((t_vector){0, 0, 0});
	if ((*(find + 1) >= '0' && *(find + 1) <= '9') || *(find + 1) == '-')
		return (get_vector(find + 1));
	else
		return ((t_vector){0, 0, 0});
}

t_vector		get_vector(char *line)
{
	t_vector	v;
	char		*find;

	if ((find = ft_strchr(line, ',')) == NULL)
		return ((t_vector){0, 1, 0});
	v[0] = ft_atof(line);
	v[1] = ft_atof(find + 1);
	v[2] = ft_atof(ft_strrchr(line, ',') + 1);
	return (v);
}
