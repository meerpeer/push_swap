/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:03:16 by mevan-de          #+#    #+#             */
/*   Updated: 2022/07/27 17:53:34 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	operation(char *op_name, t_stack **stack_a, t_stack **stack_b)
{
	t_bool	op_succes;
	int		op_name_len;

	op_succes = FALSE;
	op_name_len = ft_strlen(op_name) + 1;
	if (ft_strncmp(op_name, "sa", op_name_len) == 0)
		op_succes = swap(stack_a);
	else if (ft_strncmp(op_name, "sb", op_name_len) == 0)
		op_succes = swap(stack_b); 
	else if (ft_strncmp(op_name, "ss", op_name_len) == 0)
		op_succes = swap_both(stack_a, stack_b);
	else if (ft_strncmp(op_name, "ra", op_name_len) == 0)
		op_succes = rotate(stack_a);
	else if (ft_strncmp(op_name, "rb", op_name_len) == 0)
		op_succes = rotate(stack_b);
	else if (ft_strncmp(op_name, "rra", op_name_len) == 0)
		op_succes = reverse_rotate(stack_a);
	else if (ft_strncmp(op_name, "rrb", op_name_len) == 0)
		op_succes = reverse_rotate(stack_b);
	//pb (push b): Take the first element at the top of a and put it at the top of b.
	else if (ft_strncmp(op_name, "pb", op_name_len) == 0)
		op_succes = push(stack_a, stack_b);
	else if (ft_strncmp(op_name, "pa", op_name_len) == 0)
		op_succes = push(stack_b, stack_a);
	else if (ft_strncmp(op_name, "pb", op_name_len) == 0)
		op_succes = push(stack_a, stack_b);
	else if (ft_strncmp(op_name, "rr", op_name_len) == 0)
	{
		//ft_printf("rotating both\n");
		rotate_element_to_top(stack_a, 1, 'a');
		rotate_element_to_top(stack_b, 1, 'b');
	}
	else if (ft_strncmp(op_name, "rrr", op_name_len) == 0)
	{
		rotate_element_to_top(stack_a, lstsize(*stack_a), 'a');
		rotate_element_to_top(stack_b, lstsize(*stack_b), 'b');
	}
	if (op_succes)
		ft_printf("%s\n", op_name);
}
