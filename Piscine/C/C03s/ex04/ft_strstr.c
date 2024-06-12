/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:22:50 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/03/05 20:53:30 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	s_ctr;
	int	f_ctr;

	s_ctr = 0;
	while (str[s_ctr] != '\0')
	{
		f_ctr = 0;
		while (str[s_ctr + f_ctr] == to_find[f_ctr] && to_find[f_ctr] != 0)
		{
			f_ctr++;
		}
		if (to_find[f_ctr] == '\0')
			return (str + s_ctr);
		s_ctr++;
	}
	return (NULL);
}

int main() {
    char str[] = "Hello, world! This is a test string.";
    char to_find[] = "world";

    char *result = ft_strstr(str, to_find);
    if (result != NULL) {
        printf("'%s' found at position %ld in '%s'\n", to_find, result - str, str);
    } else {
        printf("'%s' not found in '%s'\n", to_find, str);
    }

    return 0;
}
