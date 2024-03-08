#include "push_swap.h"

void    fill_stack(Stack *stack, char **data)
{
    int i;

    i = 0;
    while (i < stack->size)
    {
        stack->content[i] = ft_atoi(data[i]);
        i++;
    }
}

int    clear_stack(Stack *stack)
{
    free(stack->content);
    stack->content = 0;
    return (0);
}

void    shift_up_stack(Stack *stack)
{
    size_t i;

    i = 0;
    while (i < stack->size - 1)
    {
        ft_swapi(stack->content + i, stack->content + (i + 1));
        i++;
    }
}

void    shift_down_stack(Stack *stack)
{
    size_t i;

    i = stack->size - 1;
    while (i > 0)
    {
        ft_swapi(stack->content + i, stack->content + (i - 1));
        i--;
    }
}
