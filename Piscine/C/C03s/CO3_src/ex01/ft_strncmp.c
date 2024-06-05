/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:09:10 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/07 15:10:44 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	chc;

	chc = 0;
	while ((s1[chc] != '\0' || s2[chc] != '\0') && chc < n)
	{
		if (s1[chc] != s2[chc])
			return (s1[chc] - s2[chc]);
		chc++;
	}
	return (0);
}

// int	main()
// {
// 	char *a = "Balleee";
// 	char *b = "Ball";
// 	printf("%d\n", ft_strncmp(a, b, 2));
// }
