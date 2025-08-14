/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeffaux <qdeffaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:01:35 by qdeffaux          #+#    #+#             */
/*   Updated: 2025/08/12 16:21:24 by qdeffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Push back from B to A with correct positioning */
void	push_back_optimally(t_stack *a, t_stack *b)
{
	int	target_pos;
	int	size_a;
	int	moves_needed;

	while (b->top)
	{
		target_pos = find_target_position_in_a(a, b->top->value);
		size_a = get_stack_size(a);
		if (target_pos <= size_a / 2)
		{
			moves_needed = target_pos;
			while (moves_needed-- > 0)
				ra(a);
		}
		else
		{
			moves_needed = size_a - target_pos;
			while (moves_needed-- > 0)
				rra(a);
		}
		pa(a, b);
	}
}

/* Final rotation to put smallest element on top */
void	final_rotation(t_stack *a)
{
	int	min_pos;
	int	size;
	int	moves_needed;

	min_pos = find_min_position(a);
	size = get_stack_size(a);
	if (min_pos == 0)
		return ;
	if (min_pos <= size / 2)
	{
		moves_needed = min_pos;
		while (moves_needed-- > 0)
			ra(a);
	}
	else
	{
		moves_needed = size - min_pos;
		while (moves_needed-- > 0)
			rra(a);
	}
}

/* Main Turk algorithm implementation */
void	turk_algorithm(t_stack *a, t_stack *b)
{
	if (get_stack_size(a) <= 3)
	{
		sort_three(a);
		return ;
	}
	push_with_cost_analysis(a, b);
	sort_three(a);
	push_back_optimally(a, b);
	final_rotation(a);
}
