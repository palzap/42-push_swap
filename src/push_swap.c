/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleal <pleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:28:03 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/01 20:03:14 by pleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_sort_1(t_arrays *a)
{
	free(a->s_a);
	exit (1);
}

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
	if (arrays.e_a == 1)
		ft_sort_1(&arrays);
	else if (arrays.e_a == 2)
		ft_sort_2(&arrays);
	else if (arrays.e_a == 3)
		ft_sort_3(&arrays);
	else if (arrays.e_a == 5)
		ft_sort_5(&arrays);
	else
		ft_sort(&arrays);
	if (!ft_is_sorted(&arrays))
		ft_rotate_sort(&arrays);
	free(arrays.s_a);
	free(arrays.s_b);
	return (0);
}
