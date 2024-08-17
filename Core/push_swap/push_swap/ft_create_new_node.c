/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_new_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:44:19 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/16 16:44:21 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_stack	*ft_create_new_node(int value)
{
	t_stack *new_node

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		ft_print_error();
	new_node->nbr = value;
	new_node->next = NULL;
	return (new_node);
}
