/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleal <pleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:29:30 by pleal             #+#    #+#             */
/*   Updated: 2023/02/01 08:30:39 by pleal            ###   ########.fr       */
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
	return ;
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
	return ;
}

void	ft_rr(t_arrays *arrays)
{
	ft_ra(arrays, 2);
	ft_rb(arrays, 2);
	ft_printf("rr\n");
	return ;
}
