/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_args_to_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:53:41 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/17 13:52:54 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_from_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_lstlast (*stack))->next = stack_new
}

void ft_add_args_to_stack(char **argv, t_stack **stack_a)
{
	long	i;

	i = 1;
	while (argv[i] != NULL)
	{
		add_from_back (stack_a, ft_create_new_node(ft_atoi(argv[i])));
		i++;
	}
}
