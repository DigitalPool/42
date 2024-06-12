/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:52:09 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/03/05 20:58:32 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/string.h>

unsigned int	f_strlen(char *str)
{
	unsigned int	res;

	res = 0;
	while (str[res] != '\0')
		res++;
	return (res);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	ctr;
	unsigned int	dest_l;
	unsigned int	src_l;

	ctr = 0;
	dest_l = f_strlen(dest);
	src_l = f_strlen(src);
	if (size == 0 || dest_l >= size)
		return (src_l + size);
	while (src[ctr] != '\0' && ctr < size - dest_l - 1)
	{
		dest[dest_l + ctr] = src[ctr];
		ctr++;
	}
	dest[dest_l + ctr] = '\0';
	return (dest_l + src_l);
}


int main() {
    char dest[20] = "Hello, ";
    char src[] = "world!";
    unsigned int size = 20;

    printf("Before concatenation: %s\n", dest);
    unsigned int result = ft_strlcat(dest, src, size);
    printf("After concatenation: %s\n", dest);
    printf("Result length: %u\n", result);

    return 0;
}
