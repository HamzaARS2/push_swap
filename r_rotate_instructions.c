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
	write(1, "rra\n",4);
}

void	rrb_reverse_rotate_b(Stack *stack)
{
	shift_down_stack(stack);
	write(1, "rrb\n",4);
}

void	rrr_reverse_rotate_ab(Stack *stack_a, Stack *stack_b)
{
	shift_down_stack(stack_a);
	shift_down_stack(stack_b);
	write(1, "rrr\n",4);
}