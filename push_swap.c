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

int main(int argc, char *argv[])
{
    Stack *stack_a;
    Stack *stack_b;
    int size;

    size = argc - 1;
    if (!size)
        return (0);
    stack_a = init_stack(size, argv + 1, 1);
    stack_b = init_stack(size, argv + 1, 0);
    printf("result: %i\n", stack_a->content[0]);
    print_stack(stack_a);
    //printf("size: %zu\n", stack_a->size);
    
}