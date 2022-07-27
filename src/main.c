/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:14:33 by mevan-de          #+#    #+#             */
/*   Updated: 2022/07/27 10:19:22 by merel            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	argc -= 1;
	stack_a = parse_input(argc, argv);
	stack_b = NULL;
	if (is_sorted(stack_a))
		return (0);
	//sort_4(&stack_a, &stack_b);
	try_smallsort(&stack_a, &stack_b);
	try_bigsort(&stack_a, &stack_b);
	//print_stack(stack_a, "A");
//	print_stack(stack_b, "B");
	return (0);
}
