/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: merel <merel@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/20 12:11:19 by merel         #+#    #+#                 */
/*   Updated: 2022/07/28 13:40:50 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *stack, char *stack_name)
{
	ft_printf("\nPrinting: %s\n", stack_name);
	ft_printf("------------\n");
	while (stack)
	{
		ft_printf("number = %i\n", stack->number);
		stack = stack->next;
	}
	ft_printf("------------\n");
}

int	ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

t_bool	is_int(char *str)
{
	while (ft_isdigit(*str) || *str == '-')
		str++;
	if (*str)
		return (FALSE);
	return (TRUE);
}

t_bool	is_double(int *numbers, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (numbers[i] == numbers[index])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	error_exit(void)
{
	ft_printf("Error\n");
	exit (1);
}
