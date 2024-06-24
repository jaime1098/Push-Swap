/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3arg.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:36:01 by joltra-r          #+#    #+#             */
/*   Updated: 2024/04/14 15:36:02 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	orderthree(t_node **stack_a)
{
	t_node	*aux_a;
	int		size;

	aux_a = *stack_a;
	size = size_stack(stack_a);
	if (size != 3)
		return ;
	aux_a = *stack_a;
	if (aux_a->ideal > aux_a->next->ideal)
		swap_a(stack_a);
	aux_a = *stack_a;
	if (aux_a->ideal > aux_a->next->next->ideal)
		rrotate_a(stack_a);
	aux_a = *stack_a;
	if (aux_a->next->ideal > aux_a->next->next->ideal)
	{
		rrotate_a(stack_a);
		swap_a(stack_a);
	}
}
