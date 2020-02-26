/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 02:09:44 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/23 23:14:45 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*x;
	unsigned int	y;

	x = ft_memalloc((size_t)ft_strlen((char*)s) + 1);
	if (!x || !s)
		return (NULL);
	y = 0;
	while (s[y])
	{
		x[y] = f(y, s[y]);
		y++;
	}
	return (x);
}
