/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/21 12:03:16 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/07/28 12:42:55 by mevan-de      ########   odam.nl         */
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
	else if (ft_strncmp(op_name, "pb", op_name_len) == 0)
		op_succes = push(stack_a, stack_b);
	else if (ft_strncmp(op_name, "pa", op_name_len) == 0)
		op_succes = push(stack_b, stack_a);
	else if (ft_strncmp(op_name, "r", 1) == 0)
		op_succes = rotation_operation(stack_a, stack_b, op_name);
	if (op_succes)
		ft_printf("%s\n", op_name);

	//ft_printf("operation tried = %s\n", op_name);
	//ft_printf("comp = %i\n", ft_strncmp(op_name, "rrr", op_name_len));
}
