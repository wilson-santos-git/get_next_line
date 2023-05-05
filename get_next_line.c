/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:18:27 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/05 19:03:57 by wteles-d         ###   ########.fr       */
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
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_read(int fd);
char	*ft_extract_str(char *str);
char	*ft_trim_str(char *str);

char	*get_next_line(int fd)
{
	static char	*mainsource;
	char		*p;
	char		*r;
	
	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	r = ft_read(fd);
	p = ft_strjoin(mainsource, r);
	free(r);
	if (ft_strlen(p) == 0)
		return (NULL);
	mainsource = ft_trim_str(p);
	return (ft_extract_str(p));
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
		joint = ft_strjoin(joint, buf);
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

char	*ft_extract_str(char *str)
{
	int	i = 0;
	char *dup;
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
	int i = 0;
	int j = 0;
	int	trimsize = 0;
	char *trim;
	if (!str)
		return (NULL);
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str)
		i++;
	trimsize = (ft_strlen(str)) - i;
	trim = (char *)malloc(trimsize + 1 * sizeof(char));
	if (!trim)
		return (NULL);
	while (str && str[i])
	{
		trim[j] = str[i];
		i++;
		j++;
	}
	trim[j] = '\0';
	return (trim);
}

int	main(void)
{
	int	fd = open("/nfs/homes/wteles-d/Wilson/get_next_line/testfd.txt", O_RDWR);
	char *p;
	
	printf("-> %s\n", p = get_next_line(fd));
	free(p);
	printf("-> %s\n", p = get_next_line(fd));
	free(p);
	printf("-> %s\n", p = get_next_line(fd));
	free(p);
	printf("-> %s\n", p = get_next_line(fd));
	free(p);
	printf("-> %s\n", p = get_next_line(fd));
	free(p);
	printf("-> %s\n", p = get_next_line(fd));
	free(p);
	printf("-> %s\n", p = get_next_line(fd));
	free(p);
	printf("-> %s\n", p = get_next_line(fd));
	free(p);
	printf("-> %s\n", p = get_next_line(fd));
	free(p);
	printf("-> %s\n", p = get_next_line(fd));
	free(p);
	printf("-> %s\n", p = get_next_line(fd));
	free(p);
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*p = 0;

	i = 0;
	p = (char *)calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (p == NULL)
		return (p);
	i = ft_spec_strcpy(p, s1, i);
	i = ft_spec_strcpy(p, s2, i);
	p[i] = '\0';
	free(s1);
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
