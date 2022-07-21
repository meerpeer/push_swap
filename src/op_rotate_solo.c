/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_rotate_solo.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/21 16:51:37 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/07/21 16:59:57 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	rotate(t_numbers **stack)
{
	lstadd_back(stack, *stack);
	return (TRUE);
}
