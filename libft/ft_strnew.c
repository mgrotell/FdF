/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 00:57:23 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/26 17:02:50 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	x;

	x = 0;
	new = (char *)malloc(size + 1);
	if (!new)
		return (NULL);
	while (x <= size)
	{
		new[x] = '\0';
		x++;
	}
	return (new);
}
