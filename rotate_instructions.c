/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:30:47 by helarras          #+#    #+#             */
/*   Updated: 2024/03/07 19:34:22 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rotate_a(Stack *stack)
{
	shift_up_stack(stack);
	write(1, "ra\n",3);
}

void	rb_rotate_b(Stack *stack)
{
	shift_up_stack(stack);
	write(1, "rb\n",3);
}

void	rr_rotate_ab(Stack *stack_a, Stack *stack_b)
{
	shift_up_stack(stack_a);
	shift_up_stack(stack_b);
	write(1, "rr\n",3);
}