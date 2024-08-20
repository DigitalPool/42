/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:52:43 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/19 20:18:27 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack **stack)
{
	while((*stack)->next)
	{
		if ((*stack)->nbr > (*stack)->next->nbr)
			return (0);
		(*stack) = (*stack)->next;
	}
	return (1);
}
