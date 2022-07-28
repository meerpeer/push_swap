/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_push.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/21 16:36:25 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/07/28 14:39:03 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	push(t_stack **source_stack, t_stack **receive_stack)
{
	t_stack	*new_source_top;

	if (!*source_stack)
		return (FALSE);
	new_source_top = (*source_stack)->next;
	lstadd_front(receive_stack, *source_stack);
	*source_stack = new_source_top;
	return (TRUE);
}
