/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:25:15 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/22 12:26:02 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define    GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_find_n(char *str);
void	ft_update(char *buff);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
size_t	ft_strcpy(char *line, char *aux);
char	*ft_extract_line(char *str, char *buff);

#endif