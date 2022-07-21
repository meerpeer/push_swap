/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/21 12:03:16 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/07/21 17:02:30 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	if (op_succes)
		ft_printf("%s\n", op_name);
}
