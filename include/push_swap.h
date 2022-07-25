/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merel <merel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:10:18 by mevan-de          #+#    #+#             */
/*   Updated: 2022/07/25 21:08:47 by merel            ###   ########.fr       */
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
}					t_stack;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}			t_bool;

t_stack	*parse_input(int argc, char **argv);

// LIST FUNCTIONS

t_stack	*lstnew_element(int number, int rank);
void		list_add_to_back(t_stack **lst, t_stack *new_number);
t_stack	*lst_last(t_stack *lst);
void		lstadd_back(t_stack **lst, t_stack *new_number);
void		lstadd_front(t_stack **lst, t_stack *new);
int			lstsize(t_stack *lst);

// MAYBE REMOVE?
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	print_stack(t_stack *stack, char *stack_name);


// HELPER FUNCTIONS

t_bool		is_int(char *str);
t_bool		is_sorted(t_stack *stack);
t_bool		is_double(int *numbers, int index);
int			find_lowest_index(t_stack	*stack);
int			get_lowest_rank(t_stack *stack);

// small sort stack (up until 5)
void		try_smallsort(t_stack **stack_a, t_stack **stack_b);

void		try_bigsort(t_stack **stack_a, t_stack **stack_b);

// OPERATIONS

void		operation(char *op_name, t_stack **stack_a, t_stack **stack_b);
void		rotate_lowest_to_top(t_stack **stack_a);
void		rotate_element_to_top(t_stack **stack, int index, char stack_letter);

/*
Takes a stack and swaps the top 2 elements
Will not do anything if there is only one element
Returns TRUE and prints 'sa' or 'sb' if succesfull

stack = stack to swap
c     = stack name (only takes 'a' or 'b')
*/
t_bool		swap(t_stack **stack);
t_bool		swap_both(t_stack **stack_a, t_stack **stack_b);
t_bool		rotate(t_stack **stack);
t_bool		reverse_rotate(t_stack **stack);
t_bool		push(t_stack **pop_stack, t_stack **receive_stack);

#endif