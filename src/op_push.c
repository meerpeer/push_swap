/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:36:25 by mevan-de          #+#    #+#             */
/*   Updated: 2022/07/22 13:04:39 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pop(t_numbers **top)
{
	t_numbers	*first;

	ft_printf("trying to pop\n");

	first = *top;
	*top = (*top)->next;
	free (first);
}

t_bool	push(t_numbers **pop_stack, t_numbers **receive_stack)
{
	t_numbers	*new;

	if (!*pop_stack)
		return (FALSE);
	new = lstnew_element((*pop_stack)->number, (*pop_stack)->rank);
	if(new)
	{
		ft_printf("new rank =%i\n", new->number);
	}
	lstadd_front(receive_stack, new);
	pop(pop_stack);
	return (TRUE);
}
