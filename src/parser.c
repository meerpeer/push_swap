/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:38:03 by mevan-de          #+#    #+#             */
/*   Updated: 2022/07/20 12:08:17 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	is_double(int *numbers, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (numbers[i] == numbers[index])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool	is_int(char *str)
{
	while (ft_isdigit(*str))
		str++;
	if (*str)
		return (FALSE);
	return (TRUE);
}

void	error_exit(void)
{
	ft_printf("Error\n");
	exit (1);
}

t_numbers	*create_linked_number_list(int *numbers)
{
	t_numbers	*number_list;
	int			i;

	i = 0;
	number_list = NULL;
	while (numbers[i])
	{
		if(!number_list)
			number_list = new_element(numbers[i]);
		else
			list_add_to_back(&number_list, new_element(numbers[i]));
		i++;
		
	}
	return (number_list);
}
/*
while (numbers[i])
	{
		ft_printf("%i\n", numbers[i]);
		i++;
	}
*/
t_numbers	*parse_input(int argc, char **argv)
{
	int			i;
	t_numbers	*number_list;
	int			*numbers;

	number_list = NULL;
	numbers = ft_calloc(argc, sizeof(int));
	i = 0;
	if (argc <= 1)
		error_exit();
	while (argc > 1)
	{
		if (!is_int(argv[i + 1]))
			error_exit();
		numbers[i] = ft_atoi(argv[i + 1]);
		if (is_double(numbers, i))
			error_exit();
		argc--;
		i++;
	}
	if(numbers)
		number_list = create_linked_number_list(numbers);
	free(numbers);
	return (number_list);
}
