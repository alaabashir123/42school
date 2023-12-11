/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:53:54 by alaa              #+#    #+#             */
/*   Updated: 2023/09/15 17:06:32 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_optimum_a(t_stack **stack_a)
{
	int		cheapest;
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	cheapest = INT_MAX;
	while (tmp_a)
	{
		if (cheapest > tmp_a->cheap)
			cheapest = tmp_a->cheap;
		tmp_a = tmp_a->next;
	}
	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->cheap == cheapest)
			tmp_a->opt = 1;
		else
			tmp_a->opt = 0;
		tmp_a = tmp_a->next;
	}
}

void	ft_optimum_rotation_a(t_stack **stack_a, t_stack **stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	set_goal_b(stack_a, *stack_b);
	ft_set_cost_a(stack_a, stack_b);
	ft_set_optimum_a(stack_a);
}

void	ft_set_optimum_b(t_stack **stack_b)
{
	int		cheapest;
	t_stack	*tmp_b;

	tmp_b = *stack_b;
	cheapest = INT_MAX;
	while (tmp_b)
	{
		if (cheapest > tmp_b->cheap)
			cheapest = tmp_b->cheap;
		tmp_b = tmp_b->next;
	}
	tmp_b = *stack_b;
	while (tmp_b)
	{
		if (tmp_b->cheap == cheapest)
			tmp_b->opt = 1;
		else
			tmp_b->opt = 0;
		tmp_b = tmp_b->next;
	}
}

void	ft_optimum_rotation_b(t_stack **stack_a, t_stack **stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	set_goal_a(*stack_a, stack_b);
	ft_set_cost_b(stack_a, stack_b);
	ft_set_optimum_b(stack_b);
}
