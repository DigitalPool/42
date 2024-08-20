/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_lst_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:32:11 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/19 19:42:14 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft_get_lst_size(t_stack *stack)
{
	int	i;

	i	= 0;

	if (!stack)
		return (0);

	while (stack)
	{
		while (stack->next != NULL)
		{
			i++;
		}
		stack = stack->next;
	}

	return (i);

}
