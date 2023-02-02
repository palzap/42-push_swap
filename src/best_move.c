/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:54:27 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/02 11:54:28 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_best_element(t_arrays *a)
{
	int		index;
	int		steps;

	steps = INT_MAX;
	index = -1;
	a->i = 0;
	while (a->i < a->e_b)
	{
		if (a->least_moves[a->s_b[a->i]] < steps)
		{
			steps = a->least_moves[a->s_b[a->i]];
			index = a->i;
		}
		a->i++;
	}
	return (index);
}

void	ft_best_move(t_arrays *a)
{
	int		moves[4];

	a->i = 0;
	while (a->i < a->e_b)
	{
		moves[0] = ft_max(a->ra[a->s_b[a->i]], a->rb[a->s_b[a->i]]);
		moves[1] = ft_max(a->rra[a->s_b[a->i]], a->rrb[a->s_b[a->i]]);
		moves[2] = a->ra[a->s_b[a->i]] + a->rrb[a->s_b[a->i]];
		moves[3] = a->rra[a->s_b[a->i]] + a->rb[a->s_b[a->i]];
		a->j = 0;
		while (a->j < 4)
		{
			if (moves[a->j] < a->least_moves[a->s_b[a->i]])
			{
				a->least_moves[a->s_b[a->i]] = moves[a->j];
				a->scheme[a->s_b[a->i]] = a->j;
			}
			a->j++;
		}
		a->i++;
	}
}
