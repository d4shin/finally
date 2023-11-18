/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasrour <amasrour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:20:00 by amasrour          #+#    #+#             */
/*   Updated: 2023/11/18 03:36:30 by amasrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adjust_pa(t_stack *stack, int j)
{
	stack->stack_b[j - 1] = 0;
	stack->size_b--;
	stack->size_a++;
	write(1, "pa\n", 3);
}

void	pa(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stack->size_b != 0)
	{
		while (i < stack->size_a)
			i++;
		while (i > 0)
		{
			stack->stack_a[i] = stack->stack_a[i - 1];
			i--;
		}
		stack->stack_a[0] = stack->stack_b[0];
		while (j < stack->size_b)
		{
			stack->stack_b[j] = stack->stack_b[j + 1];
			j++;
		}
		adjust_pa(stack, j);
	}
}

void	adjust_pb(t_stack *stack, int j)
{
	stack->stack_a[j - 1] = 0;
	stack->size_a--;
	stack->size_b++;
	write(1, "pb\n", 3);
}

void	pb(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stack->size_a != 0)
	{
		while (i < stack->size_b)
			i++;
		while (i > 0)
		{
			stack->stack_b[i] = stack->stack_b[i - 1];
			i--;
		}
		stack->stack_b[0] = stack->stack_a[0];
		while (j < stack->size_a)
		{
			stack->stack_a[j] = stack->stack_a[j + 1];
			j++;
		}
		adjust_pb(stack, j);
	}
}
