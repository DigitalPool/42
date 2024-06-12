/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:19:01 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/13 14:05:06 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}

// int main ()
// {
// 	printf ("%d\n", ft_recursive_factorial(3));
// 	printf ("%d\n", ft_recursive_factorial(-3));
// 	printf ("%d\n", ft_recursive_factorial(0));
// }
