/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:15:08 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/13 18:35:14 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	factorial;

	i = 1;
	factorial = 1;
	if (nb < 0)
	{
		return (0);
	}
	while (i <= nb)
	{
		factorial = factorial * i;
		i++;
	}
	return (factorial);
}

// int	main(void)
// {
// 	printf("%d\n", ft_iterative_factorial(5));
// }
