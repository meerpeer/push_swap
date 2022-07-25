/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:00:34 by mevan-de          #+#    #+#             */
/*   Updated: 2022/07/25 17:54:37 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_2(t_numbers **stack_a)
{
	if (is_sorted(*stack_a))
		exit (0);
	else
		operation("sa", stack_a, NULL);
}

void	sort_3(t_numbers **stack_a)
{
	int			a;
	int			b;
	int			c;

	a = stack_a[0]->rank;
	b = stack_a[0]->next->rank;
	c = stack_a[0]->next->next->rank;
	if (is_sorted(stack_a[0]))
		exit (0);
	if //(a == 1 && b == 0 && c == 2)
	(a > b && a < c && b < c)
		operation("sa", stack_a, NULL);
	if (a < b && a > c && b > c)
	//(a == 1 && b == 2 && c == 0)
		operation("rra", stack_a, NULL);
	if (a > b && a > c && b < c)
	//(a == 2 && b == 0 && c == 1)
		operation("ra", stack_a, NULL);
	if (a < b && a < c && b > c)
		//a == 0 && b == 2 && c == 1)
	{	
		operation("sa", stack_a, NULL);
		operation("ra", stack_a, NULL);
	}
	if (a > b && a > c && b > c)
		//(a == 2 && b == 1 && c == 0)
	{	
		operation("sa", stack_a, NULL);
		operation("rra", stack_a, NULL);
	}
}

void	sort_4(t_numbers **stack_a, t_numbers **stack_b)
{
	rotate_lowest_to_top(stack_a);
	operation("pb", stack_a, stack_b);
	sort_3(stack_a);
	operation("pa", stack_a, stack_b);
	return ;
}

void	sort_5(t_numbers **stack_a, t_numbers **stack_b)
{
	rotate_lowest_to_top(stack_a);
	operation("pb", stack_a, stack_b);
	sort_4(stack_a, stack_b);
	operation("pa", stack_a, stack_b);
}

void	try_smallsort(t_numbers **stack_a, t_numbers **stack_b)
{
	int	stack_a_size;

	stack_a_size = lstsize(*stack_a);
	if (stack_a_size == 2)
		sort_2(stack_a);
	else if (stack_a_size == 3)
		sort_3(stack_a);
	else if (stack_a_size == 4)
		sort_4(stack_a, stack_b);
	else if (stack_a_size == 5)
		sort_5(stack_a, stack_b);
	if (is_sorted(*stack_a) && !*stack_b)
		exit (0);
}
