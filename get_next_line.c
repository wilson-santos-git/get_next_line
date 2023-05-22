/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:18:27 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/22 11:59:14 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*ft_extract_line(char *str, char *buff)
{
	char	*s;
	int		i;
	int		j;	

	s = str;
	i = 0;
	str = malloc(sizeof(char) * ft_strlen(buff) + ft_strlen(str) + 1);
	if (!str)
		return (NULL);
	if (s)
		i = ft_strcpy(str, s);
	j = 0;
	while (buff[j])
	{
		str[i++] = buff[j];
		if (buff[j++] == '\n')
			break ;
	}
	str[i] = '\0';
	if (s)
		free(s);
	return (str);
}

int	ft_find_n(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	return (str[i] != '\n');
}

void	ft_update(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (buff[i])
	{
		if (j == -1 && buff[i] == '\n')
			j = 0;
		else if (j >= 0)
			buff[j++] = buff[i];
		buff[i++] = 0;
	}
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*str;
	size_t		ret;
	size_t		i;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	str = NULL;
	i = 1;
	while (i)
	{
		ret = 1;
		if (!buf[0])
			ret = read(fd, buf, BUFFER_SIZE);
		i = ft_find_n(buf) * ret > 0;
		if (ret > 0)
			str = ft_extract_line(str, buf);
		ft_update(buf);
	}
	return (str);
}

int	main (void)
{
 	int fd;
 	char *str;	 
	fd = open("test.txt", O_RDONLY);
 	while (1)
	{
		str = get_next_line(fd);
		printf("%s", str);
		if (!str)
			break ;
	}
}