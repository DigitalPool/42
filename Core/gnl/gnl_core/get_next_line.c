/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 06:57:17 by ashobajo          #+#    #+#             */
/*   Updated: 2024/06/06 10:36:19 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(char *s, int c);

char	*fill_the_line (int fd, char *left_line, char *buffer)
{
	ssize_t bytes_read;
	char *temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (left_line);
			return(NULL);
		}
		else if (bytes_read == 0)
			break;
		buffer[bytes_read] = 0;
		if (!left_line)
			left_line = ft_strdup("");
		temp = left_line;
		left_line = ft_strjoin(temp, buffer),
		free (temp);
		temp = NULL;
		if (ft_strchr(left_line, '\n'))
			break;
	}
return (left_line);
}

static char	*move_behind_line (char *line_buffer)
{
	char	*left_line;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return NULL;
	left_line = ft_substr (line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*left_line == 0)
	{
		free(left_line);
		left_line = NULL;
	}
	line_buffer[i + 1] = 0;
	return (left_line);
}

char	*get_next_line(int fd)
{
	static char *left_line;
	char		*line;
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (left_line);
		free (buffer);
		left_line = NULL;
		buffer = NULL;
		return NULL;
	}
	if (!buffer)
		return (NULL);
	line = fill_the_line(fd, left_line, buffer);
	free (buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	left_line = move_behind_line(line);
	return (line);
}

static char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}
