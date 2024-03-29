/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 13:38:03 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/07/29 15:08:41 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	list_set_rank(t_stack *lst, int total)
{
	int		rank;
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

t_stack	*create_linked_number_list(int *numbers, int size)
{
	t_stack	*number_list;
	int		i;

	i = 0;
	number_list = NULL;
	while (i < size)
	{
		if (!number_list)
			number_list = lstnew_element(numbers[i], -1);
		else
			lstadd_back(&number_list, lstnew_element(numbers[i], -1));
		i++;
	}
	return (number_list);
}

int	create_number_list(char **argv, int **numbers)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	*numbers = ft_calloc(i + 1, sizeof(int));
	i = 0;
	while (argv[i])
	{
		if (!is_int(argv[i]))
			error_exit();
		(*numbers)[i] = ft_atoi(argv[i]);
		if (is_double(*numbers, i))
			error_exit();
		i++;
	}
	return (i);
}

t_stack	*parse_input(char **argv)
{
	t_stack	*number_list;
	int		*numbers;
	int		size;

	number_list = NULL;
	numbers = NULL;
	size = create_number_list(argv, &numbers);
	if (!numbers)
		exit (1);
	number_list = create_linked_number_list(numbers, size);
	list_set_rank(number_list, size);
	free(numbers);
	return (number_list);
}
