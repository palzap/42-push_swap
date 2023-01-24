/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:10:26 by pealexan          #+#    #+#             */
/*   Updated: 2023/01/24 13:37:26 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int	number;
	int	index;
	struct s_stack *next;
} t_stack;

t_stack	*ft_stacknew(int number, int index);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
int	ft_stacksize(t_stack *stack);
void	ft_stackadd_front(t_stack **stack_a, t_stack *new);
void	ft_add_index(t_stack *stack_a, int	*stack, int	size);
void	ft_index_sort(t_stack *stack_a, char **argv, int size);
void	ft_print_stack(t_stack *stack);
int	ft_is_sorted(t_stack *stack, char c);

#endif