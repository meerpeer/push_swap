/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:36:25 by mevan-de          #+#    #+#             */
/*   Updated: 2022/07/25 17:15:12 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//void	pop(t_numbers **top)
// {
// 	t_numbers	*first;

// 	ft_printf("trying to pop\n");

// 	first = *top;
// 	*top = (*top)->next;
// 	free (first);
// }

t_bool	push(t_numbers **source_stack, t_numbers **receive_stack)
{
	t_numbers	*new_source_top;

	if (!*source_stack)
		return (FALSE);
	new_source_top = (*source_stack)->next;
	lstadd_front(receive_stack, *source_stack);
	*source_stack = new_source_top;
	return (TRUE);
}
