/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:26:31 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/25 18:58:28 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

char	*ft_extract_line(char *str, char *buff)
{
	int		i;
	int		j;	
	char	*s;

	i = 0;
	s = str;
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

size_t	ft_strcpy(char *line, char *aux)
{
	int	i;

	i = 0;
	while (aux[i])
	{
		line[i] = aux[i];
		i++;
	}
	return (i);
}
