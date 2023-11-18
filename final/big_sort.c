/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasrour <amasrour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:20:20 by amasrour          #+#    #+#             */
/*   Updated: 2023/11/18 04:08:17 by amasrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	median_check(t_stack *stack, int num, int size)
{
	if (get_index_b(stack, num, size) < stack->size_b / 2)
		return (1);
	return (0);
}

void	to_top(t_stack *stack, int num)
{
	int	i;

	i = median_check(stack, num, stack->size_b);
	while (stack->stack_b[0] != num)
	{
		if (i == 1)
		{
			if (stack->stack_b[0] != num)
				rb(stack);
		}
		else
		{
			if (stack->stack_b[0] != num)
				rrb(stack);
		}
	}
}

void	is_range(t_stack *stack, int index, int *f_range, int *s_range)
{
	if (index >= *f_range && index <= *s_range)
	{
		pb(stack);
		(*f_range)++;
		(*s_range)++;
	}
	else if (index < *f_range)
	{
		pb(stack);
		rb(stack);
		(*f_range)++;
		(*s_range)++;
	}
	else if (index > *s_range)
		ra(stack);
}

void	sort_100(t_stack *stack)
{
	int	f_range;
	int	s_range;
	int	s;
	int	index;

	f_range = 0;
	s_range = 15;
	s = stack->size_a;
	bubble_sort(stack);
	while (stack->size_a > 0)
	{
		index = get_index(stack, stack->stack_a[0], s);
		is_range(stack, index, &f_range, &s_range);
	}
	while (stack->size_b)
	{
		to_top(stack, ft_max(stack));
		pa(stack);
	}
}

void	sort_500(t_stack *stack)
{
	int	f_range;
	int	s_range;
	int	s;
	int	index;

	f_range = 0;
	s_range = 34;
	s = stack->size_a;
	bubble_sort(stack);
	while (stack->size_a > 0)
	{
		index = get_index(stack, stack->stack_a[0], s);
		is_range(stack, index, &f_range, &s_range);
	}
	while (stack->size_b)
	{
		to_top(stack, ft_max(stack));
		pa(stack);
	}
}
