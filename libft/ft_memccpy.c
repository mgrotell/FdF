/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:31:02 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/23 18:01:05 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			len;
	unsigned char	*x;
	unsigned char	*y;

	len = 0;
	x = (unsigned char*)dst;
	y = (unsigned char*)src;
	while (len < n)
	{
		x[len] = y[len];
		if (x[len] == (unsigned char)c)
		{
			return ((void*)(x + len + 1));
		}
		len++;
	}
	return (0);
}
