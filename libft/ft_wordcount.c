/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:25:44 by pealexan          #+#    #+#             */
/*   Updated: 2023/01/25 14:20:37 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_wordcount(const char *str, char c)
{
	int	i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			wordcount++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (wordcount);
}
