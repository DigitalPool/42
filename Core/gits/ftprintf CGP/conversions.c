/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:31:03 by ashobajo          #+#    #+#             */
/*   Updated: 2024/06/12 04:47:39 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_puthex(unsigned int n, int uppercase)
{
    char *base;
    char num[9];
    int len = 0;
    int i = 0;

    base = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    if (n == 0)
        return ft_putchar('0');
    while (n)
    {
        num[i++] = base[n % 16];
        n /= 16;
    }
    while (i--)
        len += ft_putchar(num[i]);
    return len;
}

int ft_putptr(void *ptr)
{
    unsigned long long addr = (unsigned long long)ptr;
    char num[17];
    int len = 0;
    int i = 0;

    if (ptr == NULL)
        return ft_putstr("(nil)");
    len += ft_putstr("0x");
    while (addr)
    {
        num[i++] = "0123456789abcdef"[addr % 16];
        addr /= 16;
    }
    while (i--)
        len += ft_putchar(num[i]);
    return len;
}
