/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:09:11 by helarras          #+#    #+#             */
/*   Updated: 2024/04/18 13:18:59 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H
# include "ft_stack.h"

void	sa_swap_a(t_stack *stack, int display_move);
void	sb_swap_b(t_stack *stack, int display_move);
void	ss_swap_ab(t_stack *stack_a, t_stack *stack_b, int display_move);
void	pa_push_a(t_stack *stack_a, t_stack *stack_b, int display_move);
void	pb_push_b(t_stack *stack_a, t_stack *stack_b, int display_move);

void	ra_rotate_a(t_stack *stack, int display_move);
void	rb_rotate_b(t_stack *stack, int display_move);
void	rr_rotate_ab(t_stack *stack_a, t_stack *stack_b, int display_move);

void	rra_reverse_rotate_a(t_stack *stack, int display_move);
void	rrb_reverse_rotate_b(t_stack *stack, int display_move);
void	rrr_reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b,
			int display_move);

#endif