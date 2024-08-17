#include "../includes/push_swap.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

t_stack *ft_stack_new(int content);  // Function to create a new node
void	ft_stack_add_back(t_stack **stack, t_stack *new);  // Function to add a node to the end of the stack
void	print_stack(t_stack *stack);  // Function to print the stack

int main(void)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    // Create stack `a`: 1 -> 2 -> 3
    ft_stack_add_back(&a, ft_stack_new(1));
    ft_stack_add_back(&a, ft_stack_new(2));
    ft_stack_add_back(&a, ft_stack_new(3));

    // Create stack `b`: 4 -> 5 -> 6
    ft_stack_add_back(&b, ft_stack_new(4));
    ft_stack_add_back(&b, ft_stack_new(5));
    ft_stack_add_back(&b, ft_stack_new(6));

    printf("Initial stacks:\n");
    printf("Stack A: ");
    print_stack(a);
    printf("Stack B: ");
    print_stack(b);

    // Perform the `sa` operation
    ft_sa(&a, 0);
    printf("\nAfter sa:\nStack A: ");
    print_stack(a);

    // Perform the `sb` operation
    ft_sb(&b, 0);
    printf("\nAfter sb:\nStack B: ");
    print_stack(b);

    // Perform the `ss` operation
    ft_ss(&a, &b, 0);
    printf("\nAfter ss:\nStack A: ");
    print_stack(a);
    printf("Stack B: ");
    print_stack(b);

    // Perform the `pa` operation (Move top of `b` to `a`)
    ft_pa(&a, &b, 0);
    printf("\nAfter pa:\nStack A: ");
    print_stack(a);
    printf("Stack B: ");
    print_stack(b);

    // Perform the `pb` operation (Move top of `a` to `b`)
    ft_pb(&a, &b, 0);
    printf("\nAfter pb:\nStack A: ");
    print_stack(a);
    printf("Stack B: ");
    print_stack(b);

    // Perform the `ra` operation
    ft_ra(&a, 0);
    printf("\nAfter ra:\nStack A: ");
    print_stack(a);

    // Perform the `rb` operation
    ft_rb(&b, 0);
    printf("\nAfter rb:\nStack B: ");
    print_stack(b);

    // Perform the `rr` operation
    ft_rr(&a, &b, 0);
    printf("\nAfter rr:\nStack A: ");
    print_stack(a);
    printf("Stack B: ");
    print_stack(b);

    // Perform the `rra` operation
    ft_rra(&a, 0);
    printf("\nAfter rra:\nStack A: ");
    print_stack(a);

    // Perform the `rrb` operation
    ft_rrb(&b, 0);
    printf("\nAfter rrb:\nStack B: ");
    print_stack(b);

    // Perform the `rrr` operation
    ft_rrr(&a, &b, 0);
    printf("\nAfter rrr:\nStack A: ");
    print_stack(a);
    printf("Stack B: ");
    print_stack(b);

    // Free the memory used by the stacks (not shown, but important in real usage)
    return (0);
}

// Function to print the stack (helper function)
void	print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%ld ", stack->nbr);
        stack = stack->next;
    }
    printf("\n");
}

// Function to create a new node
t_stack *ft_stack_new(int content)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (!new)
        exit(1); // Handle error appropriately
    new->nbr = content;
    new->next = NULL;
    return (new);
}

// Function to add a node to the end of the stack
void ft_stack_add_back(t_stack **stack, t_stack *new)
{
    t_stack *last;

    if (!*stack)
    {
        *stack = new;
        return;
    }
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = new;
}
