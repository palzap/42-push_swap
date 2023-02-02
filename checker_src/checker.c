/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:34:21 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/02 12:55:41 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

void	ft_move(char *move, t_arrays *a)
{
	if (!ft_strncmp(move, "sa\n", 3))
		ft_sa(a);
	if (!ft_strncmp(move, "sb\n", 3))
		ft_sb(a);
	if (!ft_strncmp(move, "ss\n", 3))
		ft_ss(a);
	if (!ft_strncmp(move, "ra\n", 3))
		ft_ra(a);
	if (!ft_strncmp(move, "rb\n", 3))
		ft_rb(a);
	if (!ft_strncmp(move, "rr\n", 3))
		ft_rr(a);
	if (!ft_strncmp(move, "rra\n", 4))
		ft_rra(a);
	if (!ft_strncmp(move, "rrb\n", 4))
		ft_rrb(a);
	if (!ft_strncmp(move, "rrr\n", 4))
		ft_rr(a);
	if (!ft_strncmp(move, "pa\n", 3))
		ft_pa(a);
	if (!ft_strncmp(move, "pb\n", 3))
		ft_pb(a);
}

void	ft_do_moves(t_arrays *a)
{
	char	*move;

	move = ft_strdup("1");
	while (move)
	{
		ft_move(move, a);
		if (!ft_strncmp(move, "done\n", 5))
			break ;
		free (move);
		move = get_next_line(0);
	}
	free (move);
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
	ft_do_moves(&arrays);
	if (!ft_is_sorted(&arrays) && arrays.e_b != 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free(arrays.s_a);
	free(arrays.s_b);
	return (0);
}
