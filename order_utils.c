/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:52:45 by joltra-r          #+#    #+#             */
/*   Updated: 2024/04/13 16:52:46 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotations(t_node **stack_b, t_node *aux_b, t_variable *variable)
{
	if (variable->total - variable->racount > variable->total / 2)
	{
		while (aux_b->ideal != higher_stack_b(stack_b))
		{
			rotate_b(stack_b);
			aux_b = (*stack_b);
		}
	}
	else
	{
		while (aux_b->ideal != higher_stack_b(stack_b))
		{
			rrotate_b(stack_b);
			aux_b = (*stack_b);
		}
	}
}

void	rotorpush(t_node **stack_a, t_node **stack_b)
{
	t_node	*aux_a;
	t_node	*aux_b;
	int		total;

	aux_b = *stack_b;
	total = size_stack(stack_a);
	while (aux_b)
	{
		aux_a = *stack_a;
		while (aux_a->next)
			aux_a = aux_a->next;
		if (aux_a->ideal > aux_b->ideal && total > 0)
		{
			rrotate_a(stack_a);
			total--;
		}
		else
		{
			push_a(stack_a, stack_b);
			aux_b = *stack_b;
		}
	}
}
