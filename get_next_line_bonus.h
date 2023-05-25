/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:26:44 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/25 18:59:02 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define    GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_find_n(char *str);
void	ft_update(char *buff);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
size_t	ft_strcpy(char *line, char *aux);
char	*ft_extract_line(char *str, char *buff);

#endif