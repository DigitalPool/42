/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:37:07 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/23 21:41:30 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Here we chech which number of the quatile is close to the top or the bottom
//then we push. After pushing all to stack_b, the top quartile of stack_b would
//would be filled with the highest numbers down the stack. we would then start
//pushing the big numbers into stack_a quartile by quartile, and then sorting them
//but also noting the move counts to see the cheapest moves.

void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	stack_mean = stack_mean(stack_a);
	mean1_stack = mean1_stack (stack_a);
	mean3_stack = mean3_stack (stack_a);
	stack_max = ft_max((*stack_a));



	stack_b = NULL;
	if (ft_lst_size(*stack_a) == 2)
		ft_sa(stack_a, 0);
	else
	{
		while ((*stack_a) && !is_sorted(stack_a))
		{
			if ((*stack_a)->nbr <= mean1_stack)
				ft_pb(stack_a, &stack_b, 0);
			else if ((ft_lst_last(*stack))->nbr <= mean1_stack)
				{
					ft_rra(stack_a, 0);
					ft_pb(stack_a, &stack_b, 0);
				}
			else if (move_count_ra(find_next_memmean1_top((*stack_a))) < (move_count_rra (find_next_memmean1_bottom((*stack_a)))))
			{
				while (find_next_memmean1_top((*stack_a)) != stack_a->nbr)
					ft_ra(stack_a, 0);
			}
			else if ((move_count_rra (find_next_memmean1_bottom((*stack_a)))) < move_count_ra(find_next_memmean1_top((*stack_a))) )
			{
				while (find_next_memmean1_bottom((*stack_a)) != stack_a->nbr)
					ft_rra(stack_a, 0);
			}

			ft_pb(stack_a, &stack_b, 0);
		}

		while ((*stack_a) && !is_sorted(stack_a))
		{
			if ((*stack_a)->nbr <= stack_mean)
				ft_pb(stack_a, &stack_b, 0);
			else if ((ft_lst_last(*stack))->nbr <= stack_mean)
				{
					ft_rra(stack_a, 0);
					ft_pb(stack_a, &stack_b, 0);
				}
			else if (move_count_ra(find_next_memmean1_top((*stack_a))) < (move_count_rra (find_next_memmean1_bottom((*stack_a)))))
			{
				while (find_next_memmean1_top((*stack_a)) != stack_a->nbr)
					ft_ra(stack_a, 0);
			}
			else if ((move_count_rra (find_next_memmean1_bottom((*stack_a)))) < move_count_ra(find_next_memmean1_top((*stack_a))) )
			{
				while (find_next_memmean1_bottom((*stack_a)) != stack_a->nbr)
					ft_rra(stack_a, 0);
			}

			ft_pb(stack_a, &stack_b, 0);
		}

		while ((*stack_a) && !is_sorted(stack_a))
		{
			if ((*stack_a)->nbr <= mean3_stack)
				ft_pb(stack_a, &stack_b, 0);
			else if ((ft_lst_last(*stack))->nbr <= mean3_stack)
				{
					ft_rra(stack_a, 0);
					ft_pb(stack_a, &stack_b, 0);
				}
			else if (move_count_ra(find_next_memmean1_top((*stack_a))) < (move_count_rra (find_next_memmean1_bottom((*stack_a)))))
			{
				while (find_next_memmean1_top((*stack_a)) != stack_a->nbr)
					ft_ra(stack_a, 0);
			}
			else if ((move_count_rra (find_next_memmean1_bottom((*stack_a)))) < move_count_ra(find_next_memmean1_top((*stack_a))) )
			{
				while (find_next_memmean1_bottom((*stack_a)) != stack_a->nbr)
					ft_rra(stack_a, 0);
			}

			ft_pb(stack_a, &stack_b, 0);
		}

		while ((*stack_a) && !is_sorted(stack_a))
		{
			if ((*stack_a)->nbr <= stack_max)
				ft_pb(stack_a, &stack_b, 0);
			else if ((ft_lst_last(*stack))->nbr <= stack_max)
				{
					ft_rra(stack_a, 0);
					ft_pb(stack_a, &stack_b, 0);
				}
			else if (move_count_ra(find_next_memmean1_top((*stack_a))) < (move_count_rra (find_next_memmean1_bottom((*stack_a)))))
			{
				while (find_next_memmean1_top((*stack_a)) != stack_a->nbr)
					ft_ra(stack_a, 0);
			}
			else if ((move_count_rra (find_next_memmean1_bottom((*stack_a)))) < move_count_ra(find_next_memmean1_top((*stack_a))) )
			{
				while (find_next_memmean1_bottom((*stack_a)) != stack_a->nbr)
					ft_rra(stack_a, 0);
			}

			ft_pb(stack_a, &stack_b, 0);
		}
	}

	while (stack_b)
	{
		if ((*stack_b)->nbr)

	}
}
