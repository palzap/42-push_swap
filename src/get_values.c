/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:54:46 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/02 11:54:46 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_convert_index(t_arrays *a, int *temp)
{
	a->i = 0;
	while (a->i < a->e_a)
	{
		a->j = 0;
		while (a->j < a->e_a)
		{
			if (a->s_a[a->i] == temp[a->j])
			{
				a->s_a[a->i] = a->j;
				break ;
			}
			a->j++;
		}
		a->i++;
	}
}

void	ft_get_median_and_indexing(t_arrays *a)
{
	int	*temp;
	int	tempi;

	temp = 0;
	temp = ft_memalloc(a->e_a);
	temp = ft_memcpy(temp, a->s_a, sizeof(int) * a->e_a);
	a->i = -1;
	while (a->i++ < a->e_a)
	{
		a->j = -1;
		while (++a->j < a->e_a - 1)
		{
			if (temp[a->j] > temp[a->j + 1])
			{
				tempi = temp[a->j];
				temp[a->j] = temp[a->j + 1];
				temp[a->j + 1] = tempi;
			}
		}
	}
	a->median = temp[a->e_a / 2];
	ft_convert_index(a, temp);
	free(temp);
}

void	ft_get_min_max(t_arrays *arrays)
{
	arrays->i = 1;
	arrays->min_a = arrays->s_a[0];
	while (arrays->i < arrays->e_a)
	{
		if (arrays->min_a > arrays->s_a[arrays->i])
			arrays->min_a = arrays->s_a[arrays->i];
		arrays->i++;
	}
	arrays->i = 0;
	arrays->max_a = arrays->s_a[0];
	while (arrays->i < arrays->e_a)
	{
		if (arrays->max_a < arrays->s_a[arrays->i])
			arrays->max_a = arrays->s_a[arrays->i];
		arrays->i++;
	}
}
