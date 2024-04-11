/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:40:16 by helarras          #+#    #+#             */
/*   Updated: 2024/03/07 20:52:45 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Stack   *init_stack(size_t size, char **data, int fill)
{
    Stack *stack;

    stack = malloc(sizeof(Stack));
    if (!stack)
        return (0);   
    stack->arr = malloc(size * sizeof(int));
    if (!stack->arr)
    {
        free(stack);
        return (0);        
    }
    stack->size = size;
    if (fill)
        fill_stack(stack, data);
    return (stack);
}

int is_empty(Stack *stack)
{
    return (!stack->size);
}

int    push(Stack *stack, int data)
{
    int *newstack;
    size_t i;

    i = 0;
    newstack = malloc((stack->size + 1) * sizeof(int));
    if (!newstack)
        return (-1);
    newstack[i] = data;
    while (i < stack->size)
    {
        newstack[i + 1] = stack->arr[i]; 
        i++;
    }
    clear_stack(stack);
    stack->arr = newstack;
    stack->size++;
    return (stack->size);
}

int pop(Stack *stack)
{
    int elem;
    size_t i;
    int *newstack;

    i = 0;
    if (is_empty(stack))
        return (-1);
    newstack = malloc((stack->size - 1) * sizeof(int));
    if (!newstack)
        return (-1);
    elem = stack->arr[i];
    while (i < stack->size - 1)
    {
        newstack[i] = stack->arr[i + 1];
        i++;
    }
    clear_stack(stack);
    stack->arr = newstack;
    stack->size--;
    return (elem);
}










































