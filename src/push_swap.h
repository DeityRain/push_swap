/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeffaux <qdeffaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:43:24 by qdeffaux          #+#    #+#             */
/*   Updated: 2025/08/14 07:10:05 by qdeffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/* Stack node structure */
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

/* Stack structure */
typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

/* Parsing functions */
int					*parse_arguments(int argc, char **argv, int *size);
int					has_duplicates(int *numbers, int size);
void				assign_indices(int *numbers, int size);

/* Stack operations */
t_stack				*init_stack(void);
void				push_node(t_stack *stack, int value, int index);
int					pop_node(t_stack *stack);
void				free_stack(t_stack *stack);
int					is_sorted(t_stack *stack);
int					get_stack_size(t_stack *stack);

/* Base operations */
void				swap(t_stack *stack, char stack_name);
void				push(t_stack *src, t_stack *dest, char stack_name);
void				rotate(t_stack *stack, char stack_name);
void				reverse_rotate(t_stack *stack, char stack_name);

/* Push_swap operations */
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

/* Sorting algorithms */
void				sort_stack(t_stack *a, t_stack *b, int size);
void				sort_three(t_stack *a);
void				sort_five(t_stack *a, t_stack *b);
void				turk_algorithm(t_stack *a, t_stack *b);
void				radix_sort(t_stack *a, t_stack *b);

/* Helper functions */
int					find_min(t_stack *stack);
int					find_max(t_stack *stack);
int					find_min_position(t_stack *stack);
void				ft_free(int *num, int *origin_num, t_stack *a, t_stack *b);

/* Turk algorithm functions */
int					calculate_rotation_cost(int pos, int size);
int					find_target_position_in_b(t_stack *b, int value);
int					find_target_position_in_a(t_stack *a, int value);
int					calculate_push_cost(t_stack *a, t_stack *b, int pos_a);
int					find_max_position_in_b(t_stack *b);
void				execute_simultaneous_rotations(t_stack *a, t_stack *b,
						int *pos_a, int *target_pos_b);
void				execute_individual_rotations(t_stack *a, t_stack *b,
						int pos_a, int target_pos_b);
void				push_with_cost_analysis(t_stack *a, t_stack *b);
void				push_back_optimally(t_stack *a, t_stack *b);
void				final_rotation(t_stack *a);

#endif
