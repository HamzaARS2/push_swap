/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:40:16 by helarras          #+#    #+#             */
/*   Updated: 2024/04/15 16:59:15 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(t_data data, int fill)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->arr = malloc(data.size * sizeof(int));
	if (!stack->arr)
	{
		free(stack);
		return (0);
	}
	stack->size = data.size;
	if (fill)
		fill_stack(stack, data.nums);
	return (stack);
}

int	is_empty(t_stack *stack)
{
	return (!stack->size);
}

int	push(t_stack *stack, int data)
{
	int		*newstack;
	size_t	i;

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

int	pop(t_stack *stack)
{
	int		elem;
	size_t	i;
	int		*newstack;

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
