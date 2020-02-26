/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:43:32 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/25 19:04:42 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		get_size(unsigned int n)
{
	int x;

	x = 0;
	while (n >= 10)
	{
		n /= 10;
		x++;
	}
	return (x + 1);
}

char			*ft_itoa(int n)
{
	char			*r;
	unsigned int	nbr;
	unsigned int	size;
	unsigned int	where;

	nbr = 0;
	where = 0;
	if (n < 0)
		nbr = (unsigned int)(n * -1);
	else
		nbr = (unsigned int)n;
	size = (unsigned int)get_size(nbr);
	if (!(r = (char*)malloc(sizeof(char) * (size + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (r[where] = '-'))
		size++;
	where = size - 1;
	while (nbr >= 10)
	{
		r[where--] = (char)(nbr % 10 + 48);
		nbr /= 10;
	}
	r[where] = (char)(nbr % 10 + 48);
	r[size] = '\0';
	return (r);
}
