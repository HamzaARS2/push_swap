#include "push_swap.h"

int get_best_index(int *arr,int number, size_t size) {
    int i;
    int best_index;
    int biggest_i;

    biggest_i = 0;
    best_index = -1;
    for (i = 0; i < size; i++) {
        if (number > arr[i]) {
            if (best_index == -1 || arr[i] > arr[best_index]) {
                best_index = i;
            }
        }
        if (arr[i] > arr[biggest_i])
            biggest_i = i;
    }
    if (best_index == -1)
        return (biggest_i);
    return best_index;
}

t_move  count_moves(size_t index, size_t size, int stack_type)
{
    t_move move;

     if (index > (size / 2)) {
        move.type = 1;
        move.count = size - index;
    } else {
        move.type = 0;
        move.count = index;
    }
    if (move.count == 0)
        move.type = -1;
    move.stack_type = stack_type;
    return (move);
}

void    execute_move(Stack *stack, t_move move)
{
    while (move.count--)
    {
        if (!move.stack_type)
        {
            if (!move.type)
                ra_rotate_a(stack);
            else
                rra_reverse_rotate_a(stack);
        } 
        else
        {
            // stack b
            if (!move.type)
                rb_rotate_b(stack);
            else
                rrb_reverse_rotate_b(stack);
        }

    }
}