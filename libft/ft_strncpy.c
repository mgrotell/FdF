/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 03:21:41 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/24 01:23:30 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t x;

	x = 0;
	while (x < len && src[x] != '\0')
	{
		dst[x] = src[x];
		++x;
	}
	if (x == len)
		return (dst);
	while (x < len)
	{
		dst[x] = '\0';
		x++;
	}
	return (dst);
}
