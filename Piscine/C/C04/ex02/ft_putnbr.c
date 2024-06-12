/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:06:03 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/11 22:01:11 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char		buffer[12];
	int			i;
	int			is_negative;
	long long	nbl;

	nbl = nb;
	i = 0;
	is_negative = 0;
	if (nbl < 0)
	{
		is_negative = 1;
		nbl = -1 * nbl;
	}
	while (nbl != 0)
	{
		buffer[i++] = nbl % 10 + '0';
		nbl /= 10;
	}
	if (is_negative)
	{
		ft_putchar('-');
	}
	while (i > 0)
		ft_putchar(buffer[--i]);
}

// 	int	main(void)
// 	{
// 	ft_putnbr(-4454542); // Example usage
// 	write (1, "\n", 1);
// 	ft_putnbr(-2147483648); // Example usage
// 	return 0;
// }
