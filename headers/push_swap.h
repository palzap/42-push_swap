/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleal <pleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:10:26 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/01 20:02:41 by pleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_arrays
{
	int	*s_a;
	int	*s_b;
	int	*least_moves;
	int	*ra;
	int	*rra;
	int	*rb;
	int	*rrb;
	int	*scheme;
	int	e_a;
	int	e_b;
	int	min_a;
	int	max_a;
	int	median;
	int	i;
	int	j;
}	t_arrays;

/*BEST_MOVE------------------------------------------------------------------*/
int		ft_best_element(t_arrays *a);
void	ft_best_move(t_arrays *a);

/*DO_MOVE+-------------------------------------------------------------------*/
void	ft_move(t_arrays *a);
void	ft_scheme_0(t_arrays *a, int index);
void	ft_scheme_1(t_arrays *a, int index);
void	ft_scheme_2(t_arrays *a, int index);
void	ft_scheme_3(t_arrays *a, int index);

/*GET_STACK------------------------------------------------------------------*/
void	ft_check_doubles(int argc, char **argv);
void	ft_check_numbers(int argc, char **argv);
void	ft_get_stack_multiarg(char **argv, int argc, t_arrays *arrays);
void	ft_get_stack(char *arg, t_arrays *arrays);

/*GET_VALUES-----------------------------------------------------------------*/
void	ft_convert_index(t_arrays *a, int *temp);
void	ft_get_median_and_indexing(t_arrays *a);
void	ft_get_min_max(t_arrays *arrays);

/*INDEXING-------------------------------------------------------------------*/
void	ft_indexing(t_arrays *a);
void	ft_position(t_arrays *a, int index);

/*PUSH_SWAP------------------------------------------------------------------*/
void	ft_sort_2(t_arrays *a);
void	ft_sort_1(t_arrays *a);

/*PUSH-----------------------------------------------------------------------*/
void	ft_pa(t_arrays *arrays);
void	ft_pb(t_arrays *arrays);

/*REVERSE_ROTATE-------------------------------------------------------------*/
void	ft_rra(t_arrays *arrays, int flag);
void	ft_rrb(t_arrays *arrays, int flag);
void	ft_rrr(t_arrays *arrays);

/*ROTATE---------------------------------------------------------------------*/
void	ft_ra(t_arrays *arrays, int flag);
void	ft_rb(t_arrays *arrays, int flag);
void	ft_rr(t_arrays *arrays);

/*SORT-----------------------------------------------------------------------*/
void	ft_sort_3(t_arrays *a);
void	ft_sort_5(t_arrays *a);
void	ft_sort(t_arrays *a);
void	ft_rotate_sort(t_arrays *a);

/*SWAP-----------------------------------------------------------------------*/
void	ft_sa(t_arrays *arrays, int flag);
void	ft_sb(t_arrays *arrays, int flag);
void	ft_ss(t_arrays *arrays);

/*UTILS----------------------------------------------------------------------*/
void	ft_free(t_arrays *a);
int		*ft_memalloc(int size);
int		ft_strdigit(char *str);
int		ft_is_sorted(t_arrays *arrays);
void	ft_init_struct(t_arrays *arrays);

#endif
