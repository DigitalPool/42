/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 06:57:17 by ashobajo          #+#    #+#             */
/*   Updated: 2024/06/06 08:09:45 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static char *left_line;
	char		*line;
	char		*buffer;

	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (fd < 0 || BUFFER_SIZE < 1 || !buffer || read(fd, 0, 0) < 0)
	{
		free (left_line);
		free (buffer);
		left_line = NULL;
		buffer = NULL;
		return NULL;
	}
	line = fill_the_line(fd, left_line, buffer);
	free (buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	left_line = move_behind_line(line);
	return (line);
}
