/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/21 16:51:37 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/07/28 12:42:16 by mevan-de      ########   odam.nl         */
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
		return (index);
	return (-total + index);
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

t_bool	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	if (rotate(stack_a))
	{
		if (rotate(stack_b))
			return (TRUE);
		reverse_rotate(stack_a);
	}
	return (FALSE);
}

t_bool	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	if (reverse_rotate(stack_a))
	{
		if (reverse_rotate(stack_b))
			return (TRUE);
		rotate(stack_a);
	}
	return (FALSE);
}

t_bool	rotation_operation(t_stack **stack_a, t_stack **stack_b, char *op_name)
{
	t_bool	op_succes;
	int		op_name_len;

	op_succes = FALSE;
	op_name_len = ft_strlen(op_name) + 1;
	if (ft_strncmp(op_name, "ra", op_name_len) == 0)
		op_succes = rotate(stack_a);
	else if (ft_strncmp(op_name, "rb", op_name_len) == 0)
		op_succes = rotate(stack_b);
	else if (ft_strncmp(op_name, "rra", op_name_len) == 0)
		op_succes = reverse_rotate(stack_a);
	else if (ft_strncmp(op_name, "rrb", op_name_len) == 0)
		op_succes = reverse_rotate(stack_b);
	else if (ft_strncmp(op_name, "rr", op_name_len) == 0)
		op_succes = rotate_both(stack_a, stack_b);
	else if (ft_strncmp(op_name, "rrr", op_name_len) == 0)
		op_succes = reverse_rotate_both(stack_a, stack_b);
	return (op_succes);
}