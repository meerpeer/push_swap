/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:48:40 by merel             #+#    #+#             */
/*   Updated: 2022/07/27 17:08:42 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_insert_index(t_stack **stack, int insert_rank)
{
	t_stack	*iter_stack;
	int		last_difference;
	int		difference;
	int		best_index;
	int		index;
	int		rank_above;

	if (!*stack)
		return (0);
	index = 0;
	iter_stack = *stack;
	best_index = 0;
	rank_above = lst_last(iter_stack)->rank;
	last_difference = lstsize(*stack);
	while (iter_stack)
	{
		if (insert_rank == 0 && iter_stack->rank == get_lowest_rank(*stack))
		{
			ft_printf("index 0 = %i\n", index);
			return (index);
		}
		else if (iter_stack->rank > insert_rank)
		{
			difference = iter_stack->rank - insert_rank;
			ft_printf("best index = %i\n", index);
			if (difference < last_difference)
			{
				ft_printf("best index = %i\n", index);
				best_index = index;
				last_difference = difference;
			}
		}
		
		rank_above = iter_stack->rank;
		iter_stack = iter_stack->next;
		index++;
	}
	//ft_printf("\nLAST BEST = %i\n", last_best);
	return (best_index);
}

int	get_rr_count(int ra_ops, int rb_ops)
{
	int	rr_ops;
	int	adjust;

			// if (cur_moves.ra > 0 && cur_moves.rb > 0)
			// ft_abs(cur_moves.ra -  cur_moves.rb);
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
	t_moves *moves)
{
	t_stack	*iter_b;
	t_moves	cur_moves;

	iter_b = *stack_b;
	while (iter_b)
	{
		cur_moves.ra = get_rotate_count(*stack_a, get_insert_index(stack_a, 
			iter_b->rank));
		cur_moves.rb  = get_rotate_count(*stack_b, 
			get_rank_index(*stack_b, iter_b->rank));
//		ft_printf("\nra = %i\n", moves->ra);
//		ft_printf("rb = %i\n", moves->rb);
		cur_moves.rr = get_rr_count(cur_moves.ra, cur_moves.rb);
		cur_moves.ra -= cur_moves.rr;
		cur_moves.rb -= cur_moves.rr;
//		ft_printf("ra = %i\n", moves->ra);
//		ft_printf("rb = %i\n", moves->rb);
		cur_moves.total = ft_abs(cur_moves.ra) + ft_abs(cur_moves.rb)
			+ ft_abs(cur_moves.rr);
		if (moves->total == 0)
			*moves = cur_moves;
		else if (ft_abs(moves->total) > ft_abs(cur_moves.total))
			*moves = cur_moves;
		iter_b = iter_b->next;
	}
}
