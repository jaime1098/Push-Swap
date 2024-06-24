/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:40:21 by joltra-r          #+#    #+#             */
/*   Updated: 2024/02/26 12:40:22 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_order(t_node **stack_a, t_node **stack_b)
{
	t_node	*aux_a;

	rotorpush(stack_a, stack_b);
	while (1)
	{
		aux_a = *stack_a;
		if (aux_a->ideal != 1)
			rrotate_a(stack_a);
		else
			break ;
	}
}

void	final_push(t_node **stack_a, t_node **stack_b, t_variable *variable)
{
	t_node	*aux_b;

	if (*stack_b == NULL)
		return ;
	variable->racount = 0;
	aux_b = *stack_b;
	while (aux_b->ideal != higher_stack_b(stack_b))
	{
		variable->racount++;
		aux_b = aux_b->next;
	}
	aux_b = *stack_b;
	variable->total = size_stack(stack_b);
	rotations(stack_b, aux_b, variable);
	final_order(stack_a, stack_b);
}

void	check_rotate_a(t_node **stack_a)
{
	t_node	*aux_a;
	t_node	*aux;
	int		max;
	int		i;

	aux_a = *stack_a;
	max = INT_MAX;
	while (aux_a)
	{
		if (aux_a->movt < max)
		{
			aux = aux_a;
			max = aux_a->movt;
		}
		aux_a = aux_a->next;
	}
	i = -1;
	while (++i < aux->mova)
	{
		if (aux->rrota == 1)
			rrotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
}

void	check_rotate_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*aux_a;
	int		i;

	aux_a = *stack_a;
	i = -1;
	while (++i < aux_a->movb)
	{
		if (aux_a->rrotb == 1)
			rrotate_b(stack_b);
		else
			rotate_b(stack_b);
	}
}

int	ft_order(t_node **stack_a, t_node **stack_b, t_variable *variable)
{
	int		three;

	three = size_stack(stack_a);
	if (three == 3)
	{
		orderthree(stack_a);
		return (three);
	}
	ft_count_a(stack_a, variable);
	ft_count_b(stack_a, stack_b, variable);
	ft_count_t(stack_a);
	if (*stack_a)
		check_rotate_a(stack_a);
	if (*stack_b)
		check_rotate_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	return (three);
}
