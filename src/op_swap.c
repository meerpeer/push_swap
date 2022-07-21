/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/21 11:24:12 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/07/21 16:22:13 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


t_bool	swap(t_numbers **stack, char c)
{
	t_numbers	*third_element;
	t_numbers	*first_element;

	first_element = *stack;
	if ((c != 'a' || c != 'b') && !*stack)
		return (FALSE);
	if (!first_element->next)
		return (FALSE);
	third_element = first_element->next->next;
	first_element->next->next = first_element;
	*stack = first_element->next;
	first_element->next = third_element;
	return (TRUE);
}

t_bool	swap_both(t_numbers **stack_a, t_numbers **stack_b)
{
	if (swap(stack_a, 'a'))
	{
		if (swap(stack_b, 'b'))
			return (TRUE);
		else
			swap(stack_a, 'a');
	}
	return (FALSE);
}
