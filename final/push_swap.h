/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasrour <amasrour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:19:35 by amasrour          #+#    #+#             */
/*   Updated: 2023/11/18 04:13:17 by amasrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
//# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	min;
	int	*tmp;
}t_stack;

void	ft_error(void);
void	first_check(int ac, char **av);
void	ft_duplicated(t_stack *stack);

int	is_it_sorted(t_stack *stack);
int	check_and_size(int ac, char **av, t_stack *stack);
int	*stack_init(char **av, t_stack *stack);

char	*join_args(char **av);
int	*convert_to_num(char *s, t_stack *stack);

void	sa(t_stack *stack);
void	sb(t_stack *stack);

void	ra(t_stack *stack);
void	rra(t_stack *stack);
void	rb(t_stack *stack);
void	rrb(t_stack *stack);

void	pa(t_stack *stack);
void	pb(t_stack *stack);

void	sort_3(t_stack *stack);
void	sort_4(t_stack *stack);
void	sort_5(t_stack *stack);
void	sort_100(t_stack *stack);
void	sort_500(t_stack *stack);

void	bubble_sort(t_stack *stack);
void	stack_cpy(t_stack *stack);
int	ft_max(t_stack *stack);
void	adjust_pa(t_stack *stack, int j);
void	adjust_pb(t_stack *stack, int j);
int	get_index(t_stack *stack, int num, int size);
int	get_index_b(t_stack *stack, int num, int size);
void	is_range(t_stack *stack, int index, int *f_range, int *s_range);

#endif
