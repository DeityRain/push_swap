/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeffaux <qdeffaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:01:35 by qdeffaux          #+#    #+#             */
/*   Updated: 2025/08/12 16:42:34 by qdeffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_and_prepare_numbers(int *numbers, int size)
{
	int	*original_numbers;
	int	i;

	original_numbers = malloc(sizeof(int) * size);
	if (!original_numbers)
		return (NULL);
	i = -1;
	while (++i < size)
		original_numbers[i] = numbers[i];
	assign_indices(numbers, size);
	return (original_numbers);
}

int	initialize_and_populate(t_stack **a, t_stack **b, int *numbers, int size)
{
	int	*original_numbers;
	int	i;

	original_numbers = copy_and_prepare_numbers(numbers, size);
	if (!original_numbers)
		return (0);
	*a = init_stack();
	*b = init_stack();
	if (!*a || !*b)
	{
		free(original_numbers);
		return (0);
	}
	i = size - 1;
	while (i >= 0)
	{
		push_node(*a, original_numbers[i], numbers[i]);
		i--;
	}
	free(original_numbers);
	return (1);
}

static int	handle_single_arg(char *arg, int **numbers, int *size)
{
	char	**split_argv;
	int		new_argc;
	int		i;

	split_argv = ft_split(arg, ' ');
	if (!split_argv)
		return (write(2, "Error\n", 6) - 1);
	new_argc = 0;
	while (split_argv[new_argc])
		new_argc++;
	if (new_argc == 0)
	{
		i = 0;
		while (split_argv[i])
			free(split_argv[i++]);
		free(split_argv);
		return (write(2, "Error\n", 6) - 1);
	}
	*numbers = parse_arguments(new_argc + 1, split_argv - 1, size);
	i = 0;
	while (split_argv[i])
		free(split_argv[i++]);
	free(split_argv);
	return (1);
}

int	validate_and_parse_input(int argc, char **argv, int **numbers, int *size)
{
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (handle_single_arg(argv[1], numbers, size) == -1)
			return (-1);
	}
	else
		*numbers = parse_arguments(argc, argv, size);
	if (!*numbers || has_duplicates(*numbers, *size))
	{
		if (*numbers)
			free(*numbers);
		return (write(2, "Error\n", 6) - 1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*numbers;
	int		size;

	if (validate_and_parse_input(argc, argv, &numbers, &size) <= 0)
	{
		if (numbers)
			return (1);
		return (0);
	}
	if (!initialize_and_populate(&a, &b, numbers, size))
	{
		free(numbers);
		return (1);
	}
	free(numbers);
	if (!is_sorted(a))
		sort_stack(a, b, size);
	free_stack(a);
	free_stack(b);
	return (0);
}
