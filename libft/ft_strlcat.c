/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:16:22 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/23 23:34:15 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dsts;
	size_t	srcs;
	size_t	x;

	dsts = 0;
	srcs = 0;
	x = 0;
	while (dst[dsts] != '\0')
		dsts++;
	while (src[srcs] != '\0')
		srcs++;
	if (dstsize <= dsts)
		srcs += dstsize;
	else
		srcs += dsts;
	while (src[x] != '\0' && dsts + 1 < dstsize)
	{
		dst[dsts] = src[x];
		dsts++;
		x++;
	}
	dst[dsts] = '\0';
	return (srcs);
}
