/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:07:18 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/16 13:22:38 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen_an_null(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i + 1);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	dup = (char *)malloc(ft_strlen_an_null(src) * (sizeof(char)));
	i = 0;
	while (*src)
	{
		dup[i++] = *src++;
	}
	dup[i] = '\0';
	return (dup);
}

// int	main (void)
// {
// 	char src[] = {"bell"};

// 	printf ("%s:\n", ft_strdup(src));
// 	printf ("%s:\n", strdup(src));
// }
