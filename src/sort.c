/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleal <pleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:34:10 by pleal             #+#    #+#             */
/*   Updated: 2023/02/01 19:35:50 by pleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_rotate_sort(t_arrays *a)
{
	a->i = 0;
	while (a->i < a->e_a)
	{
		if (a->s_a[a->i] == a->min_a)
			break ;
		a->i++;
	}
	if (a->i < a->e_a / 2)
	{
		while (!ft_is_sorted(a))
			ft_ra(a, 1);
	}
	else
	{
		while (!ft_is_sorted(a))
			ft_rra(a, 1);
	}
}

void	ft_sort_3(t_arrays *a)
{
	ft_get_min_max(a);
	if (a->s_a[0] < a->s_a[1] && a->s_a[0] < a->s_a[2] && a->s_a[1] > a->s_a[2])
	{
		ft_sa(a, 1);
		ft_ra(a, 1);
	}
	else if (a->s_a[0] > a->s_a[1] && a->s_a[0] < a->s_a[2]
		&& a->s_a[1] < a->s_a[2])
		ft_sa(a, 1);
	else if (a->s_a[0] < a->s_a[1] && a->s_a[0] > a->s_a[2]
		&& a->s_a[1] > a->s_a[2])
		ft_rra(a, 1);
	else if (a->s_a[0] > a->s_a[1] && a->s_a[0] > a->s_a[2]
		&& a->s_a[1] < a->s_a[2])
		ft_ra(a, 1);
	else if (a->s_a[0] > a->s_a[1] && a->s_a[0] > a->s_a[2]
		&& a->s_a[1] > a->s_a[2])
	{
		ft_sa(a, 1);
		ft_rra(a, 1);
	}
}

void	ft_sort_5(t_arrays *a)
{
	ft_get_min_max(a);
	while (a->e_a != 3)
	{
		if (a->s_a[0] == a->max_a || a->s_a[0] == a->min_a)
			ft_pb(a);
		else
			ft_ra(a, 1);
	}	
	ft_sort_3(a);
	ft_pa(a);
	if (ft_is_sorted(a))
	{
		ft_pa(a);
		ft_ra(a, 1);
	}
	else
	{
		ft_ra(a, 1);
		ft_pa(a);
	}
}

void	ft_sort(t_arrays *a)
{
	ft_get_median_and_indexing(a);
	ft_get_min_max(a);
	while (a->e_a != 3)
	{
		if (a->s_a[0] == a->median || a->s_a[0] == a->max_a
			|| a->s_a[0] == a->min_a)
			ft_ra(a, 1);
		else
			ft_pb(a);
	}
	ft_sort_3(a);
	a->least_moves = ft_calloc(a->e_b + a->e_a, sizeof(int));
	a->ra = ft_calloc(a->e_b + a->e_a, sizeof(int));
	a->rb = ft_calloc(a->e_b + a->e_a, sizeof(int));
	a->rra = ft_calloc(a->e_b + a->e_a, sizeof(int));
	a->rrb = ft_calloc(a->e_b + a->e_a, sizeof(int));
	a->scheme = ft_calloc(a->e_b + a->e_a, sizeof(int));
	while (a->e_b != 0)
	{
		ft_indexing(a);
		ft_best_move(a);
		ft_move(a);
	}
	ft_free(a);
}
