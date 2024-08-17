#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define the stack structure
typedef struct s_stack
{
    int             nbr;
    struct s_stack  *next;
} t_stack;

// Function prototypes
int     ft_check_if_sorted(t_stack *stack);
t_stack *ft_stack_new(int content);
void    ft_stack_add_back(t_stack **stack, t_stack *new);
void    print_stack(t_stack *stack);

int main(void)
{
    t_stack *a = NULL;

    // Create stack `a`: 1 -> 2 -> 3
    ft_stack_add_back(&a, ft_stack_new(1));
    ft_stack_add_back(&a, ft_stack_new(2));
    ft_stack_add_back(&a, ft_stack_new(3));
	ft_stack_add_back(&a, ft_stack_new(4));

    printf("Stack A:\n");
    print_stack(a);

    // Check if stack `a` is sorted
    if (ft_check_if_sorted(a))
        printf("The stack is sorted.\n");
    else
        printf("The stack is not sorted.\n");

    // Free the memory used by the stack (not shown, but important in real usage)
    return (0);
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

// Function to print the stack
void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%d ", stack->nbr);
        stack = stack->next;
    }
    printf("\n");
}

int ft_check_if_sorted(t_stack *stack)
{
	while(stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);

}

// int ft_check_if_sorted(t_stack *stack)
// {
//     if (!stack)
//         return 1; // An empty stack is considered sorted

//     while (stack->next)
//     {
//         if (stack->nbr > stack->next->nbr)
//             return 0; // The stack is not sorted
//         stack = stack->next;
//     }
//     return 1; // The stack is sorted
// }
