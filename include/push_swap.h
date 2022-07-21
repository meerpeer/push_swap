/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Push_Swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 13:10:18 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/07/21 11:00:25 by mevan-de      ########   odam.nl         */
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

// list functions
t_numbers	*new_element(int number);
void		list_add_to_back(t_numbers **lst, t_numbers *new_number);

// helper functions
t_bool		is_int(char *str);
t_bool		stack_is_ordered(t_numbers *stack);
t_bool		is_double(int *numbers, int index);

// small sort stack (up until 5)
#endif