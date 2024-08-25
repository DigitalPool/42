/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_means.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:51:36 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/25 14:08:33 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int find_next_memmean1_top(t_stack **stack, int mean1_stack_a)
{
	t_stack **current = stack;

	while ((*current))
	{
		if (((*current))->nbr <= mean1_stack_a)
			return (*current)->nbr;
		(*current) = (*current)->next;
	}
	return -1; // Return -1 if no element is found
}

int find_next_memmean1_bottom(t_stack **stack, int mean1_stack_a)
{
	t_stack **current = stack;

	// Traverse to the last element
	while ((*current)->next)
	{
		(*current) = (*current)->next;
	}

	// Traverse backwards
	while ((*current))
	{
		if ((*current)->nbr <= mean1_stack_a)
			return (*current)->nbr;
		(*current) = (*current)->prev;
	}
	return -1; // Return -1 if no element is found
}

int find_next_memmean_top(t_stack **stack, int stack_mean)
{
	t_stack **current = stack;

	while ((*current))
	{
		if ((*current)->nbr <= stack_mean)
			return (*current)->nbr;
		(*current) = (*current)->next;
	}
	return -1; // Return -1 if no element is found
}

int find_next_memmean_bottom(t_stack **stack, int stack_mean)
{
	t_stack **current = stack;

	// Traverse to the last element
	while ((*current)->next)
	{
		(*current) = (*current)->next;
	}

	// Traverse backwards
	while ((*current))
	{
		if ((*current)->nbr <= stack_mean)
			return (*current)->nbr;
		(*current) = (*current)->prev;
	}
	return -1; // Return -1 if no element is found
}

int find_next_memmean3_top(t_stack **stack, int mean3_stack)
{
	t_stack **current = stack;

	while ((*current))
	{
		if ((*current)->nbr <= mean3_stack)
			return (*current)->nbr;
		(*current) = (*current)->next;
	}
	return -1; // Return -1 if no element is found
}

int find_next_memmean3_bottom(t_stack **stack, int mean3_stack)
{
	t_stack **current = stack;

	// Traverse to the last element
	while ((*current)->next)
	{
		(*current) = (*current)->next;
	}

	// Traverse backwards
	while ((*current))
	{
		if ((*current)->nbr <= mean3_stack)
			return (*current)->nbr;
		(*current) = (*current)->prev;
	}
	return -1; // Return -1 if no element is found
}
