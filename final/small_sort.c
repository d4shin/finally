/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasrour <amasrour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:20:06 by amasrour          #+#    #+#             */
/*   Updated: 2023/11/18 03:48:13 by amasrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(t_stack *stack)
{
	int	i;
	int	j;
	int	min;
	
	i = 0;
	j = 0;
	min = stack->stack_a[0];
	while (i < stack->size_a)
	{
		if (stack->stack_a[i] < min)
		{
			min = stack->stack_a[i];
			j = i;
		}
		i++;
	}
	stack->min = min;
	return (j);
}

void	sort_3(t_stack *stack)
{
	if (stack->stack_a[2] < stack->stack_a[1] 
		&& stack->stack_a[0] < stack->stack_a[2] 
			&& stack->stack_a[0] < stack->stack_a[1])
	{
		rra(stack);
		sa(stack);
	}
	else if (stack->stack_a[0] > stack->stack_a[1] 
		&& stack->stack_a[1] < stack->stack_a[2] 
			&& stack->stack_a[0] < stack->stack_a[2])
		sa(stack);
	else if (stack->stack_a[0] < stack->stack_a[1] 
		&& stack->stack_a[1] > stack->stack_a[2] 
			&& stack->stack_a[0] > stack->stack_a[2])
		rra(stack);
	else if (stack->stack_a[0] > stack->stack_a[1] 
		&& stack->stack_a[1] < stack->stack_a[2] 
			&& stack->stack_a[0] > stack->stack_a[2])
		ra(stack);
	else
	{
		ra(stack);
		sa(stack);
	}
}

void	sort_4(t_stack *stack)
{
	ft_min(stack);
	while (stack->stack_a[0] != stack->min)
		ra(stack);
	pb(stack);
	if (!is_it_sorted(stack))
	{
		sort_3(stack);
	}
	pa(stack);
}

void	sort_5(t_stack *stack)
{
	int	i;

	i = ft_min(stack);
	while (stack->stack_a[0] != stack->min)
	{
		if (i >= (stack->size_a / 2))
			rra(stack);
		else
			ra(stack);
	}
	pb(stack);
	i = ft_min(stack);
	while (stack->stack_a[0] != stack->min)
	{
		if (i >= (stack->size_a / 2))
			rra(stack);
		else
			ra(stack);
	}
	pb(stack);
	if (!is_it_sorted(stack))
		sort_3(stack);
	pa(stack);
	pa(stack);
}
