/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:26:02 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/16 19:00:02 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*allocate_empty_string(void)
{
	char	*empty;

	empty = (char *)malloc(sizeof(char));
	if (empty == NULL)
		return (NULL);
	empty[0] = '\0';
	return (empty);
}

int	calculate_total_length(int size, char **strs, char *sep)
{
	int	total_length;
	int	i;
	int	j;
	int	sep_length;

	total_length = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			j++;
		}
		total_length += j;
		i++;
	}
	sep_length = 0;
	while (sep[sep_length] != '\0')
	{
		sep_length++;
	}
	total_length += (size * sep_length);
	return (total_length);
}

void	copy_string_and_sep(char *str, char *sep, int *index, char **memory)
{
	int	j;
	int	k;

	j = 0;
	while (str[j] != '\0')
		(*memory)[(*index)++] = str[j++];
	if (sep[0] != '\0')
	{
		k = 0;
		while (sep[k] != '\0')
			(*memory)[(*index)++] = sep[k++];
	}
}

char	*copy_strings(int size, char **strs, char *sep, int total_length)
{
	char	*memory;
	int		index;
	int		i;

	memory = (char *)malloc((total_length + 1) * sizeof(char));
	if (!memory)
		return (NULL);
	index = 0;
	i = 0;
	while (i < size - 1)
	{
		copy_string_and_sep(strs[i], sep, &index, &memory);
		i++;
	}
	while (*strs[i] != '\0')
	{
		memory[index++] = *strs[i]++;
	}
	memory[index] = '\0';
	return (memory);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	total_length;

	if (size == 0)
		return (allocate_empty_string());
	total_length = calculate_total_length(size, strs, sep);
	return (copy_strings(size, strs, sep, total_length));
}

// int	main()
// {
// 	char	*strings[] = {"Hello", "42", "Prague", "Pisciners"};
// 	char	*sep = "-";
// 	char	*joined_string = ft_strjoin(4, strings, sep);
// 	printf("Joined string: %s\n", joined_string);
// }
