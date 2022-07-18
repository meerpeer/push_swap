/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:14:33 by mevan-de          #+#    #+#             */
/*   Updated: 2022/07/18 18:27:37 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
//	ft_printf("argc = %i\n", argc);
//	ft_printf("argv[1] = %s\n", argv[1]);
*/

int	main(int argc, char **argv)
{
	t_numbers	*stack_a;
	t_numbers	*stack_b;

	stack_a = parse_input(argc, argv);

	t_numbers	*temp;
	temp = stack_a;
	while (temp)
	{
		ft_printf("number = %i\n", stack_a->number);
		temp = stack_a->next;
	}
	stack_b = NULL;
	return (0);
}
