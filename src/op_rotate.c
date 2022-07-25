/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:51:37 by mevan-de          #+#    #+#             */
/*   Updated: 2022/07/25 20:15:08 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	rotate(t_stack **stack)
{
	t_stack	*old_first;

	old_first = *stack;
	lstadd_back(stack, *stack);
	*stack = old_first->next;
	old_first->next = NULL;
	return (TRUE);
}

t_bool	reverse_rotate(t_stack **stack)
{
	t_stack	*old_last;
	t_stack	*i_list;

	old_last = lst_last(*stack);
	lstadd_front(stack, old_last);
	i_list = *stack;
	while (i_list->next != old_last)
		i_list = i_list->next;
	i_list->next = 0;
	return (TRUE);
}
