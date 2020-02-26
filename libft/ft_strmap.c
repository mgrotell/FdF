/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 01:39:27 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/25 14:18:09 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		x;

	new = ft_strnew((size_t)ft_strlen(s));
	if (!new)
		return (NULL);
	x = 0;
	while (s[x])
	{
		new[x] = f(s[x]);
		x++;
	}
	new[x] = '\0';
	return (new);
}
