#include "push_swap.h"

void print_stack(Stack *stack) {
    printf("Stack contents: [");
    
    if (!is_empty(stack)) {
        for (size_t i = 0; i < stack->size; ++i) {
            printf("%d", stack->content[i]);
            if (i < stack->size - 1) {
                printf(", ");
            }
        }
    }

    printf("]\n");
}

void    sort_three(Stack *stack) 
{
    if (stack->content[0] > stack->content[1] && stack->content[0] > stack->content[stack->size - 1])
        ra_rotate_a(stack);
    if (stack->content[stack->size - 1] < stack->content[1] && stack->content[stack->size - 1] < stack->content[0])
        rra_reverse_rotate_a(stack);
    if (stack->content[1] > stack->content[stack->size - 1])
        rra_reverse_rotate_a(stack);
    if (stack->content[0] > stack->content[1])
        sa_swap_a(stack);
}

void    sort_five(Stack *stack_a, Stack *stack_b) 
{
    int max_i;

    while (stack_a->size > 3)
    {
        max_i = max_index(stack_a->content, stack_a->size);
        if (max_i <= stack_a->size / 2)
        {
            while (--max_i + 1)
                ra_rotate_a(stack_a);
        }
        else 
        {
            while ((stack_a->size) - (max_i++))
                rra_reverse_rotate_a(stack_a);
        }
        pb_push_b(stack_b, stack_a);
    }
    sort_three(stack_a);
    while (stack_b->size)
    {
        pa_push_a(stack_a, stack_b);
        ra_rotate_a(stack_a);
    }
}

int main(int argc, char *argv[])
{
    Stack *stack_a;
    Stack *stack_b;
    int size;
    int *a;

    size = argc - 1;
    if (!size)
        return (0);
    stack_a = init_stack(size, argv + 1, 1);
    stack_b = init_stack(0, 0, 0);
    print_stack(stack_a);
    if (stack_a->size <= 3)
        sort_three(stack_a);
    else if (stack_a->size <= 5)
        sort_five(stack_a, stack_b);
    print_stack(stack_a);
}