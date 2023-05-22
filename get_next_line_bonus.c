/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:26:57 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/22 12:27:05 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

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
	static char	buf[1024][BUFFER_SIZE];
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
		if (!buf[fd][0])
			ret = read(fd, buf[fd], BUFFER_SIZE);
		i = ft_find_n(buf[fd]) * ret > 0;
		if (ret > 0)
			str = ft_extract_line(str, buf[fd]);
		ft_update(buf[fd]);
	}
	return (str);
}

int	main (void)
{ 
	int	fd1 = open("test1.txt", O_RDONLY);
	int	fd2 = open("test2.txt", O_RDONLY);
	int	fd3 = open("test3.txt", O_RDONLY);
	int	fd4 = open("test4.txt", O_RDONLY);
	int	fd5 = open("test5.txt", O_RDONLY);
	int	fd6 = open("test6.txt", O_RDONLY);
	printf("%s \n", get_next_line(fd1));
	printf("%s \n", get_next_line(fd4));
	printf("%s \n", get_next_line(fd3));
	printf("%s \n", get_next_line(fd6));
	printf("%s \n", get_next_line(fd2));
	printf("%s \n", get_next_line(fd3));
	printf("%s \n", get_next_line(fd1));
	printf("%s \n", get_next_line(fd1));
	printf("%s \n", get_next_line(fd4));
	printf("%s \n", get_next_line(fd5));
	printf("%s \n", get_next_line(fd3));
	printf("%s \n", get_next_line(fd6));
	printf("%s \n", get_next_line(fd6));
	printf("%s \n", get_next_line(fd2));
	printf("%s \n", get_next_line(fd1));
	printf("%s \n", get_next_line(fd3));
}