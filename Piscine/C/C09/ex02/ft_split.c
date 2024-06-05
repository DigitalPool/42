/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:07:52 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/20 18:12:25 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return 1;
		charset++;
	}
	return 0;
}

int	count_words(char *str, char *charset)
{
	int count = 0;
	int in_word = 0;

	while (*str)
	{
		if (!is_separator(*str, charset))
		{
			if (!in_word)
			{
				in_word = 1;
				count++;
			}
		}
		else
		{
			in_word = 0;
		}
		str++;
	}
	return count;
}

char	*copy_word(char *str, char *charset)
{
	char *start = str;
	while (*str && !is_separator(*str, charset))
	{
		str++;
	}
	int len = str - start;
	char *word = (char *)malloc((len + 1) * sizeof(char));
	for (int i = 0; i < len; i++)
	{
		word[i] = start[i];
	}
	word[len] = '\0';
	return word;
}

char	**ft_split(char *str, char *charset)
{
	int word_count = count_words(str, charset);
	char **result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
	{
		return NULL;
	}
	int i = 0;
	while (*str)
	{
		if (!is_separator(*str, charset))
		{
			result[i++] = copy_word(str, charset);
			while (*str && !is_separator(*str, charset))
			{
				str++;
			}
		}
		else
		{
			str++;
		}
	}
	result[word_count] = 0;
	return result;
}

// Main function
int	main(void)
{
	char str[] = "This,is,a,test,string";
	char charset[] = ",";
	char **result = ft_split(str, charset);

	printf("Split string:\n");
	for (int i = 0; result[i] != NULL; i++)
	{
		printf("%s\n", result[i]);
	}

	for (int i = 0; result[i] != NULL; i++)
	{
		free(result[i]);
	}
	free(result);

	return 0;
}
