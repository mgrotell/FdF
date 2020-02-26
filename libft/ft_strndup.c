/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:16:21 by msiivone          #+#    #+#             */
/*   Updated: 2019/11/08 15:06:41 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*swp;
	size_t	x;

	x = 0;
	swp = ft_strnew(n);
	if (!swp)
		return (NULL);
	while (src[x] && x < n)
	{
		swp[x] = src[x];
		x++;
	}
	return (swp);
}
