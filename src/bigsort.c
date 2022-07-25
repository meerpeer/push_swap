/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:12:40 by merel             #+#    #+#             */
/*   Updated: 2022/07/25 21:45:41 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_rank_index(t_stack *stack, int rank)
{
	int	i;

	i = 0;
	while (stack->rank != rank && stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	pre_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		total;
	int		max_range;
	t_stack	*stack_iter;

	total = lstsize(*stack_a);
	while (lstsize(*stack_a) > 5)
	{
		max_range = (total - get_lowest_rank(*stack_a)) / 2;
		stack_iter = *stack_a;
		while (stack_iter)
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
			//ft_printf("next\n");
		}
	}
	try_smallsort(stack_a, stack_b);
	return ;
}

void	try_bigsort(t_stack **stack_a, t_stack **stack_b)
{
	pre_sort(stack_a, stack_b);
	return ;
}
