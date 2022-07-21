/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Push_Swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 13:10:18 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/07/21 17:01:58 by mevan-de      ########   odam.nl         */
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

t_numbers	*lstnew_element(int number);
void		list_add_to_back(t_numbers **lst, t_numbers *new_number);
t_numbers	*lst_last(t_numbers *lst);
void		lstadd_back(t_numbers **lst, t_numbers *new_number);
void		lstadd_front(t_numbers **lst, t_numbers *new);


// HELPER FUNCTIONS

t_bool		is_int(char *str);
t_bool		is_sorted(t_numbers *stack);
t_bool		is_double(int *numbers, int index);

// small sort stack (up until 5)


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

#endif