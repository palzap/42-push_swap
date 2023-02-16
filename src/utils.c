/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:55:56 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/16 21:07:51 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_free(t_arrays *a)
{
	free(a->least_moves);
	free(a->scheme);
	free(a->ra);
	free(a->rb);
	free(a->rra);
	free(a->rrb);
}

int	*ft_memalloc(int size)
{
	int	*alloc;

	alloc = (int *)malloc(sizeof(int) * size);
	if (!alloc)
		exit (1);
	return (alloc);
}

int	ft_strdigit(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_is_sorted(t_arrays *arrays)
{
	arrays->i = 0;
	if (arrays->e_a == 1)
		exit (1);
	while (arrays->i < arrays->e_a - 1)
	{
		if (arrays->s_a[arrays->i] > arrays->s_a[arrays->i + 1])
			return (0);
		arrays->i++;
	}
	return (1);
}

void	ft_init_struct(t_arrays *arrays)
{
	arrays->s_a = 0;
	arrays->s_b = 0;
	arrays->e_a = 0;
	arrays->e_b = 0;
	arrays->i = 0;
	arrays->j = 0;
	arrays->min_a = 0;
	arrays->max_a = 0;
	arrays->median = 0;
	arrays->least_moves = 0;
	arrays->ra = 0;
	arrays->rb = 0;
	arrays->rra = 0;
	arrays->rrb = 0;
	arrays->scheme = 0;
}
