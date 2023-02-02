/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:49:13 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/02 11:49:14 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

void	ft_pa(t_arrays *a)
{
	int	*temp_a;
	int	*temp_b;

	temp_a = ft_memalloc(a->e_a);
	temp_b = ft_memalloc(a->e_b);
	temp_a = ft_memcpy(temp_a, a->s_a, sizeof(int) * a->e_a);
	temp_b = ft_memcpy(temp_b, a->s_b, sizeof(int) * a->e_b);
	free(a->s_a);
	free(a->s_b);
	a->e_a += 1;
	a->e_b -= 1;
	a->s_a = ft_memalloc(a->e_a);
	a->s_b = ft_memalloc(a->e_b);
	a->s_b = ft_memcpy(a->s_b, temp_b + 1, sizeof(int) * a->e_b);
	a->i = 1;
	a->j = 0;
	a->s_a[0] = temp_b[0];
	while (a->i < a->e_a)
		a->s_a[a->i++] = temp_a[a->j++];
	free(temp_a);
	free(temp_b);
}

void	ft_pb(t_arrays *a)
{
	int	*temp_a;
	int	*temp_b;

	temp_a = ft_memalloc(a->e_a);
	temp_b = ft_memalloc(a->e_b);
	temp_a = ft_memcpy(temp_a, a->s_a, sizeof(int) * a->e_a);
	temp_b = ft_memcpy(temp_b, a->s_b, sizeof(int) * a->e_b);
	free(a->s_a);
	free(a->s_b);
	a->e_a -= 1;
	a->e_b += 1;
	a->s_a = ft_memalloc(a->e_a);
	a->s_b = ft_memalloc(a->e_b);
	a->s_a = ft_memcpy(a->s_a, temp_a + 1, sizeof(int) * a->e_a);
	a->i = 1;
	a->j = 0;
	a->s_b[0] = temp_a[0];
	while (a->i < a->e_b)
		a->s_b[a->i++] = temp_b[a->j++];
	free(temp_a);
	free(temp_b);
}
