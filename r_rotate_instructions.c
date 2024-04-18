/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:30:29 by helarras          #+#    #+#             */
/*   Updated: 2024/04/17 20:02:48 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_reverse_rotate_a(t_stack *stack, int display_move)
{
	shift_down_stack(stack);
	if (display_move)
		write(1, "rra\n", 4);
}

void	rrb_reverse_rotate_b(t_stack *stack, int display_move)
{
	shift_down_stack(stack);
	if (display_move)
		write(1, "rrb\n", 4);
}

void	rrr_reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b,
		int display_move)
{
	shift_down_stack(stack_a);
	shift_down_stack(stack_b);
	if (display_move)
		write(1, "rrr\n", 4);
}
