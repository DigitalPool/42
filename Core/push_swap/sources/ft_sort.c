/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:59:49 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/29 10:14:40 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Here we chech which number of the quatile is close to the top or the bottom
//then we push. After pushing all to stack_b, the top quartile of stack_b would
//would be filled with the highest numbers down the stack. we would then start
//pushing the big numbers into stack_a quartile by quartile, and then sorting them
//but also noting the move counts to see the cheapest moves.

void push_tob(t_stack **stack_a, t_stack **stack_b, int mean_value)
{
	while ((*stack_a) && (!is_sorted(stack_a)) && (ft_min(*stack_a) <= mean_value) && (ft_lst_size(*stack_a) > 3))
	{
		if ((*stack_a)->nbr <= mean_value)
		{
			ft_pb(stack_a, stack_b, 0);
		}
		else if ((ft_lst_last(*stack_a))->nbr <= mean_value)
		{
			ft_rra(stack_a, 0);
			ft_pb(stack_a, stack_b, 0);
		}
		else if ((move_count_ra(stack_a, find_next_memmean_top(stack_a, mean_value)))
			< (move_count_rra(stack_a, find_next_memmean_bottom(stack_a, mean_value))))
		{
			if (find_next_memmean_top(stack_a, mean_value) != (*stack_a)->nbr)
				ft_ra(stack_a, 0);
			else
			{
				ft_pb(stack_a, stack_b, 0);
			}
		}
		else if ((move_count_ra(stack_a, find_next_memmean_top(stack_a, mean_value)))
			> (move_count_rra(stack_a, find_next_memmean_bottom(stack_a, mean_value))))
		{
			if (find_next_memmean_bottom(stack_a, mean_value) != (*stack_a)->nbr)
				ft_rra(stack_a, 0);
			else
			{
				ft_pb(stack_a, stack_b, 0);
			}
		}
		else
			ft_ra(stack_a, 0);
	}
}

void push_tob_rot(t_stack **stack_a, t_stack **stack_b, int mean_value)
{
	while ((*stack_a) && (!is_sorted(stack_a)) && (ft_min(*stack_a) <= mean_value) && (ft_lst_size(*stack_a) > 3))
	{
		if ((*stack_a)->nbr <= mean_value)
		{
			ft_pb(stack_a, stack_b, 0);
			ft_rb(stack_b, 0);
		}
		else if ((ft_lst_last(*stack_a))->nbr <= mean_value)
		{
			ft_rra(stack_a, 0);
			ft_pb(stack_a, stack_b, 0);
			ft_rb(stack_b, 0);
		}
		else if ((move_count_ra(stack_a, find_next_memmean_top(stack_a, mean_value)))
			< (move_count_rra(stack_a, find_next_memmean_bottom(stack_a, mean_value))))
		{
			if (find_next_memmean_top(stack_a, mean_value) != (*stack_a)->nbr)
				ft_ra(stack_a, 0);
			else
			{
				ft_pb(stack_a, stack_b, 0);
				ft_rb(stack_b, 0);
			}
		}
		else if ((move_count_ra(stack_a, find_next_memmean_top(stack_a, mean_value)))
			> (move_count_rra(stack_a, find_next_memmean_bottom(stack_a, mean_value))))
		{
			if (find_next_memmean_bottom(stack_a, mean_value) != (*stack_a)->nbr)
				ft_rra(stack_a, 0);
			else
			{
				ft_pb(stack_a, stack_b, 0);
				ft_rb(stack_b, 0);
			}
		}
		else
			ft_ra(stack_a, 0);
	}
}


void	ft_sort(t_stack **stack_a)
{
	t_stack	**stack_b;
	const int		stack_mean = ft_stack_mean(stack_a);
	const int		mean1_stack = ft_mean1_stack(stack_a);
	const int		mean2_stack = ft_mean2_stack(stack_a);
	const int		mean3_stack = ft_mean3_stack(stack_a);
	const int		mean4_stack = ft_mean4_stack(stack_a);
	const int		mean5_stack = ft_mean5_stack(stack_a);
	const int		mean6_stack = ft_mean6_stack(stack_a);
	const int		mean7_stack = ft_mean7_stack(stack_a);
	const int		mean9_stack = ft_mean9_stack(stack_a);
	const int		mean10_stack = ft_mean10_stack(stack_a);
	const int		mean11_stack = ft_mean11_stack(stack_a);
	const int		mean12_stack = ft_mean12_stack(stack_a);
	const int		mean13_stack = ft_mean13_stack(stack_a);
	const int		mean14_stack = ft_mean14_stack(stack_a);
	const int		mean15_stack = ft_mean15_stack(stack_a);

	int		stack_max = ft_max((*stack_a));
	int		stack_min = ft_min((*stack_a));

	stack_b = (t_stack **)malloc(sizeof(t_stack));

	push_tob(stack_a, stack_b, mean1_stack);
	push_tob(stack_a, stack_b, mean2_stack);
	push_tob(stack_a, stack_b, mean3_stack);
	push_tob_rot(stack_a, stack_b, mean4_stack);
	push_tob(stack_a, stack_b, mean5_stack);
	push_tob_rot(stack_a, stack_b, mean6_stack);
	push_tob(stack_a, stack_b, mean7_stack);
	push_tob_rot(stack_a, stack_b, stack_mean);
	push_tob(stack_a, stack_b, mean9_stack);
	push_tob_rot(stack_a, stack_b, mean10_stack);
	push_tob(stack_a, stack_b, mean11_stack);
	push_tob_rot(stack_a, stack_b, mean12_stack);
	push_tob(stack_a, stack_b, mean13_stack);
	push_tob_rot(stack_a, stack_b, mean14_stack);
	push_tob(stack_a, stack_b, mean15_stack);

	while ((*stack_a) && (!is_sorted(stack_a)) && (ft_lst_size(*stack_a) > 3))
	{
		if ((*stack_a)->nbr == stack_max)
			ft_ra(stack_a, 0);
		else
			ft_pb(stack_a, stack_b, 0);
	}
	ft_sort_three(stack_a);


	while ((*stack_b))
	{
		if ((*stack_b)->nbr > (*stack_a)->nbr)
			ft_pa(stack_a, stack_b, 0);
		else if (((*stack_b)->nbr > (*stack_a)->nbr) && ((*stack_b)->nbr < (*stack_a)->next->nbr))
			{
				ft_ra(stack_a, 0);
				ft_pa(stack_a, stack_b, 0);
			}
		else if ((*stack_b)->nbr < ft_lst_last(*stack_a)->nbr)
			{
				ft_rra(stack_a, 0);
				ft_pa(stack_a, stack_b, 0);
			}
		else if ((*stack_b)->nbr < ft_lst_last(*stack_a)->prev->nbr)
			{
				ft_rra(stack_a, 0);
				ft_rra(stack_a, 0);
				ft_pa(stack_a, stack_b, 0);
			}


		if (((*stack_b)->nbr < ft_lst_last(*stack_a)->nbr) && (ft_lst_last(*stack_a)->nbr < (*stack_a)->nbr))
			ft_rra(stack_a, 0);
		else if ((*stack_b)->nbr < (*stack_a)->nbr)
			ft_pa(stack_a, stack_b, 0);
	}

	// while ((*stack_b))
	// {
	// 	if ((*stack_b)->nbr > (*stack_a)->nbr)
	// 		ft_ra(stack_a, 0);
	// 	if (((*stack_b)->nbr < ft_lst_last(*stack_a)->nbr) && (ft_lst_last(*stack_a)->nbr < (*stack_a)->nbr))
	// 		ft_rra(stack_a, 0);
	// 	else if ((*stack_b)->nbr < (*stack_a)->nbr)
	// 		ft_pa(stack_a, stack_b, 0);
	// }

	while (!(is_sorted (stack_a)))
	{
		if (move_count_ra(stack_a, stack_max) < move_count_rra(stack_a, stack_min))
			ft_ra(stack_a, 0);
		else
			ft_rra(stack_a, 0);
	}
}

