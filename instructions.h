#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H
#include "ft_stack.h"

void	sa_swap_a(Stack *stack);
void	sb_swap_b(Stack *stack);
void	ss_swap_ab(Stack *stack_a, Stack *stack_b);
void	pa_push_a(Stack *stack_a, Stack *stack_b);
void	pb_push_b(Stack *stack_b, Stack *stack_a);

void	ra_rotate_a(Stack *stack);
void	rb_rotate_b(Stack *stack);
void	rr_rotate_ab(Stack *stack_a, Stack *stack_b);

void	rra_reverse_rotate_a(Stack *stack);
void	rrb_reverse_rotate_b(Stack *stack);
void	rrr_reverse_rotate_ab(Stack *stack_a, Stack *stack_b);




#endif