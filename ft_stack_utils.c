/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:07:12 by helarras          #+#    #+#             */
/*   Updated: 2024/04/19 15:46:31 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack *stack, char **data)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		stack->arr[i] = ft_atol(data[i]);
		i++;
	}
}

int	clear_stack(t_stack *stack)
{
	free(stack->arr);
	stack->arr = 0;
	return (0);
}

void	shift_up_stack(t_stack *stack)
{
	size_t	i;

	if (!stack->size)
		return ;
	i = 0;
	while (i < stack->size - 1)
	{
		ft_swapi(stack->arr + i, stack->arr + (i + 1));
		i++;
	}
}

void	shift_down_stack(t_stack *stack)
{
	size_t	i;

	if (!stack->size)
		return ;
	i = stack->size - 1;
	while (i > 0)
	{
		ft_swapi(stack->arr + i, stack->arr + (i - 1));
		i--;
	}
}

int	check_stack(t_stack *stack_a, t_stack *stack_b)
{
	size_t	i;

	i = 1;
	if (stack_b->size > 0)
		return (0);
	while (i < stack_a->size)
	{
		if (stack_a->arr[i - 1] > stack_a->arr[i])
			return (0);
		i++;
	}
	return (1);
}
