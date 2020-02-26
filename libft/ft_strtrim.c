/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 06:44:05 by msiivone          #+#    #+#             */
/*   Updated: 2019/12/19 06:48:51 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static int		count(char *c)
{
	int x;

	x = 0;
	while (c[x] != '\0')
		x++;
	return (x);
}

static int		blank(char *c)
{
	int x;

	x = 0;
	while (c[x] != '\0')
	{
		if (c[x] != ' ' && c[x] != '\n' && c[x] != '\t')
			return (0);
		x++;
	}
	return (1);
}

static int		true(char *c)
{
	int x;
	int y;

	y = 0;
	x = count(c);
	x--;
	if (c[0] == ' ' || c[0] == '\n' || c[0] == '\t')
		y++;
	if (c[x] == ' ' || c[x] == '\n' || c[x] == '\t')
		y++;
	if (y >= 1)
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*y;
	int		x;
	int		b;
	int		z;

	if (!s)
		return (NULL);
	if (blank((char*)s))
		return (ft_strnew(1));
	z = 0;
	b = 0;
	if (!true((char*)s))
		return ((char*)s);
	while (s[b] == ' ' || s[b] == '\n' || s[b] == '\t')
		b++;
	x = count((char*)s) - 1;
	while (s[x] == ' ' || s[x] == '\n' || s[x] == '\t')
		x--;
	x++;
	if (!(y = (char*)malloc((size_t)(x - b + 1))))
		return (NULL);
	while (s[b] && b < x)
		y[z++] = s[b++];
	y[z] = '\0';
	return (y);
}
