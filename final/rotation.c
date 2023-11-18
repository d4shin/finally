/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasrour <amasrour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:19:54 by amasrour          #+#    #+#             */
/*   Updated: 2023/11/18 03:38:30 by amasrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->stack_a[0];
	while (i < stack->size_a)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i - 1] = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->stack_b[0];
	while (i < stack->size_b)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i - 1] = tmp;
	write(1, "rb\n", 3);
}

void	rra(t_stack *stack)
{
	int	tmp;
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i < stack->size_a)
	{
		i++;
		len++;
	}
	tmp = stack->stack_a[len - 1];
	while (i >= 0)
	{
			stack->stack_a[i] = stack->stack_a[i - 1];
			i--;
	}
	stack->stack_a[0] = tmp;
	stack->stack_a[len] = 0;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	int	tmp;
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i < stack->size_b)
	{
		i++;
		len++;
	}
	tmp = stack->stack_b[len - 1];
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = tmp;
	stack->stack_b[len] = 0;
	write(1, "rrb\n", 4);
}
