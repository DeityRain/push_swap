/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeffaux <qdeffaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:01:35 by qdeffaux          #+#    #+#             */
/*   Updated: 2025/08/12 07:15:16 by qdeffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "push_swap.h"

char *int_to_binary(int n)
{
    // Enough for bits + '\0'
    char *binary = malloc(CHAR_BIT * sizeof(int) + 1);
    if (!binary)
        return NULL;
    // Start from highest bit
    unsigned int mask = 1 << (CHAR_BIT * sizeof(int) - 1); 
    int i = 0;
    int started = 0;

    // Special case for zero
    if (n == 0)
    {
        binary[0] = '0';
        binary[1] = '\0';
        return binary;
    }

    // Handle negative numbers with two's complement representation
    unsigned int num = (unsigned int) n;

    while (mask)
    {
        if (num & mask)
        {
            binary[i++] = '1';
            started = 1;
        }
        else if (started)
        {
            binary[i++] = '0';
        }
        mask >>= 1;
    }

    binary[i] = '\0';
    return binary;
}

void display_binary(t_stack *a, t_stack *b)
{
    t_node *current_a = a->top;
    t_node *current_b = b->top;

    printf("    STACK A (bin)\t\tSTACK B (bin)\n\n");
    while (current_a || current_b)
    {
        if (current_a)
        {
            char *bin_a = int_to_binary(current_a->value);
            printf("       %-20s", bin_a);
            free(bin_a);
            current_a = current_a->next;
        }
        else
            printf("                           ");

        if (current_b)
        {
            char *bin_b = int_to_binary(current_b->value);
            printf("%s\n", bin_b);
            free(bin_b);
            current_b = current_b->next;
        }
        else
            printf("\n");
    }
    printf("\n");
}
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

static int	get_max_bits(t_stack *stack)
{
	t_node	*current;
	int		max_index;
	int		max_bits;

	if (!stack || !stack->top)
		return (0);
	
	current = stack->top;
	max_index = current->index;
	
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	
	return (max_bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int max_bits;
	int size;
	int i;
	int j;

	max_bits = get_max_bits(a);
	size = a->size;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		// display(a,b);
		// display_binary(a,b);
		while (j < size)
		{
			// display(a,b);
			// display_binary(a,b);
			if (((a->top->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (b->top)
			pa(a, b);
		i++;
	}
	// display(a,b);
	// display_binary(a,b);
}
*/