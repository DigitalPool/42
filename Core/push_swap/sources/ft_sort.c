/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:59:49 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/26 17:07:27 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Here we chech which number of the quatile is close to the top or the bottom
//then we push. After pushing all to stack_b, the top quartile of stack_b would
//would be filled with the highest numbers down the stack. we would then start
//pushing the big numbers into stack_a quartile by quartile, and then sorting them
//but also noting the move counts to see the cheapest moves.

void	ft_sort(t_stack **stack_a)
{
	// printf("Stack before sorting in ft_sort:\n");
	// print_stack(*stack_a);

	t_stack	**stack_b;
	int		stack_mean = ft_stack_mean(stack_a);
	int		mean1_stack = ft_mean1_stack(stack_a);
	int		mean3_stack = ft_mean3_stack(stack_a);
	int		stack_max = ft_max((*stack_a));
	// printf (" mean1_stack is %d\n", mean1_stack);

	stack_b = (t_stack **)malloc(sizeof(t_stack));

	while ((*stack_a) && (!is_sorted(stack_a)) && (ft_min(*stack_a) <= mean1_stack))
	{
		if ((*stack_a)->nbr <= mean1_stack)
			ft_pb(stack_a, stack_b, 0);
		else if ((ft_lst_last(*stack_a))->nbr <= mean1_stack)
		{
			ft_rra(stack_a, 0);
			ft_pb(stack_a, stack_b, 0);
			// printf (" mean1_stack is %d\n", mean1_stack);
		}
		else if ((move_count_ra(stack_a, (find_next_memmean1_top((stack_a), mean1_stack))))
			< (move_count_rra (stack_a, (find_next_memmean1_bottom((stack_a), mean1_stack)))))
		{
			// printf (" stack_a now is "); print_stack(*stack_a);
			// printf (" memmean1_top is %d\n", find_next_memmean1_top((stack_a), mean1_stack));
			// printf (" mean1_stack is %d\n", mean1_stack);
			// printf (" memmean1_bottom is %d\n", find_next_memmean1_bottom((stack_a), mean1_stack));
			// printf (" move count ra is %d\n", move_count_ra(stack_a, (find_next_memmean1_top((stack_a), mean1_stack))));
			// printf (" move count rra is %d\n", move_count_rra(stack_a, (find_next_memmean1_bottom((stack_a), mean1_stack))));

			if (find_next_memmean1_top((stack_a), mean1_stack) != (*stack_a)->nbr)
				ft_ra(stack_a, 0);
			else
				ft_pb(stack_a, stack_b, 0);
		}
		else if ((move_count_ra(stack_a, (find_next_memmean1_top((stack_a), mean1_stack))))
			> (move_count_rra (stack_a, (find_next_memmean1_bottom((stack_a), mean1_stack)))))
		{
			if (find_next_memmean1_bottom((stack_a), mean1_stack) != (*stack_a)->nbr)
				ft_rra(stack_a, 0);
			else
				ft_pb(stack_a, stack_b, 0);
		}
		else
			ft_ra(stack_a, 0);
	}

	// printf("Stack_a after first step in ft_sort:\n");
	// print_stack(*stack_a);
	// printf("Stack_b after first step in ft_sort:\n");
	// print_stack(*stack_b);


	while ((*stack_a) && (!is_sorted(stack_a)) && (ft_min(*stack_a) <= stack_mean))
	{
		if ((*stack_a)->nbr <= stack_mean)
			ft_pb(stack_a, stack_b, 0);
		else if ((ft_lst_last(*stack_a))->nbr <= stack_mean)
		{
			ft_rra(stack_a, 0);
			ft_pb(stack_a, stack_b, 0);
			printf (" stack_mean is %d\n", stack_mean);
		}
		else if ((move_count_ra(stack_a, (find_next_memmean_top((stack_a), stack_mean))))
			< (move_count_rra (stack_a, (find_next_memmean_bottom((stack_a), stack_mean)))))
		{
			// printf (" stack_a now is "); print_stack(*stack_a);
			// printf (" stack_mean is %d\n", stack_mean);
			// printf (" memmean_top is %d\n", find_next_memmean_top((stack_a), stack_mean));
			// printf (" memmean_bottom is %d\n", find_next_memmean_bottom((stack_a), stack_mean));
			// printf (" move count ra is %d\n", move_count_ra(stack_a, (find_next_memmean_top((stack_a), stack_mean))));
			// printf (" move count rra is %d\n", move_count_rra(stack_a, (find_next_memmean_bottom((stack_a), stack_mean))));

			if ((find_next_memmean_top((stack_a), stack_mean)) != ((*stack_a)->nbr))
				ft_ra(stack_a, 0);
			else
				ft_pb(stack_a, stack_b, 0);
		}
		else if ((move_count_ra(stack_a, (find_next_memmean_top((stack_a), stack_mean))))
			> (move_count_rra (stack_a, (find_next_memmean_bottom((stack_a), stack_mean)))))
		{
			if ((find_next_memmean_bottom((stack_a), stack_mean)) != ((*stack_a)->nbr))
				ft_rra(stack_a, 0);
			else
				ft_pb(stack_a, stack_b, 0);
		}
		else
			ft_ra(stack_a, 0);
	}

	// printf("Stack_a after second step in ft_sort:\n");
	// print_stack(*stack_a);
	// printf("Stack_b after second step in ft_sort:\n");
	// print_stack(*stack_b);


	while ((*stack_a) && (!is_sorted(stack_a)) && (ft_min(*stack_a) <= mean3_stack))
	{
		if ((*stack_a)->nbr <= mean3_stack)
			ft_pb(stack_a, stack_b, 0);
		else if ((ft_lst_last(*stack_a))->nbr <= mean3_stack)
		{
			ft_rra(stack_a, 0);
			ft_pb(stack_a, stack_b, 0);
			printf (" mean3_stack is %d\n", mean3_stack);
		}
		else if ((move_count_ra(stack_a, (find_next_memmean_top((stack_a), mean3_stack))))
			< (move_count_rra (stack_a, (find_next_memmean_bottom((stack_a), mean3_stack)))))
		{
			// printf (" stack_a now is "); print_stack(*stack_a);
			// printf (" mean3_stack is %d\n", mean3_stack);
			// printf (" memmean_top is %d\n", find_next_memmean_top((stack_a), mean3_stack));
			// printf (" memmean_bottom is %d\n", find_next_memmean_bottom((stack_a), mean3_stack));
			// printf (" move count ra is %d\n", move_count_ra(stack_a, (find_next_memmean_top((stack_a), mean3_stack))));
			// printf (" move count rra is %d\n", move_count_rra(stack_a, (find_next_memmean_bottom((stack_a), mean3_stack))));

			if ((find_next_memmean_top((stack_a), mean3_stack)) != ((*stack_a)->nbr))
				ft_ra(stack_a, 0);
			else
				ft_pb(stack_a, stack_b, 0);
		}
		else if ((move_count_ra(stack_a, (find_next_memmean_top((stack_a), mean3_stack))))
			> (move_count_rra (stack_a, (find_next_memmean_bottom((stack_a), mean3_stack)))))
		{
			if ((find_next_memmean_bottom((stack_a), mean3_stack) )!= ((*stack_a)->nbr))
				ft_rra(stack_a, 0);
			else
				ft_pb(stack_a, stack_b, 0);
		}
		else
			ft_ra(stack_a, 0);
	}

	// printf("Stack_a after third step in ft_sort:\n");
	// print_stack(*stack_a);
	// printf("Stack_b after third step in ft_sort:\n");
	// print_stack(*stack_b);


	while ((*stack_a) && (!is_sorted(stack_a)) && (ft_lst_size(*stack_a) > 5))
	{
		if ((*stack_a)->nbr == stack_max)
			ft_ra(stack_a, 0);
		else
			ft_pb(stack_a, stack_b, 0);
	}
	ft_sort_five(stack_a);

	while ((*stack_b))
	{
		if ((*stack_b)->nbr > (*stack_a)->nbr)
			ft_ra(stack_a, 0);
		if (((*stack_b)->nbr < ft_lst_last(*stack_a)->nbr) && (ft_lst_last(*stack_a)->nbr < (*stack_a)->nbr))
			ft_rra(stack_a, 0);
		else if ((*stack_b)->nbr < (*stack_a)->nbr)
			ft_pa(stack_a, stack_b, 0);
	}

	while (!(is_sorted (stack_a)))
		ft_rra(stack_a, 0);
}

