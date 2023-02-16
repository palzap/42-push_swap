/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:55:20 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/16 21:22:23 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

void	ft_ra(t_arrays *arrays)
{
	int	temp;
	int	i;

	i = 0;
	if (!arrays->e_a)
		return ;
	temp = arrays->s_a[i];
	while (i < arrays->e_a - 1)
	{
		arrays->s_a[i] = arrays->s_a[i + 1];
		i++;
	}
	arrays->s_a[i] = temp;
}

void	ft_rb(t_arrays *arrays)
{
	int	temp;
	int	i;

	i = 0;
	if (!arrays->e_b)
		return ;
	temp = arrays->s_b[i];
	while (i < arrays->e_b - 1)
	{
		arrays->s_b[i] = arrays->s_b[i + 1];
		i++;
	}
	arrays->s_b[i] = temp;
}

void	ft_rr(t_arrays *arrays)
{
	ft_ra(arrays);
	ft_rb(arrays);
}
