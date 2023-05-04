/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:18:27 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/04 19:38:02 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// read until \n or EOF (read to char buff[BUFFSIZE + 1] & strjoin)
// #\n FOUND# extract/duplicate substring until \n to return THIS
// trim initial string until first \n and save it in a STATIC CHAR*

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int		ft_spec_strcpy(char *dst, const char *src, int i);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_read(int fd);

char	*get_next_line(int fd)
{
	//static char	*mainsource;
	char		*p;

	p = ft_read(fd);
	return (p);
}

char	*ft_read(int fd)
{
	int		i = 0;
	int		ret = 1;
	char	buf[BUFFER_SIZE + 1];
	char 	*joint = NULL;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		printf("%s\n", buf);
		joint = ft_strjoin(joint, buf);
		printf("%s\n", joint);
		i = 0;
		while (joint[i])
		{
			if (joint[i] == '\n')
			{
				return (joint);
			}
			i++;
		}
	}
	return (joint);
}

int	main(void)
{
	int	fd = open("/nfs/homes/wteles-d/Wilson/get_next_line/testfd.txt", O_RDWR);
	printf("FINAL RETURN 1 -> %s\n", get_next_line(fd));
}

int	ft_spec_strcpy(char *dst, const char *src, int i)
{
	size_t	j;

	j = 0;
	while (src && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*p;

	i = 0;
	if (!s2)
		return (NULL);
	p = (char *)calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (p == NULL)
		return (p);
	i = ft_spec_strcpy(p, s1, i);
	i = ft_spec_strcpy(p, s2, i);
	p[i] = '\0';
	return (p);
}

char	*ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (dst);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
			i++;
	return (i);
}
