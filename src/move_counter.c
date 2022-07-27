/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:48:40 by merel             #+#    #+#             */
/*   Updated: 2022/07/27 14:49:35 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_best_a_count(t_stack **stack_a, int stack_b_rank)
{
	t_stack	*iter_a;
	int		rotate_count;
	int		last_best;

	last_best = lstsize(*stack_a);
	iter_a = *stack_a;
	while (iter_a)
	{
		if (iter_a->rank < stack_b_rank)
		{
			rotate_count = get_rotate_count (*stack_a,
				get_rank_index(*stack_a, iter_a->rank));
			if (ft_abs(rotate_count) < ft_abs(last_best))
				last_best = rotate_count;
		}
		iter_a = iter_a->next;
	}
	return (last_best);
}

int	get_rr_count(int ra_ops, int rb_ops)
{
	int	rr_ops;
	int	adjust;

			// if (cur_op_count.ra > 0 && cur_op_count.rb > 0)
			// ft_abs(cur_op_count.ra -  cur_op_count.rb);
	rr_ops = 0; 
	adjust = 0; //remove
	if (ra_ops > 0 && rb_ops > 0)
		adjust = 1;
	else if (ra_ops < 0 && rb_ops < 0)
		adjust = -1;
	else 
		return (0);
	// ft_printf("ra = %i\n", ra_ops);
	// ft_printf("rb = %i\n", rb_ops);
	// ft_printf("adjust = %i\n", adjust);
	while (ra_ops != 0 && rb_ops != 0)
	{
		rr_ops -= adjust;
		ra_ops -= adjust;
		rb_ops -= adjust;
	}
	//ft_printf("exit loop count\n");

	return (rr_ops);
}

void	set_lowest_nr_moves(t_stack **stack_a, t_stack **stack_b,
	t_op_count *op_count)
{
	t_stack		*iter_b;
	t_op_count	cur_op_count;

	iter_b = *stack_b;
	while (iter_b)
	{
		cur_op_count.ra = get_best_a_count(stack_a, iter_b->rank);
		cur_op_count.rb  = get_rotate_count(*stack_b, 
			get_rank_index(*stack_b, iter_b->rank));
		cur_op_count.rr = get_rr_count(cur_op_count.ra, cur_op_count.rb);
		cur_op_count.ra -= cur_op_count.rr;
		cur_op_count.rb -= cur_op_count.rr;
		cur_op_count.total = cur_op_count.ra + cur_op_count.rb + cur_op_count.rr;
		if (op_count->total == 0)
			*op_count = cur_op_count;
		else if (ft_abs(op_count->total) > ft_abs(cur_op_count.total))
			*op_count = cur_op_count;
		iter_b = iter_b->next;
	}
}
