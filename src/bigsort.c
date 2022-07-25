/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:12:40 by merel             #+#    #+#             */
/*   Updated: 2022/07/25 20:34:46 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pre_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	total;
	int	lowest_rank;
	int	i;
	
	total = lstsize(stack_a);
	i = 0;
	
	while (lstsize(stack_a) > 5)
	{
		lowest_rank = get_lowest_rank(stack_a);
		i = lowest_rank;
		while (i < (total - lowest_rank) / 2)
		{
			
		}
	}
	try_smallsort(stack_a, stack_b);
}

void	try_bigsort(t_stack **stack_a, t_stack **stack_b)
{
	pre_sort(stack_a, stack_b);
	
}
