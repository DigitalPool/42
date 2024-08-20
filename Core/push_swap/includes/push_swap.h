/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:19:12 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/19 20:46:15 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
		long			nbr;
		long			pos;
		struct s_stack	*next;
		struct s_stack	*prev;
}		t_stack;

t_stack *ft_lst_last(t_stack *lst);
int ft_lst_size(t_stack *lst);
void	ft_free_stack(t_stack **stack);
int		ft_get_lst_size(t_stack *stack);
void	ft_sort_stack(t_stack **stack_a);
int		ft_min(t_stack *stack_a);
int		ft_max(t_stack *stack_a);
void	ft_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_three(t_stack **stack_a);
void	ft_print_error(void);
t_stack	*ft_create_new_node(int value);
int		is_sorted(t_stack **stack);
int		ft_check_duplicate(t_stack *a);
int		ft_isalpha_sym(int c);
void	check_alpha_sym(char **argv);
int		ft_Min_Max(int c);
void	add_from_back(t_stack **stack, t_stack *stack_new);
void	ft_add_args_to_stack(char **argv, t_stack **stack_a);
void	ft_sa(t_stack **a, int j);
void	ft_sb(t_stack **b, int j);
void	ft_ss(t_stack **a, t_stack **b, int j);
void	ft_pa(t_stack **a, t_stack **b, int j);
void	ft_pb(t_stack **a, t_stack **b, int j);
void	ft_ra(t_stack **a, int j);
void	ft_rb(t_stack **b, int j);
void	ft_rr(t_stack **a, t_stack **b, int j);
void	ft_rra(t_stack **a, int j);
void	ft_rrb(t_stack **b, int j);
void	ft_rrr(t_stack **a, t_stack **b, int j);
t_stack *ft_lst_last(t_stack *lst);
int	ft_atoi_stack(const char *str);
t_stack	*ft_sub_process(char **argv);
t_stack	*ft_get_stack(int argc, char **argv);
void	ft_freestr(char **lst);

#endif
