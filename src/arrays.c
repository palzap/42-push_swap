/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:28:03 by pealexan          #+#    #+#             */
/*   Updated: 2023/01/27 15:36:02 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"
#include "../headers/push_swap.h"

int	*ft_memalloc(int size)
{
	int	*alloc;

	alloc = (int *)malloc(sizeof(int) * size);
	if(!alloc)
		exit (1);
	return (alloc);
}

void	ft_pb(t_arrays *a)
{
	int	*temp_a;
	int	*temp_b;

	temp_a = ft_memalloc(a->elements_a);
	temp_b = ft_memalloc(a->elements_b);
	temp_a = ft_memcpy(temp_a, a->stack_a, sizeof(int) * a->elements_a);
	temp_b = ft_memcpy(temp_b, a->stack_b, sizeof(int) * a->elements_b);
	free(a->stack_a);
	free(a->stack_b);
	a->elements_a -= 1;
	a->elements_b += 1;
	a->stack_a = ft_memalloc(a->elements_a);
	a->stack_b = ft_memalloc(a->elements_b);
	a->stack_a = ft_memcpy(a->stack_a, temp_a + 1, sizeof(int) * a->elements_a);
	a->i = 1;
	a->j = 0;
	a->stack_b[0] = temp_a[0];
	while (a->i < a->elements_b)
		a->stack_b[a->i++] = temp_b[a->j++];
	free(temp_a);
	free(temp_b);
	ft_printf("pb\n");
	return ;
}

void	ft_pa(t_arrays *a)
{
	int	*temp_a;
	int	*temp_b;

	temp_a = ft_memalloc(a->elements_a);
	temp_b = ft_memalloc(a->elements_b);
	temp_a = ft_memcpy(temp_a, a->stack_a, sizeof(int) * a->elements_a);
	temp_b = ft_memcpy(temp_b, a->stack_b, sizeof(int) * a->elements_b);
	free(a->stack_a);
	free(a->stack_b);
	a->elements_a += 1;
	a->elements_b -= 1;
	a->stack_a = ft_memalloc(a->elements_a);
	a->stack_b = ft_memalloc(a->elements_b);
	a->stack_b = ft_memcpy(a->stack_b, temp_b + 1, sizeof(int) * a->elements_b);
	a->i = 1;
	a->j = 0;
	a->stack_a[0] = temp_b[0];
	while (a->i < a->elements_a)
		a->stack_a[a->i++] = temp_a[a->j++];
	free(temp_a);
	free(temp_b);
	ft_printf("pa\n");
	return ;
}

void	ft_rra(t_arrays *arrays, int flag)
{
	int	temp;
	int	i;

	i = arrays->elements_a - 1;
	temp = arrays->stack_a[i];
	while (i > 0)
	{
		arrays->stack_a[i] = arrays->stack_a[i - 1];
		i--;
	}
	arrays->stack_a[i] = temp;
	if (flag == 1)
		ft_printf("rra\n");
	return ;
}

void	ft_rrb(t_arrays *arrays, int flag)
{
	int	temp;
	int	i;

	i = arrays->elements_b - 1;
	temp = arrays->stack_b[i];
	while (i > 0)
	{
		arrays->stack_b[i] = arrays->stack_b[i - 1];
		i--;
	}
	arrays->stack_b[i] = temp;
	if (flag == 1)
		ft_printf("rrb\n");
	return ;
}

void	ft_rrr(t_arrays *arrays)
{
	ft_rra(arrays, 2);
	ft_rrb(arrays, 2);
	ft_printf("rrr\n");
	return ;
}

void	ft_ra(t_arrays *arrays, int flag)
{
	int	temp;
	int	i;

	i = 0;
	temp = arrays->stack_a[i];
	while (i < arrays->elements_a - 1)
	{
		arrays->stack_a[i] = arrays->stack_a[i + 1];
		i++;
	}
	arrays->stack_a[i] = temp;
	if (flag == 1)
		ft_printf("ra\n");
	return ;
}

void	ft_rb(t_arrays *arrays, int flag)
{
	int	temp;
	int	i;

	i = 0;
	temp = arrays->stack_b[i];
	while (i < arrays->elements_b - 1)
	{
		arrays->stack_b[i] = arrays->stack_b[i + 1];
		i++;
	}
	arrays->stack_b[i] = temp;
	if (flag == 1)
		ft_printf("rb\n");
	return ;
}

void	ft_rr(t_arrays *arrays)
{
	ft_ra(arrays, 2);
	ft_rb(arrays, 2);
	ft_printf("rr\n");
	return ;
}

void	ft_sb(t_arrays *arrays, int flag)
{
	int	temp;

	temp = 0;
	if (arrays->elements_b > 1)
	{
		temp = arrays->stack_b[0];
		arrays->stack_b[0] = arrays->stack_b[1];
		arrays->stack_b[1] = temp;
		if (flag == 1)
			ft_printf("sb\n");
	}
	return ;
}

void	ft_sa(t_arrays *arrays, int flag)
{
	int	temp;

	temp = 0;
	if (arrays->elements_a > 1)
	{
		temp = arrays->stack_a[0];
		arrays->stack_a[0] = arrays->stack_a[1];
		arrays->stack_a[1] = temp;
		if (flag == 1)
			ft_printf("sa\n");
	}
	return ;
}

void	ft_ss(t_arrays *arrays)
{
	ft_sa(arrays, 2);
	ft_sb(arrays, 2);
	ft_printf("ss\n");
}

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
	while(i < argc)
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

void	ft_init_struct(t_arrays *arrays)
{
	arrays->stack_a = 0;
	arrays->stack_b = 0;
	arrays->elements_a = 0;
	arrays->elements_b = 0;
	arrays->i = 0;
	arrays->j = 0;
	arrays->min_a = 0;
	arrays->max_a = 0;
	arrays->min_b = 0;
	arrays->max_b = 0;
	arrays->median = 0;
}

void	ft_get_stack_multiarg(char **argv, int argc, t_arrays *arrays)
{
	ft_check_numbers(argc, argv);
	arrays->elements_a = argc - 1;
	arrays->stack_a = ft_memalloc(arrays->elements_a);
	while (argv[arrays->i + 1])
	{
		arrays->stack_a[arrays->i] = ft_atoi(argv[arrays->i + 1]);
		arrays->i++;
	}
}

void	ft_get_stack(char *arg, t_arrays *arrays)
{
	char	**stack;

	stack = ft_split(arg, ' ');
	ft_check_numbers(ft_wordcount(arg, ' '), stack);
	arrays->elements_a = ft_wordcount(arg, ' ');
	arrays->i = 0;
	arrays->stack_a = ft_memalloc(arrays->elements_a);
	while (stack[arrays->i])
	{
		 arrays->stack_a[arrays->i] = ft_atoi(stack[arrays->i]);
		 free(stack[arrays->i]);
		 arrays->i++;
	}
	free(stack);
}

int	ft_is_sorted(t_arrays *arrays, char c)
{
	arrays->i = 0;
	if (c == 'a')
	{
		while (arrays->i < arrays->elements_a - 1)
		{
			if (arrays->stack_a[arrays->i] > arrays->stack_a[arrays->i + 1])
				return (0);
			arrays->i++;
		}
	}
	else if (c == 'b')
	{
		while (arrays->i < arrays->elements_b - 1)
		{
			if (arrays->stack_b[arrays->i] < arrays->stack_b[arrays->i + 1])
				return (0);
			arrays->i++;
		}
	}
	return (1);
}

void	ft_get_min_max_a(t_arrays *arrays)
{
	arrays->i = 1;
	arrays->min_a = arrays->stack_a[0];
	while (arrays->i < arrays->elements_a)
	{
		if (arrays->min_a > arrays->stack_a[arrays->i])
			arrays->min_a = arrays->stack_a[arrays->i];
		arrays->i++;
	}
	arrays->i = 0;
	arrays->max_a = arrays->stack_a[0];
	while (arrays->i < arrays->elements_a)
	{
		if (arrays->max_a < arrays->stack_a[arrays->i])
			arrays->max_a = arrays->stack_a[arrays->i];
		arrays->i++;
	}
}

void	ft_get_min_max_b(t_arrays *arrays)
{
	arrays->i = 1;
	arrays->min_b = arrays->stack_b[0];
	while (arrays->i < arrays->elements_b)
	{
		if (arrays->min_b > arrays->stack_b[arrays->i])
			arrays->min_b = arrays->stack_b[arrays->i];
		arrays->i++;
	}
	arrays->i = 0;
	arrays->max_b = arrays->stack_b[0];
	while (arrays->i < arrays->elements_b)
	{
		if (arrays->max_b < arrays->stack_b[arrays->i])
			arrays->max_b = arrays->stack_b[arrays->i];
		arrays->i++;
	}
}

/* void	ft_sorting(t_arrays *arrays)
{
	arrays->i = 0;
	while (arrays->i < arrays->elements_a)
	{
		if (arrays->stack_a[arrays->i] < arrays->max / 2)
			ft_pb(arrays);
		else 
			ft_ra(arrays, 1);
		arrays->i++;
	}
	return ;
} */

void	ft_sort_5(t_arrays *a)
{
	ft_get_min_max_a(a);
	while (a->elements_a != 3)
	{
		if (a->stack_a[0] == a->max_a || a->stack_a[0] == a->min_a)
			ft_pb(a);
		else
			ft_ra(a, 1);
	}	
	ft_sort_3(a);
	ft_pa(a);
	if (ft_is_sorted(a, 'a'))
	{
		ft_pa(a);
		ft_ra(a, 1);
	}
	else
	{
		ft_ra(a, 1);
		ft_pa(a);
	}
}

void	ft_sort_3(t_arrays *a)
{
	ft_get_min_max_a(a);
	while (!ft_is_sorted(a, 'a'))
	{
		if (a->stack_a[0] == a->max_a)
		{
			ft_rra(a, 1);
			ft_rra(a, 1);
			if (a->stack_a[2] == a->min_a)
				ft_sa(a, 1);
		}
		else if (a->stack_a[1] == a->max_a)
		{
			ft_rra(a, 1);
			if (a->stack_a[0] == a->min_a)
				ft_sa(a, 1);
		}
		else if (a->stack_a[2] == a->max_a && a->stack_a[1] == a->min_a)
			ft_sa(a, 1);
	}
}

void	ft_get_median(t_arrays *a)
{
	int	*temp;
	int	tempi;

	temp = 0;
	temp = (int *)malloc(sizeof(int) * a->elements_a);
	temp = ft_memcpy(temp, a->stack_a, sizeof(int) * a->elements_a);
	a->i = 0;
	while (a->i < a->elements_a)
	{
		a->j = 0;
		while (a->j < a->elements_a - 1)
		{
			if(temp[a->j] >= temp[a->j + 1])
			{
				tempi = temp[a->j];
				temp[a->j] = temp[a->j + 1];
				temp[a->j + 1] = tempi;
			}
			a->j++;
		}
		a->i++;
	}
	a->median = temp[a->elements_a/2 + 1];
	free(temp);
}

void	ft_sort_a(t_arrays *a)
{
	int	flag;

	flag = 1;
	ft_get_min_max_a(a);
	while (!ft_is_sorted(a, 'a'))
	{
		if (a->stack_a[0] == a->max_a && a->stack_a[1] == a->min_a)
		{
			flag *= -1;
			if (flag == 1)
				ft_ra(a, 1);
			if (flag == -1)
				ft_rra(a, 1);
		}
		if (a->stack_a[0] > a->stack_a[1])
			ft_sa(a, 1);
		if (flag == 1)
			ft_ra(a, 1);
		if (flag == -1)
			ft_rra(a, 1);
	}
}

void	ft_sort_b(t_arrays *a)
{
	int	flag;

	flag = 1;
	ft_get_min_max_b(a);
	while (!ft_is_sorted(a, 'b'))
	{
		if (a->stack_b[0] == a->min_b && a->stack_b[1] == a->max_b)
		{
			flag *= -1;
			if (flag == 1)
				ft_rb(a, 1);
			if (flag == -1)
				ft_rrb(a, 1);
		}
		if (a->stack_b[0] < a->stack_b[1])
			ft_sb(a, 1);
		if (flag == 1)
			ft_rb(a, 1);
		if (flag == -1)
			ft_rrb(a, 1);
	}
	a->i = 0;
	while (a->elements_b != 0)
		ft_pa(a);
}

void	ft_sort(t_arrays *a)
{
	a->i = 0;
	while (a->elements_b < a->elements_a + 1)
	{
		
		if (a->stack_a[0] < a->median)
			ft_pb(a);
		else
			ft_ra(a, 1);
	}
	ft_sort_a(a);
	ft_sort_b(a);
}

int	main(int argc, char **argv)
{
	t_arrays	arrays;

	arrays.i = 0;
	ft_init_struct(&arrays);
	if (argc < 2)
		exit(1);
	if (argc == 2)
		ft_get_stack(argv[1], &arrays);
	else
		ft_get_stack_multiarg(argv, argc, &arrays);
	ft_get_median(&arrays);
	/* ft_printf("median = %i\n", arrays.median);
	ft_printf("Total numbers: %d\n", arrays.elements_a);
	ft_printf(" _______________\n|Initial Stack_a|\n");
	for (arrays.i = 0; arrays.i < arrays.elements_a; arrays.i++)
		ft_printf("%16i\n", arrays.stack_a[arrays.i]); */
	
	if (arrays.elements_a == 3)
		ft_sort_3(&arrays);
	if (arrays.elements_a == 5)
		ft_sort_5(&arrays);
	else
		ft_sort(&arrays);

	/* for (arrays.i = 0; arrays.i < arrays.elements_a; arrays.i++)
		ft_printf("%16i\n", arrays.stack_a[arrays.i]); */
	
	/* ft_printf(" _______________\n|Initial Stack_b|\n");
	for (arrays.i = 0; arrays.i < arrays.elements_b; arrays.i++)
		ft_printf("%16i\n", arrays.stack_b[arrays.i]);
	ft_pa(&arrays);
	ft_printf(" _______________\n|AfterPA Stack_a|\n");
	for (arrays.i = 0; arrays.i < arrays.elements_a; arrays.i++)
		ft_printf("%16i\n", arrays.stack_a[arrays.i]);
	ft_printf(" _______________\n|AfterPA Stack_b|\n");
	for (arrays.i = 0; arrays.i < arrays.elements_b; arrays.i++)
		ft_printf("%16i\n", arrays.stack_b[arrays.i]);
	ft_pa(&arrays);
	ft_printf(" _______________\n|AfterPA Stack_a|\n");
	for (arrays.i = 0; arrays.i < arrays.elements_a; arrays.i++)
		ft_printf("%16i\n", arrays.stack_a[arrays.i]);
	ft_printf(" _______________\n|AfterPA Stack_b|\n");
	for (arrays.i = 0; arrays.i < arrays.elements_b; arrays.i++)
		ft_printf("%16i\n", arrays.stack_b[arrays.i]);
	ft_pa(&arrays);
	ft_printf(" _______________\n|AfterPA Stack_a|\n");
	for (arrays.i = 0; arrays.i < arrays.elements_a; arrays.i++)
		ft_printf("%16i\n", arrays.stack_a[arrays.i]);
	ft_printf(" _______________\n|AfterPA Stack_b|\n");
	for (arrays.i = 0; arrays.i < arrays.elements_b; arrays.i++)
		ft_printf("%16i\n", arrays.stack_b[arrays.i]);
	ft_ra(&arrays, 1);
	ft_printf(" _______________\n|AfterRA Stack_a|\n");
	for (arrays.i = 0; arrays.i < arrays.elements_a; arrays.i++)
		ft_printf("%16i\n", arrays.stack_a[arrays.i]);
	ft_printf(" _______________\n|AfterRA Stack_b|\n");
	for (arrays.i = 0; arrays.i < arrays.elements_b; arrays.i++)
		ft_printf("%16i\n", arrays.stack_b[arrays.i]);
	ft_rr(&arrays);
	ft_printf(" _______________\n|AfterRA Stack_a|\n");
	for (arrays.i = 0; arrays.i < arrays.elements_a; arrays.i++)
		ft_printf("%16i\n", arrays.stack_a[arrays.i]);
	ft_printf(" _______________\n|AfterRA Stack_b|\n");
	for (arrays.i = 0; arrays.i < arrays.elements_b; arrays.i++)
		ft_printf("%16i\n", arrays.stack_b[arrays.i]); */
	free(arrays.stack_a);
	free(arrays.stack_b);
	return (0);	
}