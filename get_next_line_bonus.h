/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:18:35 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/22 12:01:51 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define    GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
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