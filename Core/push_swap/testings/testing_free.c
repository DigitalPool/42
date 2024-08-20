
#include "../includes/push_swap.h"

#include <stdio.h>
#include <stdlib.h>

void ft_free_stack(t_stack **stack);

// Function prototypes
t_stack *ft_stack_new(int content);

int main(void) {
    // Create a stack
    t_stack *stack = ft_stack_new(1);
    stack->next = ft_stack_new(2);
    stack->next->next = ft_stack_new(3);

    // Free the stack
    ft_free_stack(&stack);

    // Check if the stack has been freed properly
    if (stack == NULL) {
        printf("Stack freed successfully.\n");
    } else {
        printf("Stack was not freed properly.\n");
    }

    return 0;
}

t_stack *ft_stack_new(int content) {
    t_stack *new = malloc(sizeof(t_stack));
    if (!new) {
        return NULL;
    }
    new->nbr = content;
    new->pos = 0;     // Assuming you have a pos field
    new->next = NULL;
    return new;
}

void ft_free_stack(t_stack **stack)
{
	t_stack *tmp;

	if (!stack || !*stack)
		return ;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
