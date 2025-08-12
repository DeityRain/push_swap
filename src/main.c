/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeffaux <qdeffaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:01:35 by qdeffaux          #+#    #+#             */
/*   Updated: 2025/08/12 11:06:52 by qdeffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(int *numbers, int *original_numbers, t_stack *a, t_stack *b)
{
	free(numbers);
	free(original_numbers);
	free(a);
	free(b);
}

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

int	validate_and_parse_input(int argc, char **argv, int **numbers, int *size)
{
	if (argc < 2)
		return (0);
	*numbers = parse_arguments(argc, argv, size);
	if (!*numbers)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (has_duplicates(*numbers, *size))
	{
		free(*numbers);
		write(2, "Error\n", 6);
		return (-1);
	}
	return (1);
}

/*
void    display(t_stack *a, t_stack *b)
{
    t_node    *current_a;
    t_node    *current_b;

    current_a = a->top;
    current_b = b->top;
    printf("    STACK A\t\tSTACK B\n\n");
    while (current_a || current_b)
    {
        if (current_a)
        {
            printf("       %-20d", current_a->value);
            current_a = current_a->next;
        }
        else
            printf("                           ");
        if (current_b)
        {
            printf("%d\n", current_b->value);
            current_b = current_b->next;
        }
        else
            printf("\n");
    }
    printf("\n");
}
*/

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
