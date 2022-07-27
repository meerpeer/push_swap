/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:12:40 by merel             #+#    #+#             */
/*   Updated: 2022/07/27 14:51:11 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pre_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		total;
	int		max_range;
	t_stack	*stack_iter;

	total = lstsize(*stack_a);
	while (lstsize(*stack_a) > 5)
	{
		max_range = total - ((total - get_lowest_rank(*stack_a)) / 2);
		stack_iter = *stack_a;
		while (stack_iter && lstsize(*stack_a) > 5)
		{
			if (stack_iter->rank < max_range)
			{
				rotate_element_to_top(stack_a, get_rank_index(*stack_a, 
					stack_iter->rank), 'a');
				operation("pb", stack_a, stack_b);
				stack_iter = *stack_a;
			}
			else
				stack_iter = stack_iter->next;
		}
	}
	try_smallsort(stack_a, stack_b);
	return ;
}

void	try_bigsort(t_stack **stack_a, t_stack **stack_b, t_op_count *op_count)
{
	pre_sort(stack_a, stack_b);
	if (is_sorted(*stack_a) && !*stack_b)
		exit (0);
	set_lowest_nr_moves(stack_a, stack_b, op_count);
	ft_printf("lowest nr of moves total = %i\n", op_count->total);
	// set/find lowest nr of moves
	// do those moves
	return ;
}
