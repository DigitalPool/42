/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:46:40 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/20 19:13:12 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_stack(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;

	if (ft_lst_size(*stack_a) == 2)
		ft_sa(stack_a, 0);
	else
		ft_sort(stack_a, &stack_b);

	// printf("after ft_sort_stack:\n");
	// print_stack(*stack_a);
}

void ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lst_size(*stack_a) == 3 && !is_sorted(stack_a))
		ft_sort_three(stack_a);

	while (ft_lst_size(*stack_a) > 3)
	{
		if ((*stack_a)->nbr == ft_min(*stack_a))
			ft_pb(stack_a, stack_b, 0);
		else
			ft_ra(stack_a, 0);
	}
	if (ft_lst_size(*stack_a) == 2 && (*stack_a)->nbr > (*stack_a)->next->nbr)
		ft_sa(stack_a, 0);

	while (*stack_b)
		ft_pa(stack_a, stack_b, 0);

	// printf("after ft_sort:\n");
	// print_stack(*stack_a);
}

void ft_sort_three(t_stack **stack_a)
{
	if (!is_sorted(stack_a))
	{
		int stack_min = ft_min(*stack_a);
		int stack_max = ft_max(*stack_a);

		printf ("min = %d, max = %d\n", stack_min, stack_max);

		if (stack_min == (*stack_a)->nbr && stack_max == (*stack_a)->next->nbr)
		{
			ft_sa(stack_a, 0);
			ft_ra(stack_a, 0);
		}
		else if (stack_min == (*stack_a)->next->next->nbr && stack_max == (*stack_a)->nbr)
		{
			ft_ra(stack_a, 0);
			ft_sa(stack_a, 0);
		}
		else if (stack_min == (*stack_a)->next->nbr && stack_max == (*stack_a)->next->next->nbr)
			ft_sa(stack_a, 0);
		else if (stack_min == (*stack_a)->next->nbr && stack_max == (*stack_a)->nbr)
			ft_ra(stack_a, 0);
		else if (stack_min == (*stack_a)->next->next->nbr && stack_max == (*stack_a)->next->nbr)
			ft_rra(stack_a, 0);
	}

	// printf("after ft_sort_three:\n");
	// print_stack(*stack_a);
}

