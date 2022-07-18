/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:05:46 by merel             #+#    #+#             */
/*   Updated: 2022/07/18 18:32:38 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_numbers	*lstlast(t_numbers *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	list_add_to_back(t_numbers **lst, t_numbers *new_number)
{
	t_numbers	*last;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new_number;
		return ;
	}
	last = lstlast(*lst);
	last->next = new_number;
}


// this is where it goes wrong. You're not actually storing the int, 
// but you are storing the address, check how you did this in so_long.
t_numbers	*new_element(int *number)
{
	t_numbers	*new_number;

	ft_printf("adding new element = %i\n", number);
	new_number = ft_calloc(1, sizeof(struct s_numbers));
	new_number->number = number;
	new_number->next = NULL;
	new_number->rank = NULL;
	ft_printf("added new element = %i\n", new_number->number);
	return (new_number);
}