/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:10:18 by mevan-de          #+#    #+#             */
/*   Updated: 2022/07/25 17:21:51 by merel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_numbers
{
	int					number;
	int					rank;
	struct s_numbers	*next;
}					t_numbers;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}			t_bool;

t_numbers	*parse_input(int argc, char **argv);

// LIST FUNCTIONS

t_numbers	*lstnew_element(int number, int rank);
void		list_add_to_back(t_numbers **lst, t_numbers *new_number);
t_numbers	*lst_last(t_numbers *lst);
void		lstadd_back(t_numbers **lst, t_numbers *new_number);
void		lstadd_front(t_numbers **lst, t_numbers *new);
int			lstsize(t_numbers *lst);

// MAYBE REMOVE?
void	sort_4(t_numbers **stack_a, t_numbers **stack_b);
void	print_stack(t_numbers *stack, char *stack_name);


// HELPER FUNCTIONS

t_bool		is_int(char *str);
t_bool		is_sorted(t_numbers *stack);
t_bool		is_double(int *numbers, int index);
int			find_lowest_index(t_numbers	*stack);

// small sort stack (up until 5)
void		try_smallsort(t_numbers **stack_a, t_numbers **stack_b);

// OPERATIONS

void		operation(char *op_name, t_numbers **stack_a, t_numbers **stack_b);
/*
Takes a stack and swaps the top 2 elements
Will not do anything if there is only one element
Returns TRUE and prints 'sa' or 'sb' if succesfull

stack = stack to swap
c     = stack name (only takes 'a' or 'b')
*/
t_bool		swap(t_numbers **stack);
t_bool		swap_both(t_numbers **stack_a, t_numbers **stack_b);
t_bool		rotate(t_numbers **stack);
t_bool		reverse_rotate(t_numbers **stack);
t_bool		push(t_numbers **pop_stack, t_numbers **receive_stack);

#endif