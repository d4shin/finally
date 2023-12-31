/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasrour <amasrour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:07:48 by amasrour          #+#    #+#             */
/*   Updated: 2023/11/18 01:07:49 by amasrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_process_sign(const char *str, int index)
{
	int	sign;

	sign = 1;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	return (sign);
}

int	ft_skip_sign(const char *str, int index)
{
	if (str[index] == '+' || str[index] == '-')
	{
		index++;
	}
	return (index);
}

long long	ft_atol(const char *str)
{
	int				i;
	long long		res;
	long long		sign;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = ft_process_sign(str, i);
	i = ft_skip_sign(str, i);
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		if (res == 2147483648 && sign == -1)
			return (res * sign);
		if (res > 2147483647)
			ft_error();
		i++;
	}
	if ((sign * res) > INT_MAX || (sign * res) < INT_MIN)
		ft_error();
	return (sign * res);
}
