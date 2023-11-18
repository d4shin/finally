/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasrour <amasrour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:12:13 by amasrour          #+#    #+#             */
/*   Updated: 2023/11/18 04:12:19 by amasrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_init(char **av, t_stack *stack)
{
	char	*s;
	int		*result;

	s = join_args(av);
	result = convert_to_num(s, stack);
	return (result);
}

int	check_and_size(int ac, char **av, t_stack *stack)
{
	int	i;
	int	j;

	j = 0;
	stack->size_a = 0;
	while (++j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			if (av[j][i] == '+' || av[j][i] == '-')
				i++;
			if (!ft_isdigit(av[j][i]))
				ft_error();
			if (ft_isdigit(av[j][i]))
				stack->size_a++;
			else if (av[j][i] != ' ' && av[j][i] != '\t')
				ft_error();
			while (ft_isdigit(av[j][i]))
				i++;
			if (av[j][i] != ' ' && av[j][i] != '\t' && av[j][i] != '\0')
				ft_error();
			while (av[j][i] == ' ' || av[j][i] == '\t')
				i++;
		}
	}
	return (stack->size_a);
}

void	ft_duplicated(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size_a - 1)
	{
		j = i + 1;
		while (j < stack->size_a)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
				ft_error();
			j++;
		}
		i++;
	}
}
