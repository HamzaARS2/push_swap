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
    print_stack(stack_a);
    if (stack_a->size <= 3)
        sort_three(stack_a);
    else
        sort(stack_a, stack_b);

    // int arr_a[] = {7,1,6,3,9,4,8};
    // size_t size_a = sizeof(arr_a) / sizeof(arr_a[0]);
    // Stack stack_a = {arr_a, size_a};
    // int arr_b[] = {2,5};
    // size_t size_b = sizeof(arr_b) / sizeof(arr_b[0]);
    // Stack stack_b = {arr_b, size_b};
    //  // Display the result
    // ab_move result = find_cheapest_number(&stack_a, &stack_b);
    // printf("Cheapest index: %zu\n", result.cheapest_index);
    // printf("A moves: (%d, %zu)\n", result.a_moves.type, result.a_moves.count);
    // printf("B moves: (%d, %zu)\n", result.b_moves.type, result.b_moves.count);
    // printf("combined: type=rr, count=%zu\n", result.rr);
    // printf("combined: type=rrr, count=%zu\n", result.rrr);

}