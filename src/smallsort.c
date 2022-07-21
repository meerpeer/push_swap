/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smallsort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/21 11:00:34 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/07/21 16:59:41 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_2(t_numbers **stack)
{
	if (is_sorted(*stack))
		exit (0);
	else
		operation("sa", stack, NULL);
}

// void	sort_3(t_numbers **stack)
// {
// 	int	a;
// 	int	b;
// 	int	c;
	
	
// 	a = stack->rank;
// 	b = stack->next->rank;
// 	c = stack->next->next->rank;
// 	if (is_sorted(*stack))
// 		exit (0);
// 	if (a < b && b > a)
// 	{
// 		//sa
// 		//ra
// 	}

// }
