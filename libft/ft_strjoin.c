/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 03:38:02 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/25 14:27:49 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*x;
	size_t	y;

	y = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		y += (size_t)ft_strlen((char*)s1);
	if (s2)
		y += (size_t)ft_strlen((char*)s2);
	x = ft_memalloc(y + 1);
	if (!x)
		return (NULL);
	if (s1)
		x = ft_strcpy(x, (char*)s1);
	else
		x = ft_strcpy(x, (char*)s2);
	if (s1 && s2)
		x = ft_strcat(x, (char*)s2);
	return (x);
}
