/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:14:33 by mevan-de          #+#    #+#             */
/*   Updated: 2022/07/20 12:07:48 by merel            ###   ########.fr       */
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
	stack_b = NULL;
	
	return (0);
}
