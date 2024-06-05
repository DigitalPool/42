/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:49:08 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/07 15:11:57 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	chc_s;
	int	chc_f;

	chc_s = 0;
	while (str[chc_s] != '\0')
	{
		chc_f = 0;
		while (str[chc_s + chc_f] == to_find[chc_f] && to_find[chc_f] != 0)
		{
			chc_f++;
		}
		if (to_find[chc_f] == '\0')
			return (str + chc_s);
		chc_s++;
	}
	return (NULL);
}

// int main() {
//     char str[] = "Hello, world! This is a test string.";
//     char to_find[] = "world";

//     char *result = ft_strstr(str, to_find);
//     if (result != NULL) {
//         printf("'%s' found at position %ld in '%s'\n",
// 		to_find, result - str, str);
//     } else {
//         printf("'%s' not found in '%s'\n", to_find, str);
//     }

//     return 0;
// }
