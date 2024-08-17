/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:31:45 by ashobajo          #+#    #+#             */
/*   Updated: 2024/06/12 04:47:55 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int ft_printf(const char *format, ...);

// Utility functions
int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr(int n);
int ft_putunbr(unsigned int n);
int ft_puthex(unsigned int n, int uppercase);
int ft_putptr(void *ptr);

#endif
