#include "push_swap.h"

t_move_ab count_all_moves(Stack *stack_a, Stack *stack_b, size_t index)
{
    t_move_ab m;

     m = (t_move_ab){.cheapest_index = 0,.rr = 0,.rrr = 0};
    m.b_moves = count_b_moves(get_best_index(stack_b->arr, stack_a->arr[index], stack_b->size), stack_b->size);
    m.a_moves = count_a_moves(index, stack_a->size);

    while (m.b_moves.rb && m.a_moves.ra)
    {
        m.rr++;
        m.b_moves.rb--;
        m.a_moves.ra--;
    }
     while (m.b_moves.rrb && m.a_moves.rra)
    {
        m.rrr++;
        m.b_moves.rrb--;
        m.a_moves.rra--;
    }
    return (m);
}

t_move_ab find_cheapest_number(Stack *stack_a, Stack *stack_b)
{
    int i;
    int least_moves;
    int moves;
    t_move_ab cm;
    t_move_ab ab_moves;

    least_moves = 2147483647;
    i = 0;
    while (i < stack_a->size)
    {
        if (least_moves == 1)
            return (ab_moves);
        cm = count_all_moves(stack_a, stack_b, i);
        moves = cm.a_moves.ra + cm.a_moves.rra + cm.b_moves.rb + cm.b_moves.rrb+ cm.rr + cm.rrr + 1;
        if (moves < least_moves)
        {
            least_moves = moves;
            ab_moves = cm;
            ab_moves.cheapest_index = i;
        }
        i++;
    }
    return (ab_moves);
}

int find_min_index(Stack *stack)
{
    int i;
    int min_i;

    min_i = 0;
    i = 0;
    while (i < stack->size)
    {
        if (stack->arr[min_i] > stack->arr[i])
            min_i = i;
        i++;
    }
    return (min_i);
}

void    sort(Stack *stack_a, Stack *stack_b)
{
    pb_push_b(stack_a, stack_b);
    pb_push_b(stack_a, stack_b);
    while (stack_a->size > 3)
    {
        execute_moves(stack_a, stack_b, find_cheapest_number(stack_a, stack_b));
        pb_push_b(stack_a, stack_b);
    }
    sort_three(stack_a);
    while (stack_b ->size)
    {
        t_move_a a_moves = count_a_moves(get_best_a_index(stack_a->arr, stack_b->arr[0], stack_a->size), stack_a->size);
        while (a_moves.ra--)
            ra_rotate_a(stack_a);
        while (a_moves.rra--)
            rra_reverse_rotate_a(stack_a);
        pa_push_a(stack_a, stack_b);
    }

    int min_index = find_min_index(stack_a);
    t_move_a last_moves = count_a_moves(min_index, stack_a->size);
    while (last_moves.ra--)
            ra_rotate_a(stack_a);
    while (last_moves.rra--)
            rra_reverse_rotate_a(stack_a);
}
