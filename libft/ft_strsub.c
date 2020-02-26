/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 03:31:49 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/23 03:37:37 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *x;

	x = ft_memalloc(len + 1);
	if (!x || !s)
		return (NULL);
	x = ft_strncpy(x, (char*)s + start, len);
	return (x);
}
