/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:34:22 by msiivone          #+#    #+#             */
/*   Updated: 2019/10/24 01:30:27 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char *p;

	p = (0);
	while (*s)
	{
		if (*s == c)
			p = (char*)s;
		++s;
	}
	if (p)
		return (p);
	if (c == '\0')
		return ((char*)s);
	return (0);
}
