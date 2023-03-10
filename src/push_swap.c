/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:54:58 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/16 20:20:08 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_sort_2(t_arrays *a)
{
	if (a->s_a[0] > a->s_a[1])
		ft_sa(a, 1);
}

int	main(int argc, char **argv)
{
	t_arrays	arrays;

	ft_init_struct(&arrays);
	if (argc < 2)
		return (0);
	if (argc == 2)
		ft_get_stack(argv[1], &arrays);
	else
		ft_get_stack_multiarg(argv, argc, &arrays);
	if (!ft_is_sorted(&arrays))
		ft_sort(&arrays);
	if (!ft_is_sorted(&arrays))
		ft_rotate_sort(&arrays);
	free(arrays.s_a);
	free(arrays.s_b);
	return (0);
}
