#include "push_swap.h"

void free_error(t_stack *stack, int answer)
{
	free(stack->stack_a);
	free(stack->stack_b);
	if (answer)
		write(2, "Error\n", 6);
	exit(1);
}

void	exec_instruction(t_stack *stack, char *instruction)
{
	if (!ft_strncmp(instruction, "sa\n", ft_strlen(instruction - 1)))
		sa(stack);
	else if (!ft_strncmp(instruction, "sb\n", ft_strlen(instruction - 1)))
		sb(stack);
	else if (!ft_strncmp(instruction, "ra\n", ft_strlen(instruction - 1)))
		ra(stack);
	else if (!ft_strncmp(instruction, "rb\n", ft_strlen(instruction - 1)))
		rb(stack);
	else if (!ft_strncmp(instruction, "rra\n", ft_strlen(instruction - 1)))
		rra(stack);
	else if (!ft_strncmp(instruction, "rrb\n", ft_strlen(instruction - 1)))
		rrb(stack);
	else if (!ft_strncmp(instruction, "pa\n", ft_strlen(instruction - 1)))
		pa(stack);
	else if (!ft_strncmp(instruction, "pb\n", ft_strlen(instruction - 1)))
		pb(stack);
	else
		free_error(stack, 1);
}

void	read_from_std(t_stack *stack)
{
	char		*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		exec_instruction(stack, instruction);
		free(instruction);
		instruction = get_next_line(0);
	}
	if (is_it_sorted(stack) && stack->size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "K0\n", 3);
	free_error(stack, 0);
}

int	*c_errors(int argc, char **argv, t_stack *stack)
{
	int	*a;
	int	size;
	int	i;

	i = -1;
	size = check_and_size(argc, argv, stack);
	a = (int *)malloc(size * sizeof(int));
	a = convert_to_num(argv, stack);
	ft_duplicated(stack);
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			argv = ft_split(*argv, ' ');
		stack.stack_a = c_errors(argv);
		stack.size_a = check_and_size(argc, argv, stack);
		stack.stack_b = (int *)malloc(pile.size_a * sizeof(int));
		if (!stack.b)
		{
			free(stack_a);
			return (0);
		}
		stack.size_b = 0;
		read_from_std(&stack);
	}
	return (0);
}
