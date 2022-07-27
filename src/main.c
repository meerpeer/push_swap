/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:14:33 by mevan-de          #+#    #+#             */
/*   Updated: 2022/07/27 15:07:45 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
//	ft_printf("argc = %i\n", argc);
//	ft_printf("argv[1] = %s\n", argv[1]);

check ranks in stack a 
	while(stack_a)
	{
		ft_printf("rank = %i\n", stack_a->rank);
		stack_a = stack_a->next;
	}
	while(stack_a)
	{
		ft_printf("number = %i\n", stack_a->number);
		stack_a = stack_a->next;
	}
*/

void	print_stack(t_stack *stack, char *stack_name)
{
	//if(stack == NULL)
	//	return ;
	ft_printf("\nPrinting: %s\n", stack_name);
	ft_printf("------------\n");
	while(stack)
	{
		ft_printf("number = %i\n", stack->number);
		stack = stack->next;
	}
	ft_printf("------------\n");
}


t_moves	init_moves(void)
{
	t_moves moves;

	moves.ra = 0;
	//moves.rra = 0;
	moves.rb = 0;
	//moves.rrb = 0;
	moves.rr = 0;
	//moves.rrr = 0;
	moves.total = 0;
	return (moves);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_moves	moves;

	argc -= 1;
	stack_a = parse_input(argc, argv);
	stack_b = NULL;
	moves = init_moves();
	if (is_sorted(stack_a))
		return (0);
	try_smallsort(&stack_a, &stack_b);
	try_bigsort(&stack_a, &stack_b, &moves);
	//print_stack(stack_a, "A");
//	print_stack(stack_b, "B");
	return (0);
}
