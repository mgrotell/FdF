/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:42:23 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/26 15:40:34 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				h;
	unsigned char		*x;
	const unsigned char	*y;

	if (!dst && !src)
		return (NULL);
	y = (unsigned char*)src;
	x = (unsigned char*)dst;
	h = 0;
	if (y < x)
	{
		while (++h <= len)
			x[len - h] = y[len - h];
	}
	else
	{
		while (len-- > 0)
		{
			*x = *y;
			x++;
			y++;
		}
	}
	return (dst);
}
