/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:55:13 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/02 11:55:14 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_rra(t_arrays *arrays, int flag)
{
	int	temp;
	int	i;

	i = arrays->e_a - 1;
	temp = arrays->s_a[i];
	while (i > 0)
	{
		arrays->s_a[i] = arrays->s_a[i - 1];
		i--;
	}
	arrays->s_a[i] = temp;
	if (flag == 1)
		ft_printf("rra\n");
}

void	ft_rrb(t_arrays *arrays, int flag)
{
	int	temp;
	int	i;

	i = arrays->e_b - 1;
	temp = arrays->s_b[i];
	while (i > 0)
	{
		arrays->s_b[i] = arrays->s_b[i - 1];
		i--;
	}
	arrays->s_b[i] = temp;
	if (flag == 1)
		ft_printf("rrb\n");
}

void	ft_rrr(t_arrays *arrays)
{
	ft_rra(arrays, 2);
	ft_rrb(arrays, 2);
	ft_printf("rrr\n");
}
