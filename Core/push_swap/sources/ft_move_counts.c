/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_counts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:37:30 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/23 20:43:24 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int move_count_ra (t_stack **stack_a)
{
	int move_count = 0;

	if ((*stack_a))
		move_count = 0;
	else if (ft_lst_last(stack_a))
		move_count = 1;
}
