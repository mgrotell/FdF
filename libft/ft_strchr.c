/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 04:58:54 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/24 18:33:04 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *x;

	x = (char *)s;
	while (*x != c)
	{
		if (*x == '\0')
		{
			return (NULL);
		}
		x++;
	}
	return (x);
}
