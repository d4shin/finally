/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasrour <amasrour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:20:28 by amasrour          #+#    #+#             */
/*   Updated: 2023/11/18 04:01:03 by amasrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	first_check(int ac, char **av)
{
	size_t	i;
	size_t	space;
	int		j;

	j = 0;
	if (ac < 2)
		exit (1);
	while (++j < ac)
	{
		if (ft_strlen(av[j]) == 0)
			ft_error();
		i = 0;
		space = 0;
		while (i < ft_strlen(av[j]))
		{
			if (av[j][i++] == ' ')
				space++;
		}
		if (ft_strlen(av[j]) == space)
			ft_error();
	}	
}

int	is_it_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->stack_a[i] < stack->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

char	*join_args(char **av)
{
	char	*s;
	int		i;

	s = NULL;
	i = 1;
	while (av[i])
	{
		s = ft_strjoin(s, ft_strdup(av[i]));
		s = ft_strjoin(s, ft_strdup(" "));
		i++;
	}
	return (s);
}

int	*convert_to_num(char *s, t_stack *stack)
{
	char	**str;
	int		i;

	str = ft_split(s, ' ');
	free(s);
	i = 0;
	while (str[i])
	{
		stack->stack_a[i] = ft_atol(str[i]);
		i++;
	}
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (stack->stack_a);
}
