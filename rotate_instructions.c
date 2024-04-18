/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:30:47 by helarras          #+#    #+#             */
/*   Updated: 2024/04/17 19:58:24 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rotate_a(t_stack *stack, int display_move)
{
	shift_up_stack(stack);
	if (display_move)
		write(1, "ra\n", 3);
}

void	rb_rotate_b(t_stack *stack, int display_move)
{
	shift_up_stack(stack);
	if (display_move)
		write(1, "rb\n", 3);
}

void	rr_rotate_ab(t_stack *stack_a, t_stack *stack_b, int display_move)
{
	shift_up_stack(stack_a);
	shift_up_stack(stack_b);
	if (display_move)
		write(1, "rr\n", 3);
}
