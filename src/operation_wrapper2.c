/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_wrapper2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeffaux <qdeffaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:01:35 by qdeffaux          #+#    #+#             */
/*   Updated: 2025/08/12 06:32:22 by qdeffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	rotate(a, 'a');
}

void	rb(t_stack *b)
{
	rotate(b, 'b');
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a || !a->top || !a->top->next)
		return ;
	if (!b || !b->top || !b->top->next)
		return ;
	rotate(a, 0);
	rotate(b, 0);
	write(1, "rr\n", 3);
}

void	rra(t_stack *a)
{
	reverse_rotate(a, 'a');
}

void	rrb(t_stack *b)
{
	reverse_rotate(b, 'b');
}
