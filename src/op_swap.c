/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:24:12 by mevan-de          #+#    #+#             */
/*   Updated: 2022/07/25 20:15:08 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


t_bool	swap(t_stack **stack)
{
	t_stack	*third_element;
	t_stack	*first_element;

	first_element = *stack;
	if (!first_element->next)
		return (FALSE);
	third_element = first_element->next->next;
	first_element->next->next = first_element;
	*stack = first_element->next;
	first_element->next = third_element;
	return (TRUE);
}

t_bool	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	if (swap(stack_a))
	{
		if (swap(stack_b))
			return (TRUE);
		else
			swap(stack_a);
	}
	return (FALSE);
}
