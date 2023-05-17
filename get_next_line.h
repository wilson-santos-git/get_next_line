/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:18:35 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/17 15:51:28 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define    GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_trim_str(char *str);
size_t	ft_strlen(const char *s);
int		ft_find_n(char *s, char c);
char	*ft_extract_str(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strlcpy(char *dst, const char *src, int size);
size_t	ft_spec_strcpy(char *dst, const char *src, int i);

#endif