/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:49:04 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/02 11:49:06 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

/* Simple function to free the memory allocated by split.                     */
void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

/*  Check for duplicates or values.                                           */
int	ft_check_doubles(int argc, char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	flag = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				flag = write(2, "Error\n", ft_strlen("Error\n"));
			j++;
		}
		i++;
	}
	if (flag != 0)
		return (-1);
	return (0);
}

/*  Check for duplicates or values out of INT range.                          */
/*  Check if there are any characters besides a digit, '-', '+' or ' '.       */
int	ft_check_numbers(int argc, char **argv)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX)
			flag = write(2, "Error\n", ft_strlen("Error\n"));
		else if (ft_atol(argv[i]) < INT_MIN)
			flag = write(2, "Error\n", ft_strlen("Error\n"));
		else if (ft_atoi(argv[i]) == 0 && argv[i][0] != '0')
			flag = write(2, "Error\n", ft_strlen("Error\n"));
		else if (!ft_strdigit(argv[i]))
			flag = write(2, "Error\n", ft_strlen("Error\n"));
		if (flag != 0)
			return (-1);
		i++;
	}
	return (ft_check_doubles(argc, argv));
}

/*  Applied when numbers are passed as individual arguments.                  */
/*  Check for duplicates or values out of INT range.                          */
/*  Check if there are any characters besides a digit, '-', '+' or ' '.       */
/*  Fill stack_a with the numbers to be sorted.                               */
void	ft_get_stack_multiarg(char **argv, int argc, t_arrays *arrays)
{
	if (ft_check_numbers(argc, argv) == -1)
		exit (1);
	arrays->e_a = argc - 1;
	arrays->s_a = ft_memalloc(arrays->e_a);
	arrays->i = 0;
	while (argv[arrays->i + 1])
	{
		arrays->s_a[arrays->i] = ft_atoi(argv[arrays->i + 1]);
		arrays->i++;
	}
}

/*  Applied when numbers are passed as one single argument, where each number */
/*  is separated by a space.                                                  */
/*  First check amount of numbers, if 1 program terminates (already sorted).  */
/*  Check if there are any characters besides a digit, '-', '+' or ' '.       */
/*  Apply ft_split function to get each separate number.                      */
/*  Check for duplicates or values out of INT range.                          */
/*  Fill stack_a with the numbers to be sorted.                               */
void	ft_get_stack(char *arg, t_arrays *arrays)
{
	char	**stack;

	if (ft_wordcount(arg, ' ') == 1)
		exit (1);
	if (!ft_strdigit(arg))
		exit (1);
	stack = ft_split(arg, ' ');
	if (ft_check_numbers(ft_wordcount(arg, ' '), stack) == -1)
	{
		ft_free_split(stack);
		exit (1);
	}
	arrays->e_a = ft_wordcount(arg, ' ');
	arrays->i = 0;
	arrays->s_a = ft_memalloc(arrays->e_a);
	while (stack[arrays->i])
	{
		arrays->s_a[arrays->i] = ft_atoi(stack[arrays->i]);
		arrays->i++;
	}
	ft_free_split(stack);
}
