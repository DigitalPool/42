/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:13:12 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/03/05 20:52:37 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*c_dest;
	unsigned int	ctr;

	ctr = 0;
	c_dest = dest;
	while (*dest != '\0')
		dest++;
	while (ctr < nb && src[ctr] != '\0')
	{
		*(dest + ctr) = *(src + ctr);
		ctr++;
	}
	*(dest + ctr) = '\0';
	return (c_dest);
}

int main() {
    char dest[50] = "Hello, ";
    char src[] = "world!";
    unsigned int nb = 3;

    printf("Before concatenation: %s\n", dest);
    ft_strncat(dest, src, nb);
    printf("After concatenation: %s\n", dest);

    return 0;
}

