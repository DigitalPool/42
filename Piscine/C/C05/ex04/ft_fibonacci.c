/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:35:35 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/13 14:03:08 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index < 2)
		return (index);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

// int main ()
// {
// 	printf ("%d\n", ft_fibonacci(3));
// 	printf ("%d\n", ft_fibonacci(-3));
// 	printf ("%d\n", ft_fibonacci(0));
// }
