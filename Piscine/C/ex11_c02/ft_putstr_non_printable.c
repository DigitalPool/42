/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:39:26 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/06 12:38:55 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* charToHex(unsigned char c);
int ft_char_isnt_printable(char c);

int ft_char_isnt_printable(char c)
{
    return !(c >= 32 && c <= 126);
}

// int ft_char_isnt_printable(char c)
// {
// 	int i;

// 	i = 0;


// 	if (c >= 32 && c <= 126)
// 	{
// 		return 1;
// 	}

// 	else
// 	{
// 		return 0;
// 	}
// }


char* charToHex(unsigned char c)
{
	char *hex;

	hex = (char *)malloc(3 * sizeof(c));

	return hex;
}

void ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (ft_char_isnt_printable(*str))
		{
			char *hex = charToHex(*str);
			charToHex(*str);
			free (hex);
		}

		else
		{
			putchar(*str);
		}

	str++;
	}
}


int main(void) {
    char *string = "Coucou\ntu vas bien ?";

    printf("Original string: %s\n", string);
    printf("Modified string: ");
    ft_putstr_non_printable(string);
    printf("\n");

    return 0;
}

