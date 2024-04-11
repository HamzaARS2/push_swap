#ifndef FT_STACK_H
# define FT_STACK_H
# include <stdlib.h>

typedef struct
{
    int *arr;
    size_t size;
} Stack;

Stack   *init_stack(size_t size, char **data, int fill);
int     is_empty(Stack *stack);
int     push(Stack *stack, int data);
int     pop(Stack *stack);
void    fill_stack(Stack *stack, char **data);
int     clear_stack(Stack *stack);
void    shift_up_stack(Stack *stack);
void    shift_down_stack(Stack *stack);
#endif