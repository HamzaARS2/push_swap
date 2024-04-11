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

int get_best_a_index(int *arr,int number, size_t size) {
    int i;
    int best_index;
    int smallest_i;

    smallest_i = 0;
    best_index = -1;
    for (i = 0; i < size; i++) {
        if (arr[i] > number) {
            if (best_index == -1 || arr[i] < arr[best_index]) {
                best_index = i;
            }
        }
        if (arr[i] < arr[smallest_i])
            smallest_i = i;
    }
    if (best_index == -1)
        return (smallest_i);
    return best_index;
}

t_move_b    count_b_moves(size_t index, size_t size)
{
    t_move_b move_b;

    move_b = (t_move_b){0};
    if (index > (size / 2)) 
        move_b.rrb = size - index;
    else
        move_b.rb = index;
    return (move_b);
}

t_move_a    count_a_moves(size_t index, size_t size)
{
    t_move_a move_a;

    move_a = (t_move_a){0};
    if (index > (size / 2)) 
        move_a.rra = size - index;
    else
        move_a.ra = index;
    return (move_a);
}

void    execute_moves(Stack *stack_a, Stack *stack_b, t_move_ab moves)
{
    while (moves.rr--)
        rr_rotate_ab(stack_a, stack_b);
    while (moves.rrr--)
        rrr_reverse_rotate_ab(stack_a, stack_b);
    while (moves.b_moves.rb--)
        rb_rotate_b(stack_b);
    while (moves.a_moves.ra--)
        ra_rotate_a(stack_a);
    while (moves.b_moves.rrb--)
        rrb_reverse_rotate_b(stack_b);
    while (moves.a_moves.rra--)
        rra_reverse_rotate_a(stack_a);
}
