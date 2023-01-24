/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:28:03 by pealexan          #+#    #+#             */
/*   Updated: 2023/01/24 08:56:43 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"
#include "headers/push_swap.h"

int	ft_count_numbers(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	return (i);
}

void	ft_pa(int *stack_a, int *stack_b)
{
	int	i;
	int	*temp_a;
	int	*temp_b;

	i = 0;
	/* if (!stack_b)
	{
		stack_b = (int *)malloc(sizeof(int) * 1);
		if(!stack_b)
			exit(1);
	} */
	i = 0;
	temp_a = (int *)malloc(sizeof(int) * ft_count_numbers(stack_a));
	if (!temp_a)
		exit (1);
	temp_b = (int *)malloc(sizeof(int) * ft_count_numbers(stack_b));
	if (!temp_b)
		exit(1);
	temp_a = ft_memcpy(temp_a, stack_a, sizeof(int) * ft_count_numbers(stack_a));
	ft_printf("stack_a numbers: %d\n", ft_count_numbers(stack_a));
	i = 0;
	ft_printf("temp_a\n");
	while (temp_a[i])
	{
		ft_printf("%d\n", temp_a[i]);
		i++;
	}
	i = 0;
	temp_b = ft_memcpy(temp_b, stack_b, sizeof(int) * ft_count_numbers(stack_b));
	free(stack_a);
	free(stack_b);
	stack_a = (int *)malloc(sizeof(int) * (ft_count_numbers(temp_a) - 1));
	if (!stack_a)
		exit (1);
	stack_b = (int *)malloc(sizeof(int) * (ft_count_numbers(temp_b) + 1));
	if (!stack_b)
		exit (1);
	stack_a = ft_memcpy(stack_a, temp_a + 1, sizeof(int) * (ft_count_numbers(temp_a)));
	i = 0;
	if (ft_count_numbers(temp_b) > 0)
	{
		stack_b = ft_memcpy(stack_b, temp_a, sizeof(int));
		stack_b = ft_memcpy(stack_b + 1, temp_b, sizeof(int) * (ft_count_numbers(temp_b)));
	}
	else
		stack_b = ft_memcpy(stack_b, temp_a, sizeof(int));
	i = 0;
	free(temp_a);
	free(temp_b);
}

void	ft_rra(int	*stack_a)
{
	int	temp;
	int	i;

	i = ft_count_numbers(stack_a) - 1;
	temp = stack_a[i];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[i] = temp;
	ft_printf("rra\n");
}

/* void	ft_rrb(int	*stack_b)
{
	int	temp;
	int	i;

	i = ft_count_numbers(stack_b) - 1;
	temp = stack_b[i];
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[i] = temp;
	ft_printf("rrb\n");
} */

/* void	ft_rrr(int *stack_a, int *stack_b)
{
	int	temp;
	int	i;

	i = ft_count_numbers(stack_a) - 1;
	temp = stack_a[i];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[i] = temp;
	i = ft_count_numbers(stack_b) - 1;
	temp = stack_b[i];
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[i] = temp;
	ft_printf("rrr\n");
} */

void	ft_ra(int	*stack_a)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack_a[i];
	while (i < ft_count_numbers(stack_a) - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = temp;
	ft_printf("ra\n");
}

/* void	ft_rb(int	*stack_b)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack_b[i];
	while (i < ft_count_numbers(stack_b) - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i] = temp;
	ft_printf("rb\n");
} */

/* void	ft_rr(int *stack_a, int *stack_b)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack_a[i];
	while (i < ft_count_numbers(stack_a) - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = temp;
	i = 0;
	temp = stack_b[i];
	while (i < ft_count_numbers(stack_b) - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i] = temp;
	ft_printf("rr\n");
} */

/* void	ft_sb(int *stack_b)
{
	int	temp;

	temp = 0;
	if (ft_count_numbers(stack_b) > 1)
	{
		temp = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = temp;
		if (!actions->do_ss)
			ft_printf("sb\n");
	}
	return ;
} */

void	ft_sa(int *stack_a)
{
	int	temp;

	temp = 0;
	if (ft_count_numbers(stack_a) > 1)
	{
		temp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp;
		ft_printf("sa\n");
	}
	return ;
}

/* void	ft_ss(int *stack_a, int	*stack_b)
{
	int	temp;

	temp = 0;
	if (!ft_count_numbers(stack_a) > 1)
		return ;;
	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	ft_printf("ss\n");
} */

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

int	main(int argc, char **argv)
{
	int	*stack_a = 0;
	int	*stack_b = 0;
	int	i;
//	int	j;

	i = 0;
//	j = 0;
	if (argc < 2)
		exit(1);
	ft_check_numbers(argc, argv);
	stack_a = (int *)malloc(sizeof(int) * argc - 1);
	if (!stack_a)
		exit (1);
	stack_b = (int *)malloc(sizeof(int) * 0);
	if (!stack_b)
		exit (1);
	while (argv[i + 1])
	{
		 stack_a[i] = ft_atoi(argv[i + 1]);
		 i++;
	}
	ft_printf("Total numbers: %d\n", ft_count_numbers(stack_a));
	i = 0;
	ft_printf("stack_a\n");
	while (i < argc - 1)
	{
		ft_printf("%d\n", stack_a[i]);
		i++;
	}
	ft_pa(stack_a, stack_b);
 	ft_printf("After ft_pa\n");
	i = 0;
	ft_printf("stack_a\n");
	while (stack_a[i])
	{
		ft_printf("%d\n", stack_a[i]);
		i++;
	}
	i = 0;
	ft_printf("stack_b\n");
	while (stack_b[i])
	{
		ft_printf("%d\n", stack_b[i]);
		i++;
	}
	ft_pa(stack_a, stack_b);
 	ft_printf("After ft_pa\n");
	i = 0;
	ft_printf("stack_a\n");
	while (stack_a[i])
	{
		ft_printf("%d\n", stack_a[i]);
		i++;
	}
	i = 0;
	ft_printf("stack_b\n");
	while (stack_b[i])
	{
		ft_printf("%d\n", stack_b[i]);
		i++;
	}
	ft_pa(stack_a, stack_b);
 	ft_printf("After ft_pa\n");
	i = 0;
	ft_printf("stack_a\n");
	while (stack_a[i])
	{
		ft_printf("%d\n", stack_a[i]);
		i++;
	}
	i = 0;
	ft_printf("stack_b\n");
	while (stack_b[i])
	{
		ft_printf("%d\n", stack_b[i]);
		i++;
	}
/*  	ft_rra(stack_a);
	i = 0;
	while (i < argc - 1)
	{
		ft_printf("%d\n", stack_a[i]);
		i++;
	}
	ft_ra(stack_a);
	i = 0;
	while (i < argc - 1)
	{
		ft_printf("%d\n", stack_a[i]);
		i++;
	} */
	free(stack_a);
	return (0);	
}