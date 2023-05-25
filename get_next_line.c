/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:24:48 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/25 18:58:38 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t		i;
	ssize_t		ret;
	char		*str;
	static char	buf[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		i = 0;
		while (buf[i])
			buf[i++] = 0;
		return (NULL);
	}
	i = 1;
	ret = 1;
	str = NULL;
	while (i)
	{
		if (!buf[0])
			ret = read(fd, buf, BUFFER_SIZE);
		i = ft_find_n(buf) * ret > 0;
		if (ret > 0)
			str = ft_extract_line(str, buf);
		ft_update(buf);
	}
	return (str);
}
