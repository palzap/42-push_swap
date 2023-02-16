/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:55:13 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/16 21:22:18 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

void	ft_rra(t_arrays *arrays)
{
	int	temp;
	int	i;

	if (!arrays->e_a)
		return ;
	i = arrays->e_a - 1;
	temp = arrays->s_a[i];
	while (i > 0)
	{
		arrays->s_a[i] = arrays->s_a[i - 1];
		i--;
	}
	arrays->s_a[i] = temp;
}

void	ft_rrb(t_arrays *arrays)
{
	int	temp;
	int	i;

	if (!arrays->e_b)
		return ;
	i = arrays->e_b - 1;
	temp = arrays->s_b[i];
	while (i > 0)
	{
		arrays->s_b[i] = arrays->s_b[i - 1];
		i--;
	}
	arrays->s_b[i] = temp;
}

void	ft_rrr(t_arrays *arrays)
{
	ft_rra(arrays);
	ft_rrb(arrays);
}
