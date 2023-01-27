/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:10:26 by pealexan          #+#    #+#             */
/*   Updated: 2023/01/27 14:51:06 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_arrays
{
	int	*stack_a;
	int *stack_b;
	int	elements_a;
	int	elements_b;
	int	min_a;
	int	max_a;
	int	min_b;
	int	max_b;
	int	median;
	int	i;
	int	j;
} t_arrays;

void	ft_sort_3(t_arrays *arrays);
void	ft_sort_5(t_arrays *arrays);
void	ft_get_min_max(t_arrays *arrays);
int		ft_is_sorted(t_arrays *arrays, char c);
void	ft_get_stack(char *arg, t_arrays *arrays);
void	ft_get_stack_multiarg(char **argv, int argc, t_arrays *arrays);
void	ft_init_struct(t_arrays *arrays);
void	ft_check_numbers(int argc, char **argv);
void	ft_check_doubles(int argc, char **argv);
void	ft_ss(t_arrays *arrays);
void	ft_sa(t_arrays *arrays, int flag);
void	ft_sb(t_arrays *arrays, int flag);
void	ft_rr(t_arrays *arrays);
void	ft_rb(t_arrays *arrays, int flag);
void	ft_ra(t_arrays *arrays, int flag);
void	ft_rrr(t_arrays *arrays);
void	ft_rrb(t_arrays *arrays, int flag);
void	ft_rra(t_arrays *arrays, int flag);
void	ft_pa(t_arrays *arrays);
void	ft_pb(t_arrays *arrays);
int		*ft_memalloc(int size);
void	ft_sort(t_arrays *a);






#endif