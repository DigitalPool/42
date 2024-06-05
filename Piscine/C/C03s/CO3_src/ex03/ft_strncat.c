/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:48:13 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/07 15:11:24 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*dest_str;
	unsigned int	chc;

	chc = 0;
	dest_str = dest;
	while (*dest != '\0')
		dest++;
	while (chc < nb && src[chc] != '\0')
	{
		*(dest + chc) = *(src + chc);
		chc++;
	}
	*(dest + chc) = '\0';
	return (dest_str);
}

// int main() {
//     char dest[50] = "Hello, ";
//     char src[] = "world!";
//     unsigned int nb = 3;

//     printf("Before concatenation: %s\n", dest);
//     ft_strncat(dest, src, nb);
//     printf("After concatenation: %s\n", dest);

//     return 0;
// }
