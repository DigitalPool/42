/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:00:34 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/19 20:25:02 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_min(t_stack *stack_a)
{
	int		i;

	i = stack_a->nbr;
	while (stack_a)
	{
		if (stack_a->nbr < i)
			i = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (i);
}

int	ft_max(t_stack *stack_a)
{
	int		i;

	i = stack_a->nbr;
	while (stack_a)
	{
		if (stack_a->nbr > i)
			i = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (i);
}

t_stack *ft_lst_last(t_stack *lst)
{
	if (lst == NULL)
		return NULL;

	while (lst->next != NULL)
		lst = lst->next;

	return lst;
}

int ft_lst_size(t_stack *lst)
{
	t_stack *tmp;
	int i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
