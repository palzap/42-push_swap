/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:55:44 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/16 21:22:32 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

void	ft_sa(t_arrays *arrays)
{
	int	temp;

	temp = 0;
	if (arrays->e_a > 1)
	{
		temp = arrays->s_a[0];
		arrays->s_a[0] = arrays->s_a[1];
		arrays->s_a[1] = temp;
	}
	return ;
}

void	ft_sb(t_arrays *arrays)
{
	int	temp;

	temp = 0;
	if (arrays->e_b > 1)
	{
		temp = arrays->s_b[0];
		arrays->s_b[0] = arrays->s_b[1];
		arrays->s_b[1] = temp;
	}
	return ;
}

void	ft_ss(t_arrays *arrays)
{
	ft_sa(arrays);
	ft_sb(arrays);
}
