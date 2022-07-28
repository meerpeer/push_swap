/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 13:38:03 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/07/28 13:40:36 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	list_set_rank(t_stack *lst, int total)
{
	int			rank;
	t_stack	*temp_lst;
	t_stack	*current_lowest_element;

	rank = 0;
	while (total)
	{
		temp_lst = lst;
		while (temp_lst->rank > -1)
			temp_lst = temp_lst->next;
		current_lowest_element = temp_lst;
		temp_lst = temp_lst->next;
		while (temp_lst)
		{
			if (temp_lst->rank < 0
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

t_stack	*create_linked_number_list(int *numbers)
{
	t_stack	*number_list;
	int		i;

	i = 0;
	number_list = NULL;
	while (numbers[i])
	{
		if (!number_list)
			number_list = lstnew_element(numbers[i], -1);
		else
			lstadd_back(&number_list, lstnew_element(numbers[i], -1));
		i++;
	}
	return (number_list);
}

t_stack	*parse_input(int argc, char **argv)
{
	int			i;
	t_stack	*number_list;
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
