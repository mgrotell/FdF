/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:16:08 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/25 20:09:22 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*x;
	const unsigned char *y;

	if (!dst && !src)
		return (NULL);
	x = (unsigned char*)dst;
	y = (unsigned char*)src;
	while (n-- > 0)
	{
		*(x++) = *(y++);
	}
	return (dst);
}
