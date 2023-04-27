/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:18:27 by wteles-d          #+#    #+#             */
/*   Updated: 2023/04/27 19:27:46 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(void)
{
	int	n = 100;
	int	fd = open("/nfs/homes/wteles-d/Wilson/get_next_line/testfd.txt", O_RDWR);
	char	*p;
	int i = 0;
	int	line = 3;
	int	cline = 1;
	int counth = 0;

	p = calloc(n, sizeof(char));
	if (!p)
		return (0);
	read(fd, p, n);
	while (i < n)
	{
		if (p[i] == '\n')
			{
				if (line == cline)
				{
					p[i + 1] = '\0';
					break;
				}
				cline++;
			}
		if (line == cline)
			counth++;
		i++;
	}
	printf("%s\n", p);
}
