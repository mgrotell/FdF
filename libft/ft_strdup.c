/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 19:41:07 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/26 15:57:20 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*returnable;
	int		all;

	all = 0;
	returnable = (char *)malloc((size_t)ft_strlen((char*)src) + 1);
	if (returnable == NULL)
	{
		return (NULL);
	}
	while (src[all] != '\0')
	{
		returnable[all] = src[all];
		all++;
	}
	returnable[all] = '\0';
	return (returnable);
}
