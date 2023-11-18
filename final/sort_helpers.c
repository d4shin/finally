/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasrour <amasrour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:20:13 by amasrour          #+#    #+#             */
/*   Updated: 2023/11/18 03:46:47 by amasrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack->stack_b[0];
	while (i < stack->size_b)
	{
		if (stack->stack_b[i] > max)
			max = stack->stack_b[i];
		i++;
	}
	return (max);
}

void	stack_cpy(t_stack *stack)
{
	int	i;

	i = 0;
	stack->tmp = malloc(sizeof(int) * stack->size_a);
	while (i < stack->size_a)
	{
		stack->tmp[i] = stack->stack_a[i];
		i++;
	}
}

void	bubble_sort(t_stack *stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	stack_cpy(stack);
	while (i < stack->size_a)
	{
		j = i + 1;
		while (j < stack->size_a)
		{
			if (stack->tmp[i] > stack->tmp[j])
			{
				tmp = stack->tmp[i];
				stack->tmp[i] = stack->tmp[j];
				stack->tmp[j] = tmp;
			}
			j++;
		}
	i++;
	}
}

int	get_index_b(t_stack *stack, int num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack->stack_b[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

int	get_index(t_stack *stack, int num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack->tmp[i] == num)
			return (i);
		i++;
	}
	return (-1);
}
