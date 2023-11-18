/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasrour <amasrour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:19:10 by amasrour          #+#    #+#             */
/*   Updated: 2023/11/18 05:03:27 by amasrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_handle(t_stack *stack)
{
	if (stack->size_a == 2)
		sa(stack);
	else if (stack->size_a == 3)
		sort_3(stack);
	else if (stack->size_a == 4)
		sort_4(stack);
	else if (stack->size_a == 5)
		sort_5(stack);
	else if (stack->size_a <= 100)
		sort_100(stack);
	else
		sort_500(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	first_check(argc, argv);
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->size_a = check_and_size(argc, argv, stack);
	stack->stack_a = (int *)malloc(sizeof(int) * (stack->size_a));
	stack->stack_a = stack_init(argv, stack);
	stack->stack_b = (int *)malloc(sizeof(int) * (stack->size_b));
	stack->size_b = 0;
	ft_duplicated(stack);
	if (!is_it_sorted(stack))
		ft_handle(stack);
	free(stack->stack_a);
	free(stack->stack_b);
	return (0);
}
