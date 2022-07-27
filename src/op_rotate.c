/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:51:37 by mevan-de          #+#    #+#             */
/*   Updated: 2022/07/27 15:41:04 by merel            ###   ########.fr       */
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

int	get_rotate_count(t_stack *stack, int index)
{
	int	total;

	total = lstsize(stack);
	if (index < (total / 2))
	{
		//ft_printf("index = %i\n", index);
		return index;
	}
	//ft_printf("-total + index = %i\n", (-total  + index));
		return (-total  + index);
}

void	rotate_element_to_top(t_stack **stack, int index, char stack_letter)
{
	int	total;

	total = lstsize(*stack);
	while (index > 0 && index < total)
	{
		if (index > (total / 2))
		{
			if (stack_letter == 'a' || stack_letter == 'A')
				operation("rra", stack, NULL);
			else if (stack_letter == 'b' || stack_letter == 'B')
				operation("rrb", NULL, stack);
			index++;
		}
		else
		{
			if (stack_letter == 'a' || stack_letter == 'A')
				operation("ra", stack, NULL);
			else if (stack_letter == 'b' || stack_letter == 'B')
				operation("rb", NULL, stack);
			index--;
		}
	}
}
