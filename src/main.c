/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:14:33 by mevan-de          #+#    #+#             */
/*   Updated: 2022/07/25 17:51:02 by merel            ###   ########.fr       */
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

void	print_stack(t_numbers *stack, char *stack_name)
{
	ft_printf("\nPrinting: %s\n", stack_name);
	ft_printf("------------\n");
	while(stack)
	{
		ft_printf("number = %i\n", stack->number);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_numbers	*stack_a;
	t_numbers	*stack_b;

	argc -= 1;
	stack_a = parse_input(argc, argv);
	stack_b = NULL;
	if (is_sorted(stack_a))
		return (0);
	//sort_4(&stack_a, &stack_b);
	try_smallsort(&stack_a, &stack_b);
	print_stack(stack_a, "A");
	

	return (0);
}
