/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:34:32 by pealexan          #+#    #+#             */
/*   Updated: 2023/01/24 14:33:06 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	ft_stacksize(t_stack *stack)
{
	int	i;
	t_stack	*temp;

	i = 0;
	temp = stack;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
