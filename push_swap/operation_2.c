/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:00:30 by abashir           #+#    #+#             */
/*   Updated: 2023/09/17 17:30:57 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a, int flag)
{
	rotate(stack_a);
	if (flag == 1)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **stack_b, int flag)
{
	rotate(stack_b);
	if (flag == 1)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	rotate(stack_a);
	rotate(stack_b);
	if (flag == 1)
		ft_putstr_fd("rr\n", 1);
}

void	rra(t_stack **stack_a, int flag)
{
	reverse_rotate(stack_a);
	if (flag == 1)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **stack_b, int flag)
{
	reverse_rotate(stack_b);
	if (flag == 1)
		ft_putstr_fd("rrb\n", 1);
}
