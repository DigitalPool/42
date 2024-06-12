/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:21:16 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/03/05 20:44:33 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	ctr;

	ctr = 0;
	while ((s1[ctr] != '\0' || s2[ctr] != '\0') && ctr < n)
	{
		if (s1[ctr] != s2[ctr])
			return (s1[ctr] - s2[ctr]);
		ctr++;
	}
	return (0);
}

int	main()
{
	char *a = "ABXasdsdad";
	char *b = "ABX";
	printf("%d\n", ft_strncmp(a, b, 2));
}
