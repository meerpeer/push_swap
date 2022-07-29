/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 13:14:33 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/07/29 18:09:12 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void	on_exit(void)
// {
// 	system("leaks push_swap");
// 	return ;
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_moves	moves;

	if (argc <= 1)
		exit (1);
	stack_a = parse_input(&argv[1]);
	stack_b = NULL;
	moves = init_moves();
	if (is_sorted(stack_a))
		exit (0);
	try_smallsort(&stack_a, &stack_b);
	big_sort(&stack_a, &stack_b, &moves);
	exit (0);
}
