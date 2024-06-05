/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:50:31 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/07 15:12:27 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/string.h>

unsigned int	str_len(char *str)
{
	unsigned int	chc;

	chc = 0;
	while (str[chc] != '\0')
		chc++;
	return (chc);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	chk;
	unsigned int	dest_len;
	unsigned int	src_len;

	chk = 0;
	dest_len = str_len(dest);
	src_len = str_len(src);
	if (size == 0 || dest_len >= size)
		return (src_len + size);
	while (src[chk] != '\0' && chk < size - dest_len - 1)
	{
		dest[dest_len + chk] = src[chk];
		chk++;
	}
	dest[dest_len + chk] = '\0';
	return (dest_len + src_len);
}

// int main() {
//     char dest[20] = "Hello, ";
//     char src[] = "world!";
//     unsigned int size = 20;

//     printf("Before concatenation: %s\n", dest);
//     unsigned int result = ft_strlcat(dest, src, size);
//     printf("After concatenation: %s\n", dest);
//     printf("Result length: %u\n", result);

//     return 0;
// }
