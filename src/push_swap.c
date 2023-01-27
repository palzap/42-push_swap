/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:58:30 by pealexan          #+#    #+#             */
/*   Updated: 2023/01/26 10:11:22 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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

void	ft_add_index(t_stack *stack_a, int *stack, int size)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		i = 0;
		while (i < size)
		{
			if(stack_a->number == stack[i])
					stack_a->index = i;
			i++;
		}
		stack_a = stack_a->next;	
	}
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = *stack_a;
	if (!stack_a)
		return ;
	if (!(*stack_b))
	{
		*stack_a = (*stack_a)->next;
		*stack_b = temp;
		(*stack_b)->next = NULL;

	}
	else
	{
		*stack_a = (*stack_a)->next;
		ft_stackadd_front(stack_b, temp);
	}
}

void	ft_sa(t_stack **stack_a)
{
	t_stack	*first;
	t_stack *second;

	first = *stack_a;
	second = (*stack_a)->next;
	*stack_a = second;
	first->next = second->next;
	second->next = first;
}

void	ft_ra(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	ft_stackadd_back(&temp, *stack_a);
	*stack_a = temp->next;
	temp->next = 0;
}

void	ft_rra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *stack_a;
	last = ft_stacklast(*stack_a);
	while (temp)
	{
		if (temp->next == last)
		{
			temp->next = NULL;
			break ;
		}
		temp = temp->next;
	}
	ft_stackadd_front(stack_a, last);
}

void	ft_index_sort(t_stack *stack_a, char **argv, int size)
{
	int	i;
	int	temp;
	int	stack[size];

	i = -1;
	temp = 0;
	while (++i < size)
		 stack[i] = ft_atoi(argv[i + 1]);
	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
		{
			temp = stack[i];
			stack[i] = stack[i + 1];
			stack[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	ft_add_index(stack_a, stack, size);
}

void	ft_print_stack(t_stack *stack)
{
	t_stack *head;

	head = stack;
	while (head)
	{
		ft_printf("[%i] %i\n", head->index, head->number);
		head = head->next;
	}
}

int	ft_is_sorted(t_stack *stack, char c)
{
	t_stack *temp;
	t_stack *temp1;

	temp = stack;
	temp1 = stack->next;
	while (temp)
	{
		if (temp->index > temp1->index && c == 'a')
			return (0);
		if (temp->index < temp1->index && c == 'b')
			return (0);
		temp = temp->next;
		temp1 = temp1->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	i = 1;
	stack_a = 0;
	if (argc < 2)
		exit(1);
	ft_check_numbers(argc, argv);
	//ft_add_stack(argc, argv)
	//void	ft_add_stack(int argc, char **argv)
	//	{
	//		char	**stack;
//			int	i;
//
//			if (argc == 2)
//			{
//				i = 0;
//				stack = ft_split(argv[i], ' ');
//				while (stack[i])
//				{
//					ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi(stack[i]), 0));
//					i++
//				}
//			}
//			else
//			{
//				i = 1;
//				while (i < argc)
//				{
//					ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi(argv[i]), 0));
//					i++;
//				}
//			}
//		}
	while (i < argc)
	{
		ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi(argv[i]), 0));
		i++;
	}
	



	ft_printf("initial stack_a\n");
	ft_print_stack(stack_a);
	ft_printf("____________________________________\n");
	ft_index_sort(stack_a, argv, argc - 1);
	ft_printf("is sorted? %i\n", ft_is_sorted(stack_a, 'a'));
	ft_printf("after index sort stack_a\n");
	ft_print_stack(stack_a);
	ft_printf("____________________________________\n");
	ft_sa(&stack_a);
	ft_printf("after sa stack_a\n");
	ft_print_stack(stack_a);
	ft_printf("____________________________________\n");
	ft_ra(&stack_a);
	ft_printf("after ra stack_a\n");
	ft_print_stack(stack_a);
	ft_printf("____________________________________\n");
	ft_rra(&stack_a);
	ft_printf("after rra stack_a\n");
	ft_print_stack(stack_a);
	ft_printf("____________________________________\n");
	ft_rra(&stack_a);
	ft_printf("after rra stack_a\n");
	ft_print_stack(stack_a);
	ft_printf("____________________________________\n");
	ft_pb(&stack_a, &stack_b);
	ft_printf("after pb stack_a\n");
	ft_print_stack(stack_a);
	ft_printf("____________________________________\n");
	ft_print_stack(stack_b);
	ft_printf("____________________________________\n");
	ft_pb(&stack_a, &stack_b);
	ft_printf("after pb stack_a\n");
	ft_print_stack(stack_a);
	ft_printf("____________________________________\n");
	ft_print_stack(stack_b);
	ft_printf("____________________________________\n");
	return (0);
}