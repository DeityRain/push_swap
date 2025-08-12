/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_wrapper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeffaux <qdeffaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:01:35 by qdeffaux          #+#    #+#             */
/*   Updated: 2025/08/12 06:48:09 by qdeffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	swap(a, 'a');
}

void	sb(t_stack *b)
{
	swap(b, 'b');
}

void	ss(t_stack *a, t_stack *b)
{
	if (!a || !a->top || !a->top->next)
		return ;
	if (!b || !b->top || !b->top->next)
		return ;
	swap(a, 0);
	swap(b, 0);
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a, 'a');
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b, 'b');
}
