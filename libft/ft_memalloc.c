/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:41:35 by psaprono          #+#    #+#             */
/*   Updated: 2018/03/23 15:58:40 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	char	*str;
	size_t	i;

	if ((ptr = ((void *)malloc(sizeof(ptr) * size))) == NULL)
		return (NULL);
	str = (char *)ptr;
	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return (ptr);
}
