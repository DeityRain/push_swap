/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeffaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 06:50:35 by qdeffaux          #+#    #+#             */
/*   Updated: 2025/08/07 06:50:58 by qdeffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Base swap operation - swaps first two elements of stack */
void	swap(t_stack *stack, char stack_name)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	if (stack_name == 'a')
		write(1, "sa\n", 3);
	else if (stack_name == 'b')
		write(1, "sb\n", 3);
}

/* Base push operation - moves top element from src to dest */
void	push(t_stack *src, t_stack *dest, char stack_name)
{
	t_node	*temp;

	if (!src || !src->top)
		return ;
	temp = src->top;
	src->top = src->top->next;
	temp->next = dest->top;
	dest->top = temp;
	src->size--;
	dest->size++;
	if (stack_name == 'a')
		write(1, "pa\n", 3);
	else if (stack_name == 'b')
		write(1, "pb\n", 3);
}

/* Base rotate operation - first element becomes last */
void	rotate(t_stack *stack, char stack_name)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
	if (stack_name == 'a')
		write(1, "ra\n", 3);
	else if (stack_name == 'b')
		write(1, "rb\n", 3);
}

/* Base reverse rotate - last element becomes first */
void	reverse_rotate(t_stack *stack, char stack_name)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	last = stack->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
	if (stack_name == 'a')
		write(1, "rra\n", 4);
	else if (stack_name == 'b')
		write(1, "rrb\n", 4);
}
