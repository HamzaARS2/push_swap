/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:29:00 by helarras          #+#    #+#             */
/*   Updated: 2024/04/18 16:20:32 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H

char	**read_instructions(void);
int		execute_instruction(t_stack stack_a, t_stack stack_b,
			char *instruction);
void	execute_all(t_stack *stack_a, t_stack *stack_b);
int		check_stack(t_stack *stack_a, t_stack *stack_b);

#endif