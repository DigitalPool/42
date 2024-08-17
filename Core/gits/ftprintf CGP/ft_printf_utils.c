/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:30:16 by ashobajo          #+#    #+#             */
/*   Updated: 2024/06/12 04:56:00 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
	return write(1, &c, 1);
}

int ft_putstr(char *str)
{
	int len = 0;
	if (!str)
		str = "(null)";
	while (str && *str)
		len += ft_putchar(*str++);
	return len;
}

int ft_putnbr(int n)
{
	char num[12];
	int len = 0;
	int i = 0;
	long nbr = n;

	if (nbr == 0)
		return ft_putchar('0');
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr = -nbr;
	}
	while (nbr)
	{
		num[i++] = '0' + (nbr % 10);
		nbr /= 10;
	}
	while (i--)
		len += ft_putchar(num[i]);
	return len;
}

int ft_putunbr(unsigned int n)
{
	char num[11];
	int len = 0;
	int i = 0;

	if (n == 0)
		return ft_putchar('0');
	while (n)
	{
		num[i++] = '0' + (n % 10);
		n /= 10;
	}
	while (i--)
		len += ft_putchar(num[i]);
	return len;
}
