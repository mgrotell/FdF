/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 00:47:23 by msiivone          #+#    #+#             */
/*   Updated: 2019/12/19 07:01:44 by msiivone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

t_list	*ft_check(int fd, t_list **ret)
{
	t_list	*swp;

	if (fd > 10240 || BUFF_SIZE < 1)
		return (NULL);
	if (!ret)
		return (NULL);
	swp = *ret;
	while (swp)
	{
		if ((int)swp->content_size == fd)
			return (swp);
		swp = swp->next;
	}
	swp = ft_lstnew("", fd);
	ft_lstadd(ret, swp);
	return (swp);
}

int		ft_read(int fd, char **k)
{
	char	buffer[BUFF_SIZE + 1];
	int		size;
	char	*swp;

	if (fd > 10240 || BUFF_SIZE < 1)
		return (-1);
	while (((size = read(fd, buffer, BUFF_SIZE)) > 0))
	{
		buffer[size] = '\0';
		swp = *k;
		*k = ft_strjoin(*k, buffer);
		if (!k)
			return (-1);
		free(swp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (size);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*ret;
	t_list			*swp;
	int				size;
	char			*swpk;

	if (fd < 0 || !line || !(swp = ft_check(fd, &ret)) || fd > 10240)
		return (-1);
	swpk = swp->content;
	if ((size = ft_read(fd, &swpk)) < 0)
		return (-1);
	swp->content = swpk;
	if (!size && !*swpk)
		return (0);
	size = ft_countend(swp->content);
	if (!(*line = ft_strndup(swp->content, (size_t)size)))
		return (0);
	swpk = swp->content;
	if (swpk[size] != '\0')
	{
		swp->content = ft_strdup(&((swp->content)[size + 1]));
		free(swpk);
		return (1);
	}
	swpk[0] = '\0';
	return (1);
}
