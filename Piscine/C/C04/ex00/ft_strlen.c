/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:36:19 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/09 13:52:58 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	strlen;
	int	i;

	i = 0;
	strlen = 0;
	while (str[i] != '\0')
	{
		i++;
		strlen++;
	}
	return (strlen);
}

// int main (void)
// {

// 	printf ("%i", ft_strlen("ggfffs"));
// }
