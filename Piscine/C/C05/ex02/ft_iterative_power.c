/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:19:49 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/13 14:06:18 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		while (power > 1)
		{
			result = nb * result;
			power--;
		}
		return (result);
	}
}

// int main ()
// {
// 	printf ("%d\n", ft_iterative_power(3, 9));
// 	printf ("%d\n", ft_iterative_power(-3, -2));
// 	printf ("%d\n", ft_iterative_power(0, 0));
// }
