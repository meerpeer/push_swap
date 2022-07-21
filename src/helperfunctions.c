/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helperfunctions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/20 12:11:19 by merel         #+#    #+#                 */
/*   Updated: 2022/07/21 11:01:06 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	is_int(char *str)
{
	while (ft_isdigit(*str))
		str++;
	if (*str)
		return (FALSE);
	return (TRUE);
}

t_bool	stack_is_ordered(t_numbers *stack)
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
