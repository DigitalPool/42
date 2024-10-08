/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_ba.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:14:12 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/25 13:16:45 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/push_swap.h"

// int	ft_do_rarb_a(t_stack *stack_a, t_stack *stack_b, int cnbr)
// {
// 	int	i;

// 	i = ft_findnbr_place_ina(stack_a, nbr);
// 	if (i < ft_find_pos(stack_b, nbr))
// 		i = ft_find_pos(stack_b, nbr);
// 	return (i);
// }

// // This function calculates the required amount of rotation.
// // Calculations are done for rra+rrb case.
// int	ft_case_rrarrb_a(t_stack *a, t_stack *b, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_find_place_a(a, c))
// 		i = ft_lstsize(a) - ft_find_place_a(a, c);
// 	if ((i < (ft_lstsize(b) - ft_find_index(b, c))) && ft_find_index(b, c))
// 		i = ft_lstsize(b) - ft_find_index(b, c);
// 	return (i);
// }

// // This function calculates the required amount of rotation.
// // Calculations are done for ra+rrb case.
// int	ft_case_rarrb_a(t_stack *a, t_stack *b, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_find_index(b, c))
// 		i = ft_lstsize(b) - ft_find_index(b, c);
// 	i = ft_find_place_a(a, c) + i;
// 	return (i);
// }

// // This function calculates the required amount of rotation.
// // Calculations are done for rra+rb case.
// int	ft_case_rrarb_a(t_stack *a, t_stack *b, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_find_place_a(a, c))
// 		i = ft_lstsize(a) - ft_find_place_a(a, c);
// 	i = ft_find_index(b, c) + i;
// 	return (i);
// }
