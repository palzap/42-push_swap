/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:54:39 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/07 08:39:08 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	ft_check_doubles(int argc, char **argv, int x)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	flag = 0;
	if (x == 1)
		i = 0;
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

int	ft_check_numbers(int argc, char **argv, int j)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (j == 1)
		i = 0;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN
			|| !ft_strdigit(argv[i]))
			flag = write(2, "Error\n", ft_strlen("Error\n"));
		if (flag != 0)
			return (-1);
		i++;
	}
	return (ft_check_doubles(argc, argv, j));
}

void	ft_get_stack_multiarg(char **argv, int argc, t_arrays *arrays)
{
	if (ft_check_numbers(argc, argv, 0) == -1)
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

void	ft_get_stack(char *arg, t_arrays *arrays)
{
	char	**stack;

	if (ft_wordcount(arg, ' ') == 1)
	{	
		if (!ft_strdigit(arg) || ft_atol(arg) > INT_MAX
			|| ft_atol(arg) < INT_MIN)
			write(2, "Error\n", ft_strlen("Error\n"));
		exit (1);
	}
	stack = ft_split(arg, ' ');
	if (ft_check_numbers(ft_wordcount(arg, ' '), stack, 1) == -1)
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
