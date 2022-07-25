/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:03:16 by mevan-de          #+#    #+#             */
/*   Updated: 2022/07/25 17:53:09 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// maybe make it universal later?
void	rotate_lowest_to_top(t_numbers **stack_a)
{
	int	total;
	int	lowest;

	total = lstsize(*stack_a);
	lowest = find_lowest_index(*stack_a);
	while (lowest > 0 && lowest < total)
	{
		if (lowest > (total / 2))
		{
			operation("rra", stack_a, NULL);
			lowest++;
		}
		else
		{
			operation("ra", stack_a, NULL);
			lowest--;
		}
	}
	//print_stack(*stack_a, "rotated lowest to top");
}

void	operation(char *op_name, t_numbers **stack_a, t_numbers **stack_b)
{
	t_bool	op_succes;
	int		op_name_len;

	op_succes = FALSE;
	op_name_len = ft_strlen(op_name);
	if (ft_strncmp(op_name, "sa", op_name_len) == 0)
		op_succes = swap(stack_a);
	else if (ft_strncmp(op_name, "sb", op_name_len) == 0)
		op_succes = swap(stack_b); 
	else if (ft_strncmp(op_name, "ss", op_name_len) == 0)
		op_succes = swap_both(stack_a, stack_b);
	else if (ft_strncmp(op_name, "ra", op_name_len) == 0)
		op_succes = rotate(stack_a);
	else if (ft_strncmp(op_name, "rra", op_name_len) == 0)
		op_succes = reverse_rotate(stack_a);
	else if (ft_strncmp(op_name, "rrb", op_name_len) == 0)
		op_succes = reverse_rotate(stack_b);
	//pb (push b): Take the first element at the top of a and put it at the top of b.
	else if (ft_strncmp(op_name, "pb", op_name_len) == 0)
		op_succes = push(stack_a, stack_b);
	else if (ft_strncmp(op_name, "pa", op_name_len) == 0)
		op_succes = push(stack_b, stack_a);
	if (op_succes)
		ft_printf("%s\n", op_name);
}
