/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 00:36:16 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/24 03:32:15 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	unsigned char *x;

	x = 0;
	if (size > 0)
	{
		if (!(x = (unsigned char *)malloc(size)))
			return (NULL);
		while (size)
			x[--size] = 0;
	}
	return ((void *)x);
}
