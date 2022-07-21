/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   listfunctions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/18 18:05:46 by merel         #+#    #+#                 */
/*   Updated: 2022/07/21 13:59:24 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_numbers	*lst_last(t_numbers *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_numbers **lst, t_numbers *new_number)
{
	t_numbers	*last;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new_number;
		return ;
	}
	last = lst_last(*lst);
	last->next = new_number;
}

void	lstadd_front(t_numbers **lst, t_numbers *new)
{
	new->next = *lst;
	*lst = new;
}

t_numbers	*lstnew_element(int number)
{
	t_numbers	*new_number;

	new_number = ft_calloc(1, sizeof(struct s_numbers));
	new_number->number = number;
	new_number->next = NULL;
	new_number->rank = -1;
	return (new_number);
}
