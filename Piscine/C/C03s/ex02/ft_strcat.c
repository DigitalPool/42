/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:56:04 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/03/13 20:56:13 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*c_dest;

	c_dest = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (c_dest);
}

int main() {
    char dest[3] = "Hello, ";
    char src[] = "world!";

    printf("Before concatenation: %s\n", dest);
    ft_strcat(dest, src);
    printf("After concatenation: %s\n", dest);

    return 0;
}
