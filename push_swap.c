/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:01:16 by joltra-r          #+#    #+#             */
/*   Updated: 2024/02/11 15:01:18 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(t_variable *variable)
{
	int	i;

	i = -1;
	while (variable->splited[++i])
		free(variable->splited[i]);
	free(variable->splited);
}

void	create_list(t_node **stack_a, t_variable variable)
{
	t_node	*node;
	t_node	*staux;

	node = (t_node *) ft_calloc (sizeof(t_node), 1);
	if (!node)
		return ;
	node->value = variable.num;
	node->next = NULL;
	staux = *stack_a;
	if (!*stack_a)
		*stack_a = node;
	else
	{
		while (staux->next)
			staux = staux->next;
		staux->next = node;
	}
}

void	read_args(char **argv, t_variable *variable, t_node **stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		variable->splited = ft_split(argv[i], ' ');
		while (variable->splited[++j])
		{
			variable->num = ft_atoi(variable, stack_a, variable->splited[j]);
			if (variable->num < INT_MIN && variable->num > INT_MAX)
				print_error(NULL, NULL);
			create_list(stack_a, *variable);
		}
		free_split(variable);
	}
}

void	get_ideal(t_node **stack_a, t_variable *variable)
{
	t_node	*list;
	t_node	*listideal;

	list = *stack_a;
	listideal = NULL;
	while (list)
	{
		if (variable->min >= list->value && list->value > variable->max)
		{
			variable->min = list->value;
			listideal = list;
			list = list->next;
		}
		else
			list = list->next;
	}
	if (listideal)
	{
		listideal->ideal = variable->ideal++;
		variable->max = listideal->value;
		variable->min = INT_MAX;
		list = *stack_a;
		get_ideal(stack_a, variable);
	}
}

int	main(int argc, char **argv)
{
	t_node		*stack_a;
	t_node		*stack_b;
	t_variable	variable;
	int			three;

	stack_a = NULL;
	stack_b = NULL;
	see_errors(argc, argv);
	read_args(argv, &variable, &stack_a);
	check_duplicated(stack_a);
	variable.min = INT_MAX;
	variable.max = INT_MIN;
	variable.ideal = 1;
	get_ideal(&stack_a, &variable);
	check_int_min(&stack_a);
	if (check_order_a(&stack_a) == 0)
		return (last_free(&stack_a), 0);
	three = size_stack(&stack_a);
	istwo(&stack_a, three);
	while (check_order_a(&stack_a) != 0 || three != 3)
		three = ft_order(&stack_a, &stack_b, &variable);
	final_push(&stack_a, &stack_b, &variable);
	last_free(&stack_a);
	return (0);
}
