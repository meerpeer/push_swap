/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bigsort.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/25 20:12:40 by merel         #+#    #+#                 */
/*   Updated: 2022/07/28 14:38:31 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_moves	init_moves(void)
{
	t_moves	moves;

	moves.ra = 0;
	moves.rb = 0;
	moves.rr = 0;
	moves.total = 0;
	return (moves);
}

void	do_x_move(t_stack **stack_a, t_stack **stack_b, char *op_name, int x)
{
	int	adjust;

	adjust = x / ft_abs(x);
	while (x)
	{
		operation(op_name, stack_a, stack_b);
		x -= adjust;
	}
}

void	do_moves(t_stack **stack_a, t_stack **stack_b, t_moves *moves)
{
	if (moves->rr > 0)
		do_x_move(stack_a, stack_b, "rr", moves->rr);
	else if (moves->rr < 0)
		do_x_move(stack_a, stack_b, "rrr", moves->rr);
	if (moves->ra > 0)
		do_x_move(stack_a, stack_b, "ra", moves->ra);
	else if (moves->ra < 0)
		do_x_move(stack_a, stack_b, "rra", moves->ra);
	if (moves->rb > 0)
		do_x_move(stack_a, stack_b, "rb", moves->rb);
	else if (moves->rb < 0)
		do_x_move(stack_a, stack_b, "rrb", moves->rb);
	*moves = init_moves();
}

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

void	big_sort(t_stack **stack_a, t_stack **stack_b, t_moves *moves)
{
	pre_sort(stack_a, stack_b);
	if (is_sorted(*stack_a) && !*stack_b)
		exit (0);
	while (*stack_b)
	{
		set_lowest_nr_moves(stack_a, stack_b, moves);
		do_moves(stack_a, stack_b, moves);
		operation("pa", stack_a, stack_b);
	}
	if (is_sorted(*stack_a))
		ft_printf("sorted\n");
	rotate_element_to_top(stack_a, get_rank_index(*stack_a, 0), 'a');
	return ;
}
