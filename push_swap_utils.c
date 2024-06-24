/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:17:44 by joltra-r          #+#    #+#             */
/*   Updated: 2024/02/17 17:17:45 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order_a(t_node **stack_a)
{
	t_node	*aux;

	aux = *stack_a;
	while (aux->next && aux->ideal < aux->next->ideal)
		aux = aux->next;
	if (!aux->next)
		return (0);
	else
		return (1);
}

int	size_stack(t_node **stack_a)
{
	t_node	*aux_a;
	int		size;

	aux_a = *stack_a;
	size = 0;
	while (aux_a != NULL)
	{
		aux_a = aux_a->next;
		size++;
	}
	return (size);
}

int	higher_stack_b(t_node **stack_b)
{
	t_node	*aux_b;
	int		higher;

	aux_b = *stack_b;
	higher = aux_b->ideal;
	while (aux_b != NULL)
	{
		if (aux_b->ideal > higher)
			higher = aux_b->ideal;
		aux_b = aux_b->next;
	}
	return (higher);
}

void	istwo(t_node **stack_a, int three)
{
	if (three == 2)
	{
		if (check_order_a(stack_a) == 0)
		{
			last_free(stack_a);
			exit (0);
		}
		swap_a(stack_a);
		last_free(stack_a);
		exit(0);
	}
}

/*
void	print_stacks(t_node *stack_a, t_node *stack_b)
{
	if (!stack_b)
		stack_b = NULL;
	if (!stack_a)
		stack_a = NULL;
	printf("Stack A:	Stack B\n");
	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a)
		{
			printf("%d", stack_a->value);
			stack_a = stack_a->next;
		}
		printf("		");
		if (stack_b != NULL)
		{
			printf("%d", stack_b->value);
			stack_b = stack_b->next;
		}
		printf("\n");
	}
	printf("\n");
}
*/
