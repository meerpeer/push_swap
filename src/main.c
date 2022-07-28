/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 13:14:33 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/07/28 15:26:06 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	on_exit(void)
{
	system("leaks push_swap");
	return ;
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_moves		moves;

	atexit(on_exit);
	stack_a = parse_input(argc - 1, argv);
	stack_b = NULL;
	moves = init_moves();
	if (is_sorted(stack_a))
		return (0);
	try_smallsort(&stack_a, &stack_b);
	big_sort(&stack_a, &stack_b, &moves);
	exit (0);
}
