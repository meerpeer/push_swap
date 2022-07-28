/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/28 13:34:26 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/07/28 13:35:29 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_rank_index(t_stack *stack, int rank)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->rank == rank)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}

int	get_lowest_rank(t_stack *stack)
{
	int	last_lowest;

	if (!stack)
		return (-1);
	last_lowest = stack->rank;
	while (stack)
	{
		if (stack->rank < last_lowest)
			last_lowest = stack->rank;
		stack = stack->next;
	}
	return (last_lowest);
}

int	find_lowest_index(t_stack	*stack)
{
	int	i;
	int	last_lowest_index;
	int	last_lowest_rank;

	i = 0;
	last_lowest_rank = stack->rank;
	last_lowest_index = i;
	while (stack)
	{
		if (stack->rank < last_lowest_rank)
		{
			last_lowest_rank = stack->rank;
			last_lowest_index = i;
		}
		stack = stack->next;
		i++;
	}
	return (last_lowest_index);
}

t_bool	is_sorted(t_stack *stack)
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
