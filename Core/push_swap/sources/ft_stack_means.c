/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_means.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:04:47 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/23 20:33:09 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int mean1_stack(t_stack **stack_a)
{
	int mean1 = 0;
	int sum = 0;
	int count = 0;

	while ((*stack_a))
		{
			if ((*stack_a)->nbr <= (ft_stack_mean(stack_a)))
				{
					sum += (*stack_a)->nbr;
					count++;
				}
			(*stack_a) = (*stack_a)->next;
		}

	mean1 = sum/count;

	return (mean);
}

int mean3_stack(t_stack **stack_a)
{
	int mean3 = 0;
	int sum = 0;
	int count = 0;

	while ((*stack_a))
		{
			if ((*stack_a)->nbr >= (ft_stack_mean(stack_a)))
				{
					sum += (*stack_a)->nbr;
					count++;
				}
			(*stack_a) = (*stack_a)->next;
		}

	mean3 = sum/count;

	return (mean);
}
