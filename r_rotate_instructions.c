/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:30:29 by helarras          #+#    #+#             */
/*   Updated: 2024/03/07 19:34:31 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_reverse_rotate_a(Stack *stack)
{
	shift_down_stack(stack);
}

void	rrb_reverse_rotate_b(Stack *stack)
{
	shift_down_stack(stack);
}

void	rrr_reverse_rotate_ab(Stack *stack_a, Stack *stack_b)
{
	rra_reverse_rotate_a(stack_a);
	rrb_reverse_rotate_b(stack_b);
}