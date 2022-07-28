/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 13:14:33 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/07/28 13:39:44 by mevan-de      ########   odam.nl         */
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
	big_sort(&stack_a, &stack_b, &moves);
	return (0);
}
