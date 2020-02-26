/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:58:10 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/26 15:09:53 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;
	unsigned char	*y;

	x = 0;
	y = (unsigned char*)s;
	while (++x <= n)
	{
		if (*(y++) == (unsigned char)c)
		{
			return ((void*)--y);
		}
	}
	return (0);
}
