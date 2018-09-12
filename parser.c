/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:11:14 by psaprono          #+#    #+#             */
/*   Updated: 2018/06/04 11:11:17 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		check_arg(int argc, char **argv, int *fd)
{
	if (argc != 2)
	{
		ft_putendl("Usage: ./RTv1 <filename>");
		return (0);
	}
	else
	{
		if ((*fd = open(argv[1], O_RDONLY)) < 0)
		{
			ft_putstr("No file ");
			ft_putendl(argv[1]);
			return (0);
		}
	}
	return (1);
}

void	readfile(t_canv *cnv)
{
	int		res;
	char	*line;

	while ((res = get_next_line(cnv->fd, &line)) > 0)
	{
		find_inf(line, cnv);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (res == -1)
		ft_putendl("Error reading file");
}

void	find_inf(char *line, t_canv *cnv)
{
	if (ft_strnstr(line, "camera:", 7))
		cnv->cam = parse_vector(line);
	else if (ft_strnstr(line, "angles:", 7))
		cnv->angles = parse_vector(line);
	else if (ft_strnstr(line, "#plane", 6))
		parse_plane(cnv);
	else if (ft_strnstr(line, "#sphere", 7))
		parse_sphere(cnv);
	else if (ft_strnstr(line, "#cylinder", 9))
		parse_cylinder(cnv);
	else if (ft_strnstr(line, "#cone", 5))
		parse_cone(cnv);
	else if (ft_strnstr(line, "#light", 6))
		parse_light(cnv);
}
