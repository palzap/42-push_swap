/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleal <pleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:32:41 by pleal             #+#    #+#             */
/*   Updated: 2023/02/01 08:44:50 by pleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_check_doubles(int argc, char **argv)
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
		exit(1);
}

void	ft_check_numbers(int argc, char **argv)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	while (i < argc)
	{
		if (ft_atol(argv[i]) > INT_MAX)
			flag = write(2, "Error\n", ft_strlen("Error\n"));
		if (ft_atol(argv[i]) < INT_MIN)
			flag = write(2, "Error\n", ft_strlen("Error\n"));
		if (ft_atoi(argv[i]) == 0 && argv[i][0] != '0')
			flag = write(2, "Error\n", ft_strlen("Error\n"));
		if (flag != 0)
			exit(1);
		i++;
	}
	ft_check_doubles(argc, argv);
}

void	ft_get_stack_multiarg(char **argv, int argc, t_arrays *arrays)
{
	ft_check_numbers(argc, argv);
	arrays->e_a = argc - 1;
	arrays->s_a = ft_memalloc(arrays->e_a);
	arrays->i = 0;
	while (argv[arrays->i + 1])
	{
		if (!ft_strdigit(argv[arrays->i + 1]))
		{
			write(2, "Error\n", ft_strlen("Error\n"));
			exit(1);
		}
		arrays->s_a[arrays->i] = ft_atoi(argv[arrays->i + 1]);
		arrays->i++;
	}
}

void	ft_get_stack(char *arg, t_arrays *arrays)
{
	char	**stack;

	stack = ft_split(arg, ' ');
	ft_check_numbers(ft_wordcount(arg, ' '), stack);
	arrays->e_a = ft_wordcount(arg, ' ');
	arrays->i = 0;
	arrays->s_a = ft_memalloc(arrays->e_a);
	while (stack[arrays->i])
	{
		if (!ft_strdigit(stack[arrays->i]))
		{
			write(2, "Error\n", ft_strlen("Error\n"));
			exit(1);
		}
		arrays->s_a[arrays->i] = ft_atoi(stack[arrays->i]);
		free(stack[arrays->i]);
		arrays->i++;
	}
	free(stack);
}
