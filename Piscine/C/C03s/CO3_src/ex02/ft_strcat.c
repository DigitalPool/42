/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:10:41 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/07 14:58:20 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*dest_str;

	dest_str = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (dest_str);
}

// int main() {
//     char dest[50] = "Hello, ";
//     char src[] = "world!";

//     printf("Before concatenation: %s\n", dest);
//     ft_strcat(dest, src);
//     printf("After concatenation: %s\n", dest);

//     return 0;
// }
