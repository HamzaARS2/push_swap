#include "push_swap.h"

void    fill_stack(Stack *stack, char **data)
{
    int i;

    i = 0;
    while (i < stack->size)
    {
        stack->arr[i] = ft_atoi(data[i]);
        i++;
    }
}

int    clear_stack(Stack *stack)
{
    free(stack->arr);
    stack->arr = 0;
    return (0);
}

void    shift_up_stack(Stack *stack)
{
    size_t i;

    i = 0;
    while (i < stack->size - 1)
    {
        ft_swapi(stack->arr + i, stack->arr + (i + 1));
        i++;
    }
}

void    shift_down_stack(Stack *stack)
{
    size_t i;

    i = stack->size - 1;
    while (i > 0)
    {
        ft_swapi(stack->arr + i, stack->arr + (i - 1));
        i--;
    }
}
