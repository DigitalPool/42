/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:51:42 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/20 19:14:06 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%ld\n", stack->nbr);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;

	// Initialize the stack with input arguments
	stack_a = ft_get_stack(argc, argv);

	// Check for errors: empty stack, duplicates, etc.
	if (!stack_a || ft_check_duplicate(stack_a))
	{
		ft_free_stack(&stack_a);
		ft_print_error();
		return (1);  // Exit with error code
	}

	// // Print the stack before sorting
	// printf("Stack before sorting:\n");
	// print_stack(stack_a);

	// Sort the stack if it's not already sorted
	if (!is_sorted(&stack_a))
		ft_sort_stack(&stack_a);

	// // Print the stack after sorting
	// printf("Stack after sorting:\n");
	// print_stack(stack_a);

	// Free the stack memory
	ft_free_stack(&stack_a);
	return (0);
}


// int	main(int argc, char **argv)
// {
// 	t_stack *stack_a;

// 	stack_a = ft_get_stack (argc, argv);
// 	if(!stack_a || ft_check_duplicate(stack_a))
// 	{
// 		ft_free_stack(&stack_a);
// 		ft_print_error();
// 	}
// 	if(!is_sorted(&stack_a))
// 		ft_sort_stack(&stack_a);
// 	ft_free_stack(&stack_a);
// 	return (0);
// }
