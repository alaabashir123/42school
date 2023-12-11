/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:20:45 by abashir           #+#    #+#             */
/*   Updated: 2023/09/17 17:30:12 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, int flag)
{
	swap(stack_a);
	if (flag == 1)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **stack_b, int flag)
{
	swap(stack_b);
	if (flag == 1)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int flag)
{
	swap(stack_a);
	swap(stack_b);
	if (flag == 1)
		ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack **stack_a, t_stack **stack_b, int flag)
{
	push(stack_b, stack_a);
	if (flag == 1)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int flag)
{
	push(stack_a, stack_b);
	if (flag == 1)
		ft_putstr_fd("pb\n", 1);
}
