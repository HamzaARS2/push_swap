#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include "ft_stack.h"
# include "instructions.h"

typedef struct move{
    int stack_type;
    int type;
    size_t count;
} t_move;

typedef struct 
{
    t_move a_moves;
    t_move b_moves;
    int rr;
    int rrr;
    size_t cheapest_index;
} ab_move;

int     ft_atoi(const char *str);
void    ft_swapi(int *n1, int *n2);
int     max_index(int *nums, size_t size);
int get_best_index(int *arr,int number, size_t size);
t_move  count_moves(size_t index, size_t size, int stack_type);
void    execute_move(Stack *stack, t_move move);
ab_move count_all_moves(Stack *stack_a, Stack *stack_b, size_t index);
ab_move find_cheapest_number(Stack *stack_a, Stack *stack_b);
void    sort(Stack *stack_a, Stack *stack_b);


#endif