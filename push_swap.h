/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:59:14 by joltra-r          #+#    #+#             */
/*   Updated: 2024/02/11 14:59:16 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

void	see_errors(int argc, char **argv);
void	get_ideal(t_node **stack_a, t_variable *variable);
int		ft_order(t_node **stack_a, t_node **stack_b, t_variable *variable);
void	count_movs(t_node **stack_a, t_variable *variable, int search);
int		check_order_a(t_node **stack_a);
int		size_stack(t_node **stack_a);
void	rotations(t_node **stack_b, t_node *aux_b, t_variable *variable);
void	rotorpush(t_node **stack_a, t_node **stack_b);
int		higher_stack_b(t_node **stack_b);
void	istwo(t_node **stack_a, int three);
void	orderthree(t_node **stack_a);
void	ft_count_a(t_node **stack_a, t_variable *variable);
void	ft_count_b(t_node **stack_a, t_node **stack_b, t_variable *variable);
void	ft_count_t(t_node **stack_a);
void	final_push(t_node **stack_a, t_node **stack_b, t_variable *variable);
void	print_error(t_node **stack_a, t_node **stack_b);
void	check_errors(t_node **stack_a, t_node **stack_b, t_variable *variable);
void	check_duplicated(t_node *stack_a);
void	free_split(t_variable *variable);
void	last_free(t_node **stack_a);
void	print_stack_a(t_node *stack_a);
void	print_stacks(t_node *stack_a, t_node *stack_b);
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);
void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	swap_ss(t_node **stack_a, t_node **stack_b);
void	rotate_a(t_node **stack_a);
void	rotate_b(t_node **stack_b);
void	rotate_rr(t_node **stack_a, t_node **stack_b);
void	rrotate_a(t_node **stack_a);
void	rrotate_b(t_node **stack_b);
void	rrotate_rr(t_node **stack_a, t_node **stack_b);

#endif