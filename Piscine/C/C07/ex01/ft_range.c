/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:54:22 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/16 13:23:08 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int		*range;
	int		i;
	int		size;

	size = max - min;
	i = 0;
	range = (int *)malloc((size + 1) * sizeof(int));
	if (min >= max)
		return (NULL);
	while (i < size)
	{
		range[i] = min;
		min++;
		i++;
	}
	return (range);
}

// int main() {
//     int min = 1;
//     int max = 12;

//     // Call ft_range to generate the range of integers
//     int *result = ft_range(min, max);

//     // Print the generated range of integers
//     printf("Generated range: ");
//     for (int i = 0; i < max - min; i++) {
//         printf("%d ", result[i]);
//     }
//     printf("\n");

//     // Free the allocated memory
//     free(result);

//     return 0;
// }
