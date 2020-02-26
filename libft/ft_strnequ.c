/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 03:23:14 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/25 20:01:28 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int x;

	if (s1 == NULL && s2 == NULL)
		return (1);
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	if (ft_strlen((char*)s1) != ft_strlen((char*)s2))
		return (0);
	x = 0;
	while (s1[x] && s2[x] && (size_t)x < n)
	{
		if (s1[x] != s2[x])
			return (0);
		x++;
	}
	return (1);
}
