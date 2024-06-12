/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:58:52 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/13 14:02:12 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;
	int	square_root;

	i = 2;
	if (nb == 1)
		return (1);
	while (i < nb)
	{
		square_root = i * i;
		if (square_root == nb)
			return (i);
		i++;
	}
	return (0);
}

// int main ()
// {
// 	printf ("%d\n", ft_sqrt(4));
// 	printf ("%d\n", ft_sqrt(400));
// 	printf ("%d\n", ft_sqrt(16));
// }
