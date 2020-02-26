/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:41:50 by msiivone          #+#    #+#             */
/*   Updated: 2019/12/23 14:42:32 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		wa(const char *f, char c)
{
	int w;

	w = 0;
	if (*f != c && *f)
	{
		f++;
		w++;
	}
	while (*f)
	{
		while (*f == c)
		{
			f++;
			if (*f != c && *f)
				w++;
		}
		f++;
	}
	return (w);
}

static int		pt(const char *f, char c)
{
	int pt;

	pt = 0;
	while (*f != c && *f)
	{
		pt++;
		f++;
	}
	return (pt);
}

char			**ft_strsplit(char const *s, char c)
{
	int		x;
	int		y;
	char	**ret;

	x = 0;
	y = 0;
	if (!s || (!(ret = (char **)malloc(sizeof(char *) * (wa(s, c) + 1)))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(ret[x] = (char *)malloc(sizeof(char) * (pt(s, c) + 1))))
				return (NULL);
			while (*s && *s != c)
				ret[x][y++] = (char)*s++;
			ret[x][y] = '\0';
			x++;
			y = 0;
		}
	}
	ret[x] = NULL;
	return (ret);
}
