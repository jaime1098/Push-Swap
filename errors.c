/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:26:46 by joltra-r          #+#    #+#             */
/*   Updated: 2024/04/06 16:27:12 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_free(t_node **stack_a)
{
	t_node	*i;
	t_node	*next_node;

	i = *stack_a;
	while (i)
	{
		next_node = i->next;
		free (i);
		i = next_node;
	}
	*stack_a = NULL;
}

void	see_errors(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc <= 1)
		exit (0);
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			write (2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
	if (argc < 2 || argv[1][0] == '\0')
		exit (0);
}

void	print_error(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a != NULL)
		last_free(stack_a);
	if (stack_b && *stack_b != NULL)
		last_free(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

void	check_duplicated(t_node *stack_a)
{
	t_node	*i;
	t_node	*j;

	i = stack_a;
	while (i)
	{
		j = stack_a;
		while (j)
		{
			if (i != j && i->value == j->value)
				print_error(&stack_a, NULL);
			j = j->next;
		}
		i = i->next;
	}
}
