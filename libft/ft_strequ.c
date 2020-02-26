/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 03:12:18 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/25 14:23:55 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	unsigned int x;

	if (s1 == NULL && s2 == NULL)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	x = 0;
	while (s1[x] && s2[x])
	{
		if (s1[x] != s2[x])
			return (0);
		x++;
	}
	if (ft_strlen((char*)s1) == ft_strlen((char*)s2))
		return (1);
	if (s1[x] == '\0' && s2[x] == '\0')
		return (1);
	return (0);
}
