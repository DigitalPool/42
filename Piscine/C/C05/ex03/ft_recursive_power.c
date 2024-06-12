/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:35:35 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/13 15:58:58 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		return (nb * ft_recursive_power(nb, (power - 1)));
	}
}

// int main ()
// {
// 	printf ("%d\n", ft_recursive_power(3, 9));
// 	printf ("%d\n", ft_recursive_power(-3, -2));
// 	printf ("%d\n", ft_recursive_power(0, 0));
// }
