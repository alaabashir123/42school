/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:50:23 by alaa              #+#    #+#             */
/*   Updated: 2023/09/15 17:00:29 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_rrarrb_a(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	int	i;

	i = 0;
	if (node->goal)
		i = ft_lstsize(*stack_b) - node->goal;
	if ((i < (ft_lstsize(*stack_a) - node->index)) && node->index)
		i = ft_lstsize(*stack_a) - node->index;
	return (i);
}

int	cost_rarb_a(t_stack *node)
{
	int	i;

	i = node->goal;
	if (i < node->index)
		i = node->index;
	return (i);
}

int	cost_rrarb_a(t_stack **a, t_stack *node)
{
	int	i;

	i = 0;
	if (node->index)
		i = ft_lstsize(*a) - node->index;
	i = node->goal + i;
	return (i);
}

int	cost_rarrb_a(t_stack **b, t_stack *node)
{
	int	i;

	i = 0;
	if (node->goal)
		i = ft_lstsize(*b) - node->goal;
	i = node->index + i;
	return (i);
}

void	ft_set_cost_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	i = cost_rarb_a(tmp_a);
	while (tmp_a)
	{
		tmp_a->rarb = cost_rarb_a(tmp_a);
		if (tmp_a->rarb < i)
			i = tmp_a->rarb;
		tmp_a->rrarrb = cost_rrarrb_a(stack_a, stack_b, tmp_a);
		if (tmp_a->rrarrb < i)
			i = tmp_a->rrarrb;
		tmp_a->rarrb = cost_rarrb_a(stack_b, tmp_a);
		if (tmp_a->rarrb < i)
			i = tmp_a->rarrb;
		tmp_a->rrarb = cost_rrarb_a(stack_a, tmp_a);
		if (tmp_a->rrarb < i)
			i = tmp_a->rrarb;
		tmp_a->cheap = i;
		tmp_a = tmp_a->next;
	}
}
