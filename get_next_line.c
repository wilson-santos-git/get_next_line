/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:18:27 by wteles-d          #+#    #+#             */
/*   Updated: 2023/04/28 19:49:16 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// if buffer 42 read 42 and save in calloc str
// if while read 42 not \n read 42 again (LOOP)
// if find \n while in middle of read 42 cut str and save rest in another str
// after find of \n strjoin all strings behind and return them as one str

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	ft_spec_strcpy(char *dst, const char *src, int i);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

char *get_next_line(int fd)
{
	int	i = 0;
	int	n = 82746;
	char *p = 0;
	char *savep = 0;
	char *currentjoin = 0;
	
	p = calloc(n, sizeof(char));
	if (!p)
		return (0);
	savep = calloc(n , sizeof(char));
	if (!savep)
		return (0);
	currentjoin = calloc(n, sizeof(char));
	if (!currentjoin)
		return (0);
	read(fd, p, n);
	currentjoin = ft_strjoin(ft_strlcpy(savep, p, n + 1), currentjoin);
	while (i <= n && p[i] != '\n')
	{
		if (i == n)
		{
			savep = ft_strlcpy(savep, p, n + 1);
			free(p);
			p = calloc(n, sizeof(char));
			if (!p)
				return (0);
			read(fd, p, n);
			i = 0;
			currentjoin = ft_strjoin(currentjoin, ft_strlcpy(savep, p, n + 1));
			while (currentjoin[i])
			{
				i++;
				if (currentjoin[i] == '\n')
					currentjoin[i + 1] = '\0';
			}
			i = 0;
		}
		i++;
		if (p[i] == '\n')
		{
			p[i + 1] = '\0';
		}
	}
	return (currentjoin);
}

int	main(void)
{
	int	fd = open("/nfs/homes/wteles-d/Wilson/get_next_line/testfd.txt", O_RDWR);
	printf("FINAL RETURN 1 -> %s\n",get_next_line(fd));
}

int	ft_spec_strcpy(char *dst, const char *src, int i)
{
	size_t	j;

	j = 0;
	while (src[j] != '\0')
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
	if (!s1 || !s2)
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
	while (s[i])
			i++;
	return (i);
}
