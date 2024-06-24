/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:29:47 by joltra-r          #+#    #+#             */
/*   Updated: 2024/03/15 15:29:49 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_movb_aux(t_node **stack_b, t_node *aux_a, \
t_variable *variable, int min)
{
	t_node	*aux_b;

	aux_b = *stack_b;
	while (aux_b && aux_b->ideal != min)
	{
		variable->movb++;
		aux_b = aux_b->next;
	}
	if (variable->movb > variable->totalb / 2)
	{
		aux_a->rrotb = 1;
		variable->movb = variable->totalb - variable->movb;
	}
	aux_a->movb = variable->movb;
}

void	get_movb(t_node *aux_a, t_node **stack_b, t_variable *variable)
{
	t_node	*aux_b;
	int		min;

	min = INT_MIN;
	variable->movb = 0;
	aux_b = *stack_b;
	aux_a->rrotb = 0;
	while (aux_b)
	{
		if (aux_a->ideal > aux_b->ideal && aux_b->ideal > min)
			min = aux_b->ideal;
		aux_b = aux_b->next;
	}
	aux_b = *stack_b;
	if (min == INT_MIN)
	{
		while (aux_b)
		{
			if (min < aux_b->ideal)
				min = aux_b->ideal;
			aux_b = aux_b->next;
		}
	}
	get_movb_aux(stack_b, aux_a, variable, min);
}

void	ft_count_t(t_node **stack_a)
{
	t_node	*aux_a;

	aux_a = *stack_a;
	while (aux_a)
	{
		aux_a->movt = aux_a->mova + aux_a->movb;
		aux_a = aux_a->next;
	}
}

void	ft_count_b(t_node **stack_a, t_node **stack_b, t_variable *variable)
{
	t_node	*aux_a;
	t_node	*aux_b;

	aux_a = *stack_a;
	aux_b = *stack_b;
	variable->totalb = 0;
	if (!aux_a || !aux_b)
		return ;
	while (aux_b)
	{
		variable->totalb++;
		aux_b = aux_b->next;
	}
	aux_b = *stack_b;
	while (aux_a)
	{
		get_movb(aux_a, stack_b, variable);
		aux_a = aux_a->next;
	}
}

void	ft_count_a(t_node **stack_a, t_variable *variable)
{
	t_node	*aux_a;

	aux_a = *stack_a;
	variable->totala = 0;
	if (!aux_a)
		return ;
	while (aux_a)
	{
		aux_a->mova = variable->totala++;
		aux_a->rrota = 0;
		aux_a = aux_a->next;
	}
	aux_a = *stack_a;
	variable->mova = variable->totala / 2;
	while (aux_a->mova != variable->mova)
		aux_a = aux_a->next;
	aux_a = aux_a->next;
	if (variable->totala % 2 == 0)
		variable->mova--;
	while (aux_a)
	{
		aux_a->mova = variable->mova--;
		aux_a->rrota = 1;
		aux_a = aux_a->next;
	}
}
