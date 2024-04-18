/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:50:10 by helarras          #+#    #+#             */
/*   Updated: 2024/04/18 12:18:19 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H
# include <stdlib.h>

typedef struct stack
{
	int		*arr;
	size_t	size;
}			t_stack;

typedef struct data
{
	char	**nums;
	size_t	size;
}			t_data;

t_stack		*init_stack(t_data data, int fill);
int			is_empty(t_stack *stack);
int			push(t_stack *stack, int data);
int			pop(t_stack *stack);
void		fill_stack(t_stack *stack, char **data);
int			clear_stack(t_stack *stack);
void		shift_up_stack(t_stack *stack);
void		shift_down_stack(t_stack *stack);
#endif