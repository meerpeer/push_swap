/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 13:14:33 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/07/29 13:57:29 by mevan-de      ########   odam.nl         */
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
	char	**split;

	if (is_int(argv[1]))
	{
		if (argc <= 1)
			error_exit();
		stack_a = parse_input(&argv[1]);
	}
	else
	{
		split = ft_split(argv[1], ' ');
		stack_a = parse_input(split);
	}
	stack_b = NULL;
	moves = init_moves();
	if (is_sorted(stack_a))
		return (0);
	try_smallsort(&stack_a, &stack_b);
	big_sort(&stack_a, &stack_b, &moves);
	exit (0);
}
