/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:10:26 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/06 11:34:13 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

/*CHECKER--------------------------------------------------------------------*/

/* Apply get_next_line to read each line from the standard input.
If piped with push_swap it will read all resulting instructions.
If executed by itself, it will wait for an input and execute said input,
when the word "done\n" is inputed it will stop reading, allowing it to
advance for the sort check. */
void	ft_do_moves(t_arrays *a);

/* Checks which input is given and executes the corresponding function. */
void	ft_move(char *move, t_arrays *a);

/*GET_STACK-------------------------------------------------------------------*/
/* Simple function to free the memory allocated by split. */
void	ft_free_split(char **split);

/* Check for duplicate values. */
int		ft_check_doubles(int argc, char **argv, int x);

/* Check for duplicates or values out of INT range.
Check if there are any characters besides a digit, '-', '+' or ' '. */
int		ft_check_numbers(int argc, char **argv, int j);

/* Applied when numbers are passed as individual arguments.
Check for duplicates or values out of INT range.
Check if there are any characters besides a digit, '-', '+' or ' '.
Fill stack_a with the numbers to be sorted. */
void	ft_get_stack_multiarg(char **argv, int argc, t_arrays *arrays);

/* Applied when numbers are passed as one single argument, where each number
is separated by a space.
First check amount of numbers, if 1, program terminates (already sorted).
Check if there are any characters besides a digit, '-', '+' or ' '.
Apply ft_split function to get each separate number.
Check for duplicates or values out of INT range.
Fill stack_a with the numbers to be sorted. */
void	ft_get_stack(char *arg, t_arrays *arrays);

/*PUSH------------------------------------------------------------------------*/
/* Pushes stack_b[0] to stack_a[0]. 
Reduces elements_b by 1, increments elements_a by 1. */
void	ft_pa(t_arrays *arrays);

/* Pushes stack_a[0] to stack_b[0]. 
Reduces elements_a by 1, increments elements_b by 1. */
void	ft_pb(t_arrays *arrays);

/*REVERSE_ROTATE--------------------------------------------------------------*/
/* Shift down all elements of stack a by 1.
The last element becomes the first one. */
void	ft_rra(t_arrays *arrays);

/* Shift down all elements of stack b by 1.
The last element becomes the first one. */
void	ft_rrb(t_arrays *arrays);

/* Shift down all elements of stack a and b by 1.
The last element becomes the first one. */
void	ft_rrr(t_arrays *arrays);

/*ROTATE----------------------------------------------------------------------*/
/* Shift up all elements of stack a by 1.
The first element becomes the last one. */
void	ft_ra(t_arrays *arrays);

/* Shift up all elements of stack b by 1.
The first element becomes the last one. */
void	ft_rb(t_arrays *arrays);

/* Shift up all elements of stack a and b by 1.
The first element becomes the last one. */
void	ft_rr(t_arrays *arrays);

/*SWAP------------------------------------------------------------------------*/
/* Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. */
void	ft_sa(t_arrays *arrays);

/* Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements. */
void	ft_sb(t_arrays *arrays);

/* Swap the first 2 elements at the top of stack a and b.
Do nothing if there is only one or no elements. */
void	ft_ss(t_arrays *arrays);

/*UTILS-----------------------------------------------------------------------*/
/* Free all the memory allocated to the needed arrays. */
void	ft_free(t_arrays *a);

/* Allocate with malloc the necessary memory to create the int arrays. 
Also performs the malloc protection in case no memory can be allocated. */
int		*ft_memalloc(int size);

/* Checks a string for anything other than a digit, '+', '-' or ' '. */
int		ft_strdigit(char *str);

/* Checks if stack_a is sorted in asecnding order. */
int		ft_is_sorted(t_arrays *arrays);

/* Initializes all elements of the struct to 0. */
void	ft_init_struct(t_arrays *arrays);

#endif
