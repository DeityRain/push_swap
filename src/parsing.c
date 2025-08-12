/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeffaux <qdeffaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:01:35 by qdeffaux          #+#    #+#             */
/*   Updated: 2025/08/12 07:13:16 by qdeffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	safe_atoi(char *str, int *error)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	*error = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result > -(long)INT_MIN))
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	return ((int)(result * sign));
}

int	*parse_arguments(int argc, char **argv, int *size)
{
	int	*numbers;
	int	i;
	int	error;

	*size = argc - 1;
	numbers = malloc(sizeof(int) * (*size));
	if (!numbers)
		return (NULL);
	i = 0;
	while (i < *size)
	{
		if (!is_valid_number(argv[i + 1]))
		{
			free(numbers);
			return (NULL);
		}
		numbers[i] = safe_atoi(argv[i + 1], &error);
		if (error)
		{
			free(numbers);
			return (NULL);
		}
		i++;
	}
	return (numbers);
}

int	has_duplicates(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
