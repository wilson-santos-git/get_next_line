/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:26:57 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/25 18:56:44 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buf[1024][BUFFER_SIZE + 1];
	char		*str;
	size_t		ret;
	size_t		i;

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0 || fd >= 1024)
	{
		i = 0;
		while (fd >= 0 && fd < 1024 && buf[fd][i])
			buf[fd][i++] = 0;
		return (NULL);
	}
	str = NULL;
	i = 1;
	while (i)
	{
		ret = 1;
		if (!buf[fd][0])
			ret = read(fd, buf[fd], BUFFER_SIZE);
		i = ft_find_n(buf[fd]) * ret > 0;
		if (ret > 0)
			str = ft_extract_line(str, buf[fd]);
		ft_update(buf[fd]);
	}
	return (str);
}
