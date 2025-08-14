/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeffaux <qdeffaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 06:58:57 by qdeffaux          #+#    #+#             */
/*   Updated: 2025/08/12 14:43:36 by qdeffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	sort_array(int *sorted, int size)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (sorted[i] > sorted[j])
			{
				temp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = temp;
			}
		}
	}
}

static void	map_indices(int *sorted, int *numbers, int *result, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (sorted[i] == numbers[j])
				result[j] = i;
		}
	}
}

void	assign_indices(int *numbers, int size)
{
	int	i;
	int	*sorted;
	int	*result;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return ;
	i = -1;
	while (++i < size)
		sorted[i] = numbers[i];
	sort_array(sorted, size);
	result = malloc(sizeof(int) * size);
	map_indices(sorted, numbers, result, size);
	i = -1;
	while (++i < size)
		numbers[i] = result[i];
	free(sorted);
	free(result);
}
