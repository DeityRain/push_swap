/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_cost_calculation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeffaux <qdeffaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:03:17 by qdeffaux          #+#    #+#             */
/*   Updated: 2025/08/12 07:40:24 by qdeffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_rotation_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (size - pos);
}

int	find_target_position_in_b(t_stack *b, int value)
{
	t_node	*current;
	int		pos;
	int		best_pos;
	int		best_smaller;

	if (!b->top)
		return (0);
	current = b->top;
	pos = 0;
	best_pos = 0;
	best_smaller = INT_MIN;
	while (current)
	{
		if (current->value < value && current->value > best_smaller)
		{
			best_smaller = current->value;
			best_pos = pos;
		}
		current = current->next;
		pos++;
	}
	if (best_smaller == INT_MIN)
		best_pos = find_max_position_in_b(b);
	return (best_pos);
}

int	find_target_position_in_a(t_stack *a, int value)
{
	t_node	*current;
	int		pos;
	int		best_pos;
	int		best_larger;

	if (!a->top)
		return (0);
	current = a->top;
	pos = 0;
	best_pos = 0;
	best_larger = INT_MAX;
	while (current)
	{
		if (current->value > value && current->value < best_larger)
		{
			best_larger = current->value;
			best_pos = pos;
		}
		current = current->next;
		pos++;
	}
	if (best_larger == INT_MAX)
		return (0);
	return (best_pos);
}

int	calculate_push_cost(t_stack *a, t_stack *b, int pos_a)
{
	int		cost_a;
	int		target_pos_b;
	int		cost_b;
	t_node	*current;
	int		i;

	cost_a = calculate_rotation_cost(pos_a, get_stack_size(a));
	current = a->top;
	i = 0;
	while (i++ < pos_a)
		current = current->next;
	target_pos_b = find_target_position_in_b(b, current->value);
	cost_b = calculate_rotation_cost(target_pos_b, get_stack_size(b));
	if ((pos_a <= get_stack_size(a) / 2
			&& target_pos_b <= get_stack_size(b) / 2)
		|| (pos_a > get_stack_size(a) / 2
			&& target_pos_b > get_stack_size(b) / 2))
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

int	find_max_position_in_b(t_stack *b)
{
	t_node	*current;
	int		max_value;
	int		pos;
	int		best_pos;

	if (!b->top)
		return (0);
	current = b->top;
	max_value = current->value;
	pos = 0;
	best_pos = 0;
	while (current)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
			best_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (best_pos);
}
