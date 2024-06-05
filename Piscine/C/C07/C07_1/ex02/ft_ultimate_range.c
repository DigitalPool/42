/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:10:14 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/16 13:23:40 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	size = max - min;
	i = 0;
	*range = (int *)malloc(size * sizeof(int));
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (*range == NULL)
		return (-1);
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (size);
}

// int main() {
//     int *result; // Pointer to hold the generated range
//     int min = 1;
//     int max = 12;

//     // Call ft_ultimate_range to generate the range of integers
//     int range_size = ft_ultimate_range(&result, min, max);

//     // Check if the range generation was successful
//     if (range_size == -1) {
//         printf("Memory allocation failed!\n");
//         return 1; // Exit program with error
//     }

//     // If range_size is 0, the range is empty
//     if (range_size == 0) {
//         printf("Empty range!\n");
//         return 0;
//     }

//     // Print the generated range of integers
//     printf("Generated range: ");
//     for (int i = 0; i < range_size; i++) {
//         printf("%d ", result[i]);
//     }
//     printf("\n");

//     // Free the allocated memory
//     free(result);

//     return 0;
// }
