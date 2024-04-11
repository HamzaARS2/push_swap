#include "push_swap.h"

void print_stack(Stack *stack) {
    printf("Stack arrs: [");
    
    if (!is_empty(stack)) {
        for (size_t i = 0; i < stack->size; ++i) {
            printf("%d", stack->arr[i]);
            if (i < stack->size - 1) {
                printf(", ");
            }
        }
    }

    printf("]\n");
}

void    sort_three(Stack *stack) 
{
    if (stack->arr[0] > stack->arr[1] && stack->arr[0] > stack->arr[stack->size - 1])
        ra_rotate_a(stack);
    if (stack->arr[stack->size - 1] < stack->arr[1] && stack->arr[stack->size - 1] < stack->arr[0])
        rra_reverse_rotate_a(stack);
    if (stack->arr[1] > stack->arr[stack->size - 1])
        rra_reverse_rotate_a(stack);
    if (stack->arr[0] > stack->arr[1])
        sa_swap_a(stack);
}

int main(int argc, char *argv[])
{
    Stack *stack_a;
    Stack *stack_b;
    int size;
    
    size = argc - 1;
    if (!size)
        return (0);
    stack_a = init_stack(size, argv + 1, 1);
    stack_b = init_stack(0, 0, 0);
    if (stack_a->size <= 3)
        sort_three(stack_a);
    else
        sort(stack_a, stack_b);
    print_stack(stack_a);
}