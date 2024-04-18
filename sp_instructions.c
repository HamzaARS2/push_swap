/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:27:18 by helarras          #+#    #+#             */
/*   Updated: 2024/04/17 19:54:13 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_swap_a(t_stack *stack, int display_move)
{
	if (stack->size <= 1)
		return ;
	ft_swapi(stack->arr, stack->arr + 1);
	if (display_move)
		write(1, "sa\n", 3);
}

void	sb_swap_b(t_stack *stack, int display_move)
{
	if (stack->size <= 1)
		return ;
	ft_swapi(stack->arr, stack->arr + 1);
	if (display_move)
		write(1, "sb\n", 3);
}

void	ss_swap_ab(t_stack *stack_a, t_stack *stack_b, int display_move)
{
	if (stack_a->size > 1)
		ft_swapi(stack_a->arr, stack_a->arr + 1);
	if (stack_b->size > 1)
		ft_swapi(stack_b->arr, stack_b->arr + 1);
	if (display_move)
		write(1, "ss\n", 3);
}

void	pa_push_a(t_stack *stack_a, t_stack *stack_b, int display_move)
{
	push(stack_a, pop(stack_b));
	if (display_move)
		write(1, "pa\n", 3);
}

void	pb_push_b(t_stack *stack_a, t_stack *stack_b, int display_move)
{
	push(stack_b, pop(stack_a));
	if (display_move)
		write(1, "pb\n", 3);
}
