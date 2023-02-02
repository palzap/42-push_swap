/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:54:33 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/02 11:54:34 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_scheme_0(t_arrays *a, int index)
{
	int	i;

	i = ft_min(a->ra[a->s_b[index]], a->rb[a->s_b[index]]);
	while (i-- > 0)
	{
		ft_rr(a);
		index--;
	}
	if (a->ra[a->s_b[index]] > a->rb[a->s_b[index]])
	{
		i = (a->ra[a->s_b[index]] - a->rb[a->s_b[index]]);
		while (i-- > 0)
			ft_ra(a, 1);
	}
	else
	{
		i = (a->rb[a->s_b[index]] - a->ra[a->s_b[index]]);
		while (i-- > 0)
			ft_rb(a, 1);
	}
}

void	ft_scheme_1(t_arrays *a, int index)
{
	int	i;

	i = ft_min(a->rra[a->s_b[index]], a->rrb[a->s_b[index]]);
	while (i-- > 0)
	{
		ft_rrr(a);
		index++;
		if (index > a->e_b - 1)
			index = index - a->e_b;
	}
	if (a->rra[a->s_b[index]] > a->rrb[a->s_b[index]])
	{
		i = a->rra[a->s_b[index]] - a->rrb[a->s_b[index]];
		while (i-- > 0)
			ft_rra(a, 1);
	}
	else
	{
		i = a->rrb[a->s_b[index]] - a->rra[a->s_b[index]];
		while (i-- > 0)
			ft_rrb(a, 1);
	}
}

void	ft_scheme_2(t_arrays *a, int index)
{
	int	i;

	i = a->ra[a->s_b[index]];
	while (i > 0)
	{
		ft_ra(a, 1);
		i--;
	}
	i = a->rrb[a->s_b[index]];
	while (i > 0)
	{
		ft_rrb(a, 1);
		i--;
	}
}

void	ft_scheme_3(t_arrays *a, int index)
{
	int	i;

	i = a->rra[a->s_b[index]];
	while (i > 0)
	{
		ft_rra(a, 1);
		i--;
	}
	i = a->rb[a->s_b[index]];
	while (i > 0)
	{
		ft_rb(a, 1);
		i--;
	}
}

void	ft_move(t_arrays *a)
{
	int	index;

	index = ft_best_element(a);
	if (index == -1)
		return ;
	if (a->scheme[a->s_b[index]] == 0)
		ft_scheme_0(a, index);
	else if (a->scheme[a->s_b[index]] == 1)
		ft_scheme_1(a, index);
	else if (a->scheme[a->s_b[index]] == 2)
		ft_scheme_2(a, index);
	else if (a->scheme[a->s_b[index]] == 3)
		ft_scheme_3(a, index);
	ft_pa(a);
}
