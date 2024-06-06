/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:47:10 by aassaad-          #+#    #+#             */
/*   Updated: 2024/06/06 08:09:39 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (i);
		i++;
	}
	return (i);
}

char	*fill_the_line (int fd, char *left_line, char *buffer)
{
	ssize_t bytes_read;
	char *temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return(NULL);
		else if (bytes_read == 0)
			break;
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
	char	*left_c;
	ssize_t i;

	i = 0;
	if (!line_buffer)
		return NULL;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return NULL;
	left_c = ft_substr (line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*left_c == 0)
	{
		free(left_c);
		left_c = NULL;
	}
	return left_c;
}

char	*ft_strdup(const char *s)
{
	char	*memory;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	memory = (char *) malloc (sizeof(char) * (len + 1));
	if (!memory)
		return (NULL);
	while (i < len)
	{
		memory[i] = s[i];
		i++;
	}
	memory[len] = '\0';
	return (memory);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat_str;
	char	*cat_str_start;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	cat_str = (char *) malloc (sizeof(char) * (s1_len + s2_len + 1));
	if (!cat_str)
		return (NULL);
	cat_str_start = cat_str;
	while (*s1)
		*cat_str++ = *s1++;
	while (*s2)
		*cat_str++ = *s2++;
	*cat_str = '\0';
	return (cat_str_start);
}
