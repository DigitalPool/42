/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:23:37 by ashobajo          #+#    #+#             */
/*   Updated: 2024/06/12 04:55:39 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int handle_format(const char **format, va_list args)
{
	int len = 0;

	(*format)++;
	if (**format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (**format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (**format == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (**format == 'd' || **format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (**format == 'u')
		len += ft_putunbr(va_arg(args, unsigned int));
	else if (**format == 'x')
		len += ft_puthex(va_arg(args, unsigned int), 0);
	else if (**format == 'X')
		len += ft_puthex(va_arg(args, unsigned int), 1);
	else if (**format == '%')
		len += ft_putchar('%');
	else
		len += ft_putchar(**format);
	(*format)++;
	return len;
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int len = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			len += handle_format(&format, args);
		else
			len += ft_putchar(*format++);
	}
	va_end(args);
	return len;
}
