/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperfunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:11:19 by merel             #+#    #+#             */
/*   Updated: 2022/07/22 12:07:38 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_lowest_index(t_numbers	*stack)
{
	int	i;
	int	last_lowest_index;
	int	last_lowest_rank;

	i = 0;
	last_lowest_rank = stack->rank;
	last_lowest_index = i;
	while (stack)
	{
		if(stack->rank < last_lowest_rank)
		{
			last_lowest_rank = stack->rank;
			last_lowest_index = i;
		}
		stack = stack->next;
		i++;
	}
	return (last_lowest_index);
}

t_bool	is_int(char *str)
{
	while (ft_isdigit(*str) || *str == '-')
		str++;
	if (*str)
		return (FALSE);
	return (TRUE);
}

t_bool	is_sorted(t_numbers *stack)
{
	int	last_rank;

	last_rank = -1;
	while (stack)
	{
		if (stack->rank < last_rank)
			return (FALSE);
		last_rank = stack->rank;
		stack = stack->next;
	}
	return (TRUE);
}

t_bool	is_double(int *numbers, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (numbers[i] == numbers[index])
			return (TRUE);
		i++;
	}
	return (FALSE);
}
