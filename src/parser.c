/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 13:38:03 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/07/21 16:43:28 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	list_set_rank(t_numbers *lst, int total)
{
	int			rank;
	t_numbers	*temp_lst;
	t_numbers	*current_lowest_element;

	rank = 1;
	while (total)
	{
		temp_lst = lst;
		while (temp_lst->rank > 0)
			temp_lst = temp_lst->next;
		current_lowest_element = temp_lst;
		temp_lst = temp_lst->next;
		while (temp_lst)
		{
			if (temp_lst->rank <= 0
				&& current_lowest_element->number > temp_lst->number)
				current_lowest_element = temp_lst;
			temp_lst = temp_lst->next;
		}
		current_lowest_element->rank = rank;
		total--;
		rank++;
	}
	return ;
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
		if (!number_list)
			number_list = lstnew_element(numbers[i]);
		else
			lstadd_back(&number_list, lstnew_element(numbers[i]));
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
	numbers = ft_calloc(argc + 1, sizeof(int));
	i = 0;
	if (argc <= 1)
		error_exit();
	while (argc - i >= 1)
	{
		if (!is_int(argv[i + 1]))
			error_exit();
		numbers[i] = ft_atoi(argv[i + 1]);
		if (is_double(numbers, i))
			error_exit();
		i++;
	}
	if (numbers)
		number_list = create_linked_number_list(numbers);
	free(numbers);
	list_set_rank(number_list, argc);
	return (number_list);
}
