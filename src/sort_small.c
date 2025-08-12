/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeffaux <qdeffaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:01:35 by qdeffaux          #+#    #+#             */
/*   Updated: 2025/08/12 07:57:45 by qdeffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (!a || !a->top || !a->top->next || !a->top->next->next)
		return ;
	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	int		min;
	int		pos;
	t_node	*current;

	min = find_min(a);
	pos = 0;
	current = a->top;
	while (current && current->value != min)
	{
		pos++;
		current = current->next;
	}
	if (pos <= a->size / 2)
	{
		while (a->top->value != min)
			ra(a);
	}
	else
	{
		while (a->top->value != min)
			rra(a);
	}
	pb(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	size;

	size = get_stack_size(a);
	while (size > 3)
	{
		push_smallest_to_b(a, b);
		size--;
	}
	sort_three(a);
	while (b->top)
		pa(a, b);
}

void	sort_stack(t_stack *a, t_stack *b, int size)
{
	(void) size;
	if (is_sorted(a))
		return ;
	else if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		turk_algorithm(a, b);
}
	/*else
		radix_sort(a, b);*/
	/*for very long list (more than 1000)*/