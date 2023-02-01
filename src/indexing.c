/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleal <pleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:55:54 by pleal             #+#    #+#             */
/*   Updated: 2023/02/01 17:48:32 by pleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_position_a(t_arrays *a, int index)
{
	int		position;
	int		diff;
	int		min;

	position = 0;
	min = INT_MAX;
	a->i = 0;
	diff = 0;
	while (a->i < a->e_a)
	{
		diff = a->s_a[a->i] - a->s_b[index];
		if (diff > 0 && diff < min)
		{
			position = a->i;
			min = diff;
		}
		a->i++;
	}
	a->ra[a->s_b[index]] = position;
	a->rra[a->s_b[index]] = a->e_a - position;
}

void	ft_position(t_arrays *a, int index)
{
	int		position;
	int		diff;
	int		min;

	position = 0;
	min = INT_MAX;
	a->i = 0;
	diff = 0;
	while (a->i < a->e_a)
	{
		diff = a->s_a[a->i] - a->s_b[index];
		if (diff > 0 && diff < min)
		{
			position = a->i;
			min = diff;
		}
		a->i++;
	}
	a->ra[a->s_b[index]] = position;
	a->rra[a->s_b[index]] = a->e_a - position;
}

void	ft_indexing(t_arrays *a)
{
	int	index;

	a->i = 0;
	while (a->i < a->e_b + a->e_a)
	{
		a->least_moves[a->i] = a->e_a + a->e_b + 1;
		a->i++;
	}
	index = 0;
	while (index < a->e_b)
	{
		ft_position(a, index);
		a->rb[a->s_b[index]] = index;
		a->rrb[a->s_b[index]] = a->e_b - index;
		index++;
	}
}
