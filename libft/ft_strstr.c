/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 03:53:34 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/26 15:53:27 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int x;
	int y;

	x = 0;
	if (!*needle)
		return ((char *)haystack);
	if (!*haystack)
		return (NULL);
	x = 0;
	while (haystack[x] != '\0')
	{
		if (haystack[x] == needle[0])
		{
			y = 1;
			while (needle[x] != '\0' && haystack[x + y] != '\0' &&
					haystack[x + y] == needle[y])
				++y;
			if (needle[y] == '\0')
				return ((char*)&haystack[x]);
		}
		++x;
	}
	return (0);
}
