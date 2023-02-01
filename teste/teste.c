/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:11:28 by pealexan          #+#    #+#             */
/*   Updated: 2023/01/19 10:45:33 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	ft_check_doubles(int argc, char **argv)
{
	int i;
	int	j;
	int	flag;

	i = 1;
	flag = 0;
	while(i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				flag = write(2, "Duplicate!\n", ft_strlen("Duplicate!\n"));
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
	while(i < argc)
	{
		if (ft_atol(argv[i]) > INT_MAX)
			flag = write(2, "> INT_MAX!\n", ft_strlen("> INT_MAX!\n"));
		if (ft_atol(argv[i]) < INT_MIN)
			flag = write(2, "< INT_MIN!\n", ft_strlen("< INT_MIN!\n"));
		if (ft_atoi(argv[i]) == 0 && argv[i][0] != '0')
			flag = write(2, "Not a number!\n", ft_strlen("Not a number!\n"));
		if (flag != 0)
			exit(1);
		i++;
	}
	ft_check_doubles(argc, argv);
}

void	del(void *list)
{
 	free (list);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 1;
	stack_a = 0;
	stack_b = 0;
	if (argc < 2)
		exit(1);
	ft_check_numbers(argc, argv);
	while (i < argc)
		ft_lstadd_back(&stack_a, ft_lstnew(argv[i++]));
	while (stack_a)
	{
		printf("%i\n", ft_atoi(stack_a->content));
		stack_a = stack_a->next;
	}
	/* while (stack_b)
	{
		printf("%i\n", (int)ft_atoi(stack_b->content));
		stack_b = stack_b->next;
	} */
	//ft_lstclear(&stack_a, del);
	//free(stack_b->next);
	return (0);
}