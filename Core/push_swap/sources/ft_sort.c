/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:37:07 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/25 14:48:40 by ashobajo         ###   ########.fr       */
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
	t_stack	**stack_b;
	int		stack_mean = ft_stack_mean(stack_a);
	int		mean1_stack = ft_mean1_stack(stack_a);
	int		mean3_stack = ft_mean3_stack(stack_a);
	int		stack_max = ft_max((*stack_a));

	stack_b = NULL;
	if ((ft_lst_size(*stack_a) == 2) && is_sorted(stack_a))
		ft_ra(stack_a, 0);
	else
	{
		while ((*stack_a) && (!is_sorted(stack_a)) && (ft_max(*stack_a) <= mean1_stack))
		{
			if ((*stack_a)->nbr <= mean1_stack)
				ft_pb(stack_a, stack_b, 0);
			else if ((ft_lst_last(*stack_a))->nbr <= mean1_stack)
				{
					ft_rra(stack_a, 0);
					ft_pb(stack_a, stack_b, 0);
				}
			//else we would find the best move from top 50% against that from bottom 50%
			else if (move_count_ra(stack_a, find_next_memmean1_top((stack_a), mean1_stack)) < (move_count_rra (stack_a, find_next_memmean1_bottom((stack_a), mean1_stack))))
			{
				while (find_next_memmean1_top((stack_a), mean1_stack) != (*stack_a)->nbr)
					ft_ra(stack_a, 0);
			}
			else if ((move_count_rra (stack_a, find_next_memmean1_bottom((stack_a), mean1_stack))) < move_count_ra(stack_a, find_next_memmean1_top((stack_a), mean1_stack)))
			{
				while (find_next_memmean1_bottom((stack_a), mean1_stack) != (*stack_a)->nbr)
					ft_rra(stack_a, 0);
			}

			ft_pb(stack_a, stack_b, 0);
		}

		while ((*stack_a) && !is_sorted(stack_a) && (ft_max(*stack_a) <= stack_mean))
		{
			if ((*stack_a)->nbr <= stack_mean)
				ft_pb(stack_a, stack_b, 0);
			else if ((ft_lst_last(*stack_a))->nbr <= stack_mean)
				{
					ft_rra(stack_a, 0);
					ft_pb(stack_a, stack_b, 0);
				}
			else if ((move_count_ra(stack_a, find_next_memmean_top((stack_a), stack_mean))) < (move_count_rra (stack_a, find_next_memmean_bottom((stack_a), stack_mean))))
			{
				while (find_next_memmean_top((stack_a), stack_mean) != (*stack_a)->nbr)
					ft_ra(stack_a, 0);
			}
			else if ((move_count_rra (stack_a, find_next_memmean_bottom((stack_a), stack_mean))) < move_count_ra(stack_a, find_next_memmean_top((stack_a), stack_mean)) )
			{
				while (find_next_memmean1_bottom((stack_a), stack_mean) != (*stack_a)->nbr)
					ft_rra(stack_a, 0);
			}

			ft_pb(stack_a, stack_b, 0);
		}

		while ((*stack_a) && !is_sorted(stack_a) && (ft_max(*stack_a) <= mean3_stack))
		{
			if ((*stack_a)->nbr <= mean3_stack)
				ft_pb(stack_a, stack_b, 0);
			else if ((ft_lst_last(*stack_b))->nbr <= mean3_stack)
				{
					ft_rra(stack_a, 0);
					ft_pb(stack_a, stack_b, 0);
				}
			else if (move_count_ra(stack_a, find_next_memmean3_top((stack_a), mean3_stack)) < (move_count_rra (stack_a, find_next_memmean3_bottom((stack_a), mean3_stack))))
			{
				while (find_next_memmean3_top((stack_a), mean3_stack) != (*stack_a)->nbr)
					ft_ra(stack_a, 0);
			}
			else if ((move_count_rra (stack_a, find_next_memmean3_bottom((stack_a), mean3_stack))) < move_count_ra(stack_a, find_next_memmean3_top((stack_a), mean3_stack)) )
			{
				while (find_next_memmean3_bottom((stack_a), mean3_stack) != (*stack_a)->nbr)
					ft_rra(stack_a, 0);
			}

			ft_pb(stack_a, stack_b, 0);
		}

		while ((*stack_a) && !is_sorted(stack_a))
		{
			//here stack_a remains the topest 25% (from mean3). So we first find the smallest and largest numbers
			//we keep them in the stack, push the rest and start sorting them back to the stack_a from stack_b

			if ((*stack_a)->nbr == ft_min(*stack_a) || (*stack_a)->nbr == stack_max)
				ft_ra(stack_a, 0);
			else
				ft_pb(stack_a, stack_b, 0);
		}
	}

	while (*stack_b)
	{
		int next_mean = mean3_stack;

		while ((*stack_b)->nbr >= next_mean)
		{
			if ((*stack_b)->nbr == ft_max(*stack_b))
				ft_pa(stack_a, stack_b, 0);
			else if ((ft_lst_last(*stack_b))->nbr == ft_min(*stack_b))
			{
				ft_rb(stack_b, 0);
				ft_pa(stack_a, stack_b, 0);
				ft_ra(stack_a, 0);
			}
			else
			{
				if (move_count_rbpa(stack_b, find_next_max_top((stack_b))) < (move_count_rrbpa(stack_b, find_next_min_bottom((stack_a)))))
				{
					while (find_next_max_top((stack_b)) != (*stack_a)->nbr)
						ft_rb(stack_b, 0);
					ft_pa(stack_a, stack_b, 0);
				}
				if ((move_count_rrbpa (stack_b, find_next_min_bottom((stack_a)))) < move_count_rbpa(stack_b, find_next_max_top((stack_b))))
				{
					while (find_next_min_bottom((stack_b)) != (*stack_b)->nbr)
					{
						ft_rrb(stack_b, 0);
					}
					ft_pa(stack_a, stack_b, 0);
					ft_rra(stack_a, 0);
				}
			}

			if ((ft_max(*stack_b)) <= next_mean && ft_max(*stack_b) >= stack_mean)
				next_mean = stack_mean;
			else if ((ft_max(*stack_b)) <= stack_mean && ft_max(*stack_b) >= mean1_stack)
				next_mean = mean1_stack;
			else if ((ft_max(*stack_b)) <= mean1_stack)
				next_mean = ft_min(*stack_b);
		}

	}

	while (!is_sorted(stack_a))
	{
		if (move_count_ra_stack(stack_a) < (move_count_rra_stack(stack_a)))
			ft_ra(stack_a, 0);
		else if ((move_count_rra_stack (stack_a)) < move_count_ra_stack(stack_a))
			ft_ra(stack_a, 0);
	}
}
