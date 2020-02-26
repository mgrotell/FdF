/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:25:06 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/24 18:34:01 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int x;

	x = 0;
	if (n == 0)
		return (0);
	while (s1[x] && s2[x] && s1[x] == s2[x] && (size_t)x < n - 1)
		++x;
	return ((unsigned char)s1[x] - ((unsigned char)s2[x]));
}
