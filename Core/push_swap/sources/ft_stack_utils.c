/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:00:34 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/23 20:42:03 by ashobajo         ###   ########.fr       */
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
int ft_second_min(t_stack *stack_a)
{
	int min;
	int second_min;

	if (!stack_a || !stack_a->next)
		return (0);

	min = ft_min(stack_a);
	second_min = INT_MAX;
	while (stack_a)
	{
		if (stack_a->nbr > min && stack_a->nbr < second_min)
			second_min = stack_a->nbr;
		stack_a = stack_a->next;
	}

	printf("second min:\n");
	printf ("%d\n", second_min);

	return (second_min);
}

int ft_stack_position (t_stack stack, int nbr)
{
	int i;

	i = 0;

	while (stack->nbr != nbr)
	{
		i++;
		stack = stack->next
	}

	stack->pos = 0
	return (i);
	// i is the position of that stack in the list
}

int	ft_findnbr_place_ina(t_stack *stack_a, int nbr_to_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_to_push < stack_a->nbr && nbr_to_push > ft_lstlast(stack_a)->nbr)
		i = 0;
	else if (nbr_to_push > ft_max(stack_a) || nbr_to_push < ft_min(stack_a))
		i = ft_stack_position(stack_a, ft_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->nbr > nbr_to_push || tmp->nbr < nbr_to_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}

int	ft_findnbr_place_inb(t_stack *stack_b, int nbr_to_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_to_push > stack_b->nbr && nbr_to_push < ft_lstlast(stack_b)->nbr)
		i = 0;
	else if (nbr_to_push > ft_max(stack_b) || nbr_to_push < ft_min(stack_b))
		i = ft_stack_position(stack_b, ft_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->nbr < nbr_to_push || tmp->nbr > nbr_to_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}
