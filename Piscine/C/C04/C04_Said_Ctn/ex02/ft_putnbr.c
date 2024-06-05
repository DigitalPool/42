/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:06:03 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/10 15:41:08 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	buffer[12];
	int		i;
	int		is_negative;

	i = 0;
	is_negative = 0;
	if (nb < 0)
	{
		is_negative = 1;
		nb = -1 * nb;
	}
	while (nb != 0)
	{
		buffer[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	if (is_negative)
	{
		ft_putchar('-');
	}
	while (i > 0)
	{
		ft_putchar(buffer[--i]);
	}
}

//	int	main(void)
//	{
//	ft_putnbr(-4454542); // Example usage
//	return 0;
// }
