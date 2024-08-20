
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack {
    int             nbr;
    struct s_stack  *next;
} t_stack;

t_stack *ft_stack_new(int content);
int     ft_get_lst_size(t_stack *stack);
void ft_free_stack(t_stack **stack);

int main(void) {
    // Create a stack with 3 elements
    t_stack *stack = ft_stack_new(1);
    stack->next = ft_stack_new(2);
    stack->next->next = ft_stack_new(3);

    // Count the number of elements in the stack
    int count = ft_get_lst_size(stack);

    // Expected number of elements
    int expected_count = 3;

    // Check if the count is correct
    if (count == expected_count) {
        printf("Count is correct: %d elements.\n", count);
    } else {
        printf("Count is incorrect: got %d, expected %d.\n", count, expected_count);
    }

    // Free the stack
    ft_free_stack(&stack);

    return 0;
}

// Function to create a new stack node
t_stack *ft_stack_new(int content) {
    t_stack *new = malloc(sizeof(t_stack));
    if (!new) {
        return NULL;
    }
    new->nbr = content;
    new->next = NULL;
    return new;
}

int ft_get_lst_size(t_stack *stack)
{
	int	i;
	
	while (stack)
	{
		stack = stack->next;
		i += 1;
	}
	return (i);
}

// Function to free the stack (as defined earlier)
void ft_free_stack(t_stack **stack) {
    t_stack *tmp;
    while (*stack) {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
    *stack = NULL;
}
