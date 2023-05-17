/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:18:27 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/17 16:21:41 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

char	*ft_read(int fd)
{
	ssize_t	ret;
	char	*buf;
	char	*save;
	char	*joint;
	
	ret = 1;
	joint = NULL;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		save = ft_strjoin(joint, buf);
		free(joint);
		joint = save;
		if (!joint)
			return (NULL);
		if (ft_find_n(joint, '\n'))
			break ;
	}
	free(buf);
	return (joint);
}

char	*ft_extract_str(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	if (!str)
		return (NULL);
	while (str && str[i] && str[i] != '\n')
		i++;
	dup = (char *)malloc((i + 2) * sizeof(char));
	if (!dup)
		return (NULL);
	return (ft_strlcpy(dup, str, i + 2));
}

char	*ft_trim_str(char *str)
{
	int	i;
	int	j;
	int	trimsize;
	char	*trim;

	i = 0;
	j = 0;
	trimsize = 0;
	if (!str)
		return (NULL);
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	trimsize = (ft_strlen(str)) - i;
	trim = (char *)malloc(trimsize + 1 * sizeof(char));
	if (!trim)
		return (NULL);
	while (str && str[i])
		trim[j++] = str[i++];
	trim[j] = '\0';
	return (trim);
}

char	*get_next_line(int fd)
{
	char		*p;
	char		*readptr;
	char		*finalreturn;
	static char	*mainsource[1024];

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	readptr = ft_read(fd);
	if (!readptr && !*mainsource)
		return (NULL);
	p = ft_strjoin(mainsource[fd], readptr);
	free(readptr);
	free(mainsource[fd]);
	mainsource[fd] = NULL;
	if (ft_strlen(p) == 0)
	{
		free(p);
		return (NULL);
	}
	mainsource[fd] = ft_trim_str(p);
	finalreturn = ft_extract_str(p);
	free(p);
	return (finalreturn);
}
