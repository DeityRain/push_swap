/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_push_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeffaux <qdeffaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:03:51 by qdeffaux          #+#    #+#             */
/*   Updated: 2025/08/12 07:43:08 by qdeffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_simultaneous_rotations(t_stack *a, t_stack *b, int *pos_a,
		int *target_pos_b)
{
	int	size_a;
	int	size_b;

	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	while (*pos_a > 0 && *target_pos_b > 0 && *pos_a <= size_a / 2
		&& *target_pos_b <= size_b / 2)
	{
		rr(a, b);
		(*pos_a)--;
		(*target_pos_b)--;
	}
	while (*pos_a > 0 && *target_pos_b > 0 && *pos_a > size_a / 2
		&& *target_pos_b > size_b / 2)
	{
		rrr(a, b);
		(*pos_a)++;
		(*target_pos_b)++;
		if (*pos_a >= size_a)
			*pos_a = 0;
		if (*target_pos_b >= size_b)
			*target_pos_b = 0;
	}
}

void	execute_individual_rotations(t_stack *a, t_stack *b, int pos_a,
		int target_pos_b)
{
	int	size_a;
	int	size_b;

	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	if (pos_a <= size_a / 2)
	{
		while (pos_a-- > 0)
			ra(a);
	}
	else
	{
		while (pos_a++ < size_a)
			rra(a);
	}
	if (target_pos_b <= size_b / 2)
	{
		while (target_pos_b-- > 0)
			rb(b);
	}
	else
	{
		while (target_pos_b++ < size_b)
			rrb(b);
	}
}

static int	find_best_element(t_stack *a, t_stack *b)
{
	int	min_cost;
	int	best_pos;
	int	size_a;
	int	cost;
	int	i;

	min_cost = INT_MAX;
	best_pos = 0;
	size_a = get_stack_size(a);
	i = 0;
	while (i < size_a)
	{
		cost = calculate_push_cost(a, b, i);
		if (cost < min_cost)
		{
			min_cost = cost;
			best_pos = i;
		}
		if (cost <= 1)
			break ;
		i++;
	}
	return (best_pos);
}

void	push_with_cost_analysis(t_stack *a, t_stack *b)
{
	int		best_pos;
	int		i;
	t_node	*current;
	int		value;
	int		target_pos;

	pb(a, b);
	pb(a, b);
	if (b->top->value < b->top->next->value)
		sb(b);
	while (get_stack_size(a) > 3)
	{
		best_pos = find_best_element(a, b);
		current = a->top;
		i = 0;
		while (i++ < best_pos)
			current = current->next;
		value = current->value;
		target_pos = find_target_position_in_b(b, value);
		execute_simultaneous_rotations(a, b, &best_pos, &target_pos);
		execute_individual_rotations(a, b, best_pos, target_pos);
		pb(a, b);
	}
}
