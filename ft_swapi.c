/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:08:07 by helarras          #+#    #+#             */
/*   Updated: 2024/04/15 20:08:46 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swapi(int *n1, int *n2)
{
	int	temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
