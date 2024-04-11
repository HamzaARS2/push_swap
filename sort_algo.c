#include "push_swap.h"

ab_move count_all_moves(Stack *stack_a, Stack *stack_b, size_t index)
{
    ab_move m;
    int diff;

    m.b_moves = count_moves(get_best_index(stack_b->arr, stack_a->arr[index], stack_b->size), stack_b->size, 1);
    m.a_moves = count_moves(index, stack_a->size, 0);
    m.rr = 0;
    m.rrr = 0;
    diff = m.b_moves.count - m.a_moves.count;
    if (m.b_moves.type == m.a_moves.type && m.b_moves.type == 0)
    {
        if (diff >= 0)
            m.rr = m.b_moves.count - diff;
        else
            m.rr = m.a_moves.count - (-diff);
        m.b_moves.count -= m.rr;
        m.a_moves.count -= m.rr;
    }
    else if (m.b_moves.type == m.a_moves.type && m.b_moves.type == 1)
    {
         if (diff >= 0)
            m.rrr = m.b_moves.count - diff;
        else
            m.rrr = m.a_moves.count - (-diff);
        m.b_moves.count -= m.rrr;
        m.a_moves.count -= m.rrr;
    }
    return (m);
}

void    execute_all_moves(Stack *stack_a, Stack *stack_b, ab_move moves)
{
    while (moves.rr || moves.rrr)
    {
        if (moves.rr--)
            rr_rotate_ab(stack_a, stack_b);
        if (moves.rrr--)
            rrr_reverse_rotate_ab(stack_a, stack_b);
    }
    execute_move(stack_b, moves.b_moves);
    execute_move(stack_a, moves.a_moves);
}


ab_move find_cheapest_number(Stack *stack_a, Stack *stack_b)
{
    int i;
    int least_moves;
    int moves;
    ab_move cm;
    ab_move ab_moves;

    least_moves = 2147483647;
    i = 0;
    while (i < stack_a->size)
    {
        if (least_moves == 1)
            return (ab_moves);
        cm = count_all_moves(stack_a, stack_b, i);
        moves = cm.a_moves.count + cm.b_moves.count + cm.rr + cm.rrr + 1;
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

static void print_stack(Stack *stack) {
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
void    sort(Stack *stack_a, Stack *stack_b)
{
    pb_push_b(stack_a, stack_b);
    pb_push_b(stack_a, stack_b);
    print_stack(stack_a);
    print_stack(stack_b);
    while (stack_a->size > 3)
    {
        execute_all_moves(stack_a, stack_b, find_cheapest_number(stack_a, stack_b));
        print_stack(stack_a);
        print_stack(stack_b);
    }
}