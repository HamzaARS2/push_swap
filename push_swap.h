#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include "ft_stack.h"
# include "instructions.h"

typedef struct move_a{
    int ra;
    int rra;
} t_move_a;

typedef struct move_b{
    int rb;
    int rrb;
} t_move_b;

typedef struct move{
    t_move_a a_moves;
    t_move_b b_moves;
    int cheapest_index;
    int rr;
    int rrr;
} t_move_ab;


int         ft_atoi(const char *str);
void        ft_swapi(int *n1, int *n2);
void        sort_three(Stack *stack);
int         max_index(int *nums, size_t size);
int         get_best_index(int *arr,int number, size_t size);
t_move_b    count_b_moves(size_t index, size_t size);
t_move_a    count_a_moves(size_t index, size_t size);
t_move_ab   count_all_moves(Stack *stack_a, Stack *stack_b, size_t index);
t_move_ab   find_cheapest_number(Stack *stack_a, Stack *stack_b);
void        sort(Stack *stack_a, Stack *stack_b);
void        execute_moves(Stack *stack_a, Stack *stack_b, t_move_ab moves);
int         get_best_a_index(int *arr,int number, size_t size);

#endif