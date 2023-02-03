/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:55:20 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/02 11:55:21 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_ra(t_arrays *arrays, int flag)
{
	int	temp;
	int	i;

	i = 0;
	temp = arrays->s_a[i];
	while (i < arrays->e_a - 1)
	{
		arrays->s_a[i] = arrays->s_a[i + 1];
		i++;
	}
	arrays->s_a[i] = temp;
	if (flag == 1)
		ft_printf("ra\n");
}

void	ft_rb(t_arrays *arrays, int flag)
{
	int	temp;
	int	i;

	i = 0;
	temp = arrays->s_b[i];
	while (i < arrays->e_b - 1)
	{
		arrays->s_b[i] = arrays->s_b[i + 1];
		i++;
	}
	arrays->s_b[i] = temp;
	if (flag == 1)
		ft_printf("rb\n");
}

void	ft_rr(t_arrays *arrays)
{
	ft_ra(arrays, 2);
	ft_rb(arrays, 2);
	ft_printf("rr\n");
}