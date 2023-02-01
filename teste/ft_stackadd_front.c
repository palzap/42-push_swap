/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:33:24 by pealexan          #+#    #+#             */
/*   Updated: 2023/01/23 15:32:26 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	ft_stackadd_front(t_stack **stack_a, t_stack *new)
{
	if (!new)
		return ;
	if (!stack_a)
	{
		*stack_a = new;
		return ;
	}
	new->next = *stack_a;
	*stack_a = new;
}
