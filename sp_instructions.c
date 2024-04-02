/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:27:18 by helarras          #+#    #+#             */
/*   Updated: 2024/03/07 19:34:29 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_swap_a(Stack *stack)
{
	if (stack->size <= 1)
		return ;
	ft_swapi(stack->content, stack->content + 1);
	write(1, "sa\n",3);
}

void	sb_swap_b(Stack *stack)
{
	if (stack->size <= 1)
		return ;
	ft_swapi(stack->content, stack->content + 1);
	write(1, "sb\n",3);
}

void	ss_swap_ab(Stack *stack_a, Stack *stack_b)
{
	sa_swap_a(stack_a);
	sb_swap_b(stack_b);
	write(1, "ss\n",3);
}

void	pa_push_a(Stack *stack_a, Stack *stack_b)
{
	push(stack_a, pop(stack_b));
	write(1, "pa\n",3);
}

void	pb_push_b(Stack *stack_b, Stack *stack_a)
{
	push(stack_b, pop(stack_a));
	write(1, "pb\n",3);
}


