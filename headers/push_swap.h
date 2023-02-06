/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:10:26 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/06 11:34:19 by pealexan         ###   ########.fr       */
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

/*BEST_MOVE-------------------------------------------------------------------*/
/* Check the least_moves array to check for the element with the least amount 
it returns the index of the best element. */
int		ft_best_element(t_arrays *a);

/*Reads arrays ra, rra, rb, rrb for each element of stack_b to determine the
minimum number of moves needed to achieved the desired sort.
Fills in the least_moves array with the least amount of moves needed for each
element.
Also fills the scheme array with the pattern of moves that will be used.*/
void	ft_best_move(t_arrays *a);

/*DO_MOVE+--------------------------------------------------------------------*/
/* Finds best element to get its index.
Checks scheme array on the element index for the corresponding move scheme
to apply. */
void	ft_move(t_arrays *a);

/* Apply moves to get desired result. */
void	ft_scheme_0(t_arrays *a, int index);

/* Apply moves to get desired result. */
void	ft_scheme_1(t_arrays *a, int index);

/* Apply moves to get desired result. */
void	ft_scheme_2(t_arrays *a, int index);

/* Apply moves to get desired result. */
void	ft_scheme_3(t_arrays *a, int index);

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

/*GET_VALUES------------------------------------------------------------------*/

/* Compares the values of stack_a and the temporary sorted copy.
When values match, value of stack_a is replaced by index of the temporary array.
Basically converts any value to its index in the same order. 
This is used to facilitate the sorting of the other arrays. */
void	ft_convert_index(t_arrays *a, int *temp);

/* Gets the median value of stack_a.
Sorts a temporary copy of stack_a.
Performs an indexing of all values of stack_a. */
void	ft_get_median_and_indexing(t_arrays *a);

/* Gets max and min values of stack_a. */
void	ft_get_min_max(t_arrays *arrays);

/*INDEXING--------------------------------------------------------------------*/
/* Array least_moves is filled with total number of elements + 1.
Executes ft_position to fill stacks ra and rra.
Stack rb and rrb are filled in the following way:
stack_b value = x
elements_b = y
rb[x] = x
rrb[x] = y - x
This is the number of rb or rrbs needed to get said element to the top. */
void	ft_indexing(t_arrays *a);

/* Compares each element of stack_b with each element of stack_a.
Gets the difference of each comparison. If the difference is positive
save the position of that element. If any other subsequent comparison
has a lower difference value, the position is changed. 
Stack ra and rra are filled with that position. 
Example:
stack_b value = x
stack_a value = y
diff = y - x = z
ra[x] = z
rra[x] = elements_a - z 
This is the number of ra or rra needed to get the best stack_a element to
the top.*/
void	ft_a_indexing(t_arrays *a, int index);

/*PUSH_SWAP-------------------------------------------------------------------*/
/* Sorts 2 numbers. */
void	ft_sort_2(t_arrays *a);

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
void	ft_rra(t_arrays *arrays, int flag);

/* Shift down all elements of stack b by 1.
The last element becomes the first one. */
void	ft_rrb(t_arrays *arrays, int flag);

/* Shift down all elements of stack a and b by 1.
The last element becomes the first one. */
void	ft_rrr(t_arrays *arrays);

/*ROTATE----------------------------------------------------------------------*/
/* Shift up all elements of stack a by 1.
The first element becomes the last one. */
void	ft_ra(t_arrays *arrays, int flag);

/* Shift up all elements of stack b by 1.
The first element becomes the last one. */
void	ft_rb(t_arrays *arrays, int flag);

/* Shift up all elements of stack a and b by 1.
The first element becomes the last one. */
void	ft_rr(t_arrays *arrays);

/*SORT------------------------------------------------------------------------*/
/* Sorts 3 numbers. */
void	ft_sort_3(t_arrays *a);

/* Sorts 5 numbers. */
void	ft_sort_5(t_arrays *a);

/* Pushes all numbers to stack_b exept max, min and med values.
Sorts the remaining 3 values.
Allocates memory for the needed arrays to be filled.
Applies the functions to decide which combination of moves is the best to 
ensure the minimum number of moves used untill stack_b is emply. */
void	ft_sort(t_arrays *a);

/* Simply calculates between ra and rra the least amount of moves needed to 
sort the stack. */
void	ft_rotate_sort(t_arrays *a);

/*SWAP------------------------------------------------------------------------*/
/* Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. */
void	ft_sa(t_arrays *arrays, int flag);

/* Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements. */
void	ft_sb(t_arrays *arrays, int flag);

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
