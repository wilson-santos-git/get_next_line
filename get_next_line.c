/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:18:27 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/09 18:34:28 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*ft_read(int fd)
{
	int		i ;
	int		ret;
	char	buf[BUFFER_SIZE + 1];
	char	*joint;
	char	*save;

	ret = 1;
	joint = NULL;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (NULL);
		buf[ret] = '\0';
		save = ft_strjoin(joint, buf);
		free(joint);
		joint = save;
		if (!joint)
			return (NULL);
		i = 0;
		while (joint[i])
			if (joint[i++] == '\n')
				return (joint);
	}
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
	int		i;
	int		j;
	int		trimsize;
	char	*trim;

	i = 0;
	j = 0;
	trimsize = 0;
	if (!str)
		return (NULL);
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str[i])
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
	static char	*mainsource;
	char		*p;
	char		*readptr;
	char		*finalreturn;

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	readptr = ft_read(fd);
	if (!readptr && !mainsource)
		return (NULL);
	p = ft_strjoin(mainsource, readptr);
	free(readptr);
	free(mainsource);
	mainsource = NULL;
	if (ft_strlen(p) == 0)
	{
		free(p);
		return (NULL);
	}
	mainsource = ft_trim_str(p);
	finalreturn = ft_extract_str(p);
	free(p);
	return (finalreturn);
}
