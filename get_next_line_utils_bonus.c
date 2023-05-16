/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:18:19 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/16 16:02:17 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

size_t	ft_spec_strcpy(char *dst, const char *src, int i)
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
	int	i;
	char	*p;
	int	s1size;
	int	s2size;

	s1size = ft_strlen(s1);
	s2size = ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	i = 0;
	p = (char *)malloc((s1size + s2size + 1) * sizeof(char));
	if (p == NULL)
		return (p);
	i = ft_spec_strcpy(p, s1, i);
	i = ft_spec_strcpy(p, s2, i);
	p[i] = '\0';
	return (p);
}

char	*ft_strlcpy(char *dst, const char *src, int size)
{
	int	i;

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
