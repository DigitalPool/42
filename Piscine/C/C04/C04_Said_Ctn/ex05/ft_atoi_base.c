/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:59:26 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/10 15:30:07 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int		isnt_valid_base(char *base);
int		ft_power(int base, int exponent);
int		ft_char_to_digit(char c, char *base);
int		ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	strlen;
	int	i;

	i = 0;
	strlen = 0;
	while (str[i] != '\0')
	{
		i++;
		strlen++;
	}
	return (strlen);
}

int	isnt_valid_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (!base || ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || isspace(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_char_to_digit(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (!isnt_valid_base(base))
		return (0);
	while (isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (ft_char_to_digit(str[i], base) == -1)
			return (0);
		result = result * ft_strlen(base) + ft_char_to_digit(str[i], base);
		i++;
	}
	return (result * sign);
}

int	ft_power(int base, int exponent)
{
	int		result;

	exponent = 0;
	result = 1;
	while (exponent--)
		result *= base;
	return (result);
}

// int main(void)
// {
//     // Example 1: Binary to Decimal
//     char *binary_base = "01";
//     char *binary_number = "1010";
//     int decimal_value = ft_atoi_base(binary_number, binary_base);
//     printf("Binary %s in decimal is: %d\n", binary_number, decimal_value);

//     // Example 2: Hexadecimal to Decimal
//     char *hex_base = "0123456789ABCDEF";
//     char *hex_number = "1A2B";
//     int decimal_value2 = ft_atoi_base(hex_number, hex_base);
//     printf("Hexadecimal %s in decimal is: %d\n", hex_number, decimal_value2);

//     // Example 3: Decimal to Decimal (Should return the same number)
//     char *decimal_base = "0123456789";
//     char *decimal_number = "12345";
//     int decimal_value3 = ft_atoi_base(decimal_number, decimal_base);
//     printf("Decimal %s in decimal is: %d\n", decimal_number, decimal_value3);

//     // Example 4: Invalid Base
//     char *invalid_base = "+- 0123";
//     char *invalid_number = "123";
//     int invalid_value = ft_atoi_base(invalid_number, invalid_base);
//     printf("Invalid number %s with base %s: %d\n",
// 	invalid_number, invalid_base, invalid_value);

//     return 0;
// }
