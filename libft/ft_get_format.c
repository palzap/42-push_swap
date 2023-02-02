/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:58:16 by pealexan          #+#    #+#             */
/*   Updated: 2023/02/02 11:57:30 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	ft_get_values(t_buffer *values, char *buffer)
{
	if (!values->point)
	{
		values->width = ft_atoi(buffer);
		return (ft_getlength(values->width, 10) - 1);
	}
	else
	{
		values->precision = ft_atoi(buffer);
		return (ft_getlength(values->precision, 10) - 1);
	}
}

static void	ft_read_buffer(char *buffer, t_buffer *values)
{
	while (*buffer)
	{
		if (*buffer == '-')
			values->minus = 1;
		else if (*buffer == '+')
			values->plus = 1;
		else if (*buffer == ' ')
			values->space = 1;
		else if (*buffer == '0')
			values->zero = 1;
		else if (*buffer == '#')
			values->hash = 1;
		else if (*buffer == '.')
			values->point = 1;
		else if ((*buffer >= '1' && *buffer <= '9'))
			buffer += ft_get_values(values, buffer);
	buffer++;
	}
}

static void	ft_init_format_buffer(t_buffer *values)
{
	values->conversion_type = 0;
	values->space = 0;
	values->zero = 0;
	values->plus = 0;
	values->minus = 0;
	values->hash = 0;
	values->point = 0;
	values->width = 0;
	values->precision = 0;
}

int	ft_get_format_buffer(const char **str, va_list args)
{
	t_buffer	values;
	char		*buffer;
	int			i;

	i = 0;
	ft_init_format_buffer(&values);
	while (!ft_strchr(TYPE, (*str)[i]))
		i++;
	buffer = ft_substr(*str, 0, i);
	ft_read_buffer(buffer, &values);
	(*str) += i;
	values.conversion_type = **str;
	free(buffer);
	return (ft_check_type_format(args, &values));
}
