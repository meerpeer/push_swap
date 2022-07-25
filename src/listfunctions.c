/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:05:46 by merel             #+#    #+#             */
/*   Updated: 2022/07/25 20:15:08 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*lst_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_stack **lst, t_stack *new_number)
{
	t_stack	*last;

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

void	lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

t_stack	*lstnew_element(int number, int rank)
{
	t_stack	*new_number;

	new_number = ft_calloc(1, sizeof(struct s_numbers));
	new_number->number = number;
	new_number->next = NULL;
	new_number->rank = rank;
	return (new_number);
}

int	lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
