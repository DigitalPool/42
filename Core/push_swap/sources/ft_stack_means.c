/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_means.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:04:47 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/25 16:07:56 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Calculate mean1 for elements <= mean
int ft_mean1_stack(t_stack **stack_a) {
	int mean1 = 0;
	int sum = 0;
	int count = 0;
	int mean = ft_stack_mean(stack_a);
	t_stack *temp = *stack_a;

	while (temp) {
		if (temp->nbr <= mean) {
			sum += temp->nbr;
			count++;
		}
		temp = temp->next;
	}

	if (count > 0)
		mean1 = sum / count; // Only divide if count is greater than 0
	else
		mean1 = 0; // Handle the case where no elements satisfy the condition

	return mean1;
}

// Calculate mean3 for elements > mean
int ft_mean3_stack(t_stack **stack_a) {
	int mean3 = 0;
	int sum = 0;
	int count = 0;
	int mean = ft_stack_mean(stack_a);
	t_stack *temp = *stack_a;

	while (temp) {
		if (temp->nbr > mean) {
			sum += temp->nbr;
			count++;
		}
		temp = temp->next;
	}

	if (count > 0)
		mean3 = sum / count; // Only divide if count is greater than 0
	else
		mean3 = 0; // Handle the case where no elements satisfy the condition

	return mean3;
}

// int ft_mean1_stack(t_stack **stack_a)
// {
// 	int mean1 = 0;
// 	int sum = 0;
// 	int count = 0;

// 	while ((*stack_a))
// 		{
// 			if ((*stack_a)->nbr < (ft_stack_mean(stack_a)))
// 				{
// 					sum += (*stack_a)->nbr;
// 					count++;
// 				}
// 			(*stack_a) = (*stack_a)->next;
// 		}

// 	if (count > 0)
// 		mean1 = sum / count; // Only divide if count is greater than 0
// 	else
// 		mean1 = 0; // Handle the case where no elements satisfy the condition

// 	return (mean1);
// }

// int ft_mean3_stack(t_stack **stack_a)
// {
// 	int mean3 = 0;
// 	int sum = 0;
// 	int count = 0;

// 	while ((*stack_a))
// 		{
// 			if ((*stack_a)->nbr > (ft_stack_mean(stack_a)))
// 				{
// 					sum += (*stack_a)->nbr;
// 					count++;
// 				}
// 			(*stack_a) = (*stack_a)->next;
// 		}

// 	if (count > 0)
// 		mean3 = sum / count; // Only divide if count is greater than 0
// 	else
// 		mean3 = 0; // Handle the case where no elements satisfy the condition

// 	return (mean3);
// }
