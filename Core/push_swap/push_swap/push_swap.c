/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:51:42 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/19 20:25:43 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;

	stack_a = ft_get_stack (argc, argv);
	if(!stack_a || ft_check_duplicate(stack_a))
	{
		ft_free_stack(stack_a);
		ft_print_error();
	}
	if(!is_sorted(stack_a))
		ft_sort_stack(stack_a);
	ft_free_stack(stack_a);
	return (0);
}
