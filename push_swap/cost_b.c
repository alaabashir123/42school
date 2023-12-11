/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:00:58 by alaa              #+#    #+#             */
/*   Updated: 2023/09/15 17:02:12 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_rrarrb_b(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	int		i;

	i = 0;
	if (node->goal)
		i = ft_lstsize(*stack_a) - node->goal;
	if ((i < (ft_lstsize(*stack_b) - node->index)) && node->index)
		i = ft_lstsize(*stack_b) - node->index;
	return (i);
}

int	cost_rarb_b(t_stack *node)
{
	int	i;

	i = 0;
	i = node->goal;
	if (i < node->index)
		i = node->index;
	return (i);
}

int	cost_rarrb_b(t_stack **b, t_stack *node)
{
	int	i;

	i = 0;
	if (node->index)
		i = ft_lstsize(*b) - node->index;
	i = node->goal + i;
	return (i);
}

int	cost_rrarb_b(t_stack **a, t_stack *node)
{
	int	i;

	i = 0;
	if (node->goal)
		i = ft_lstsize(*a) - node->goal;
	i = node->index + i;
	return (i);
}

void	ft_set_cost_b(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp_b;

	tmp_b = *stack_b;
	i = cost_rarb_b(tmp_b);
	while (tmp_b)
	{
		tmp_b->rarb = cost_rarb_b(tmp_b);
		if (tmp_b->rarb < i)
			i = tmp_b->rarb;
		tmp_b->rrarrb = cost_rrarrb_b(stack_a, stack_b, tmp_b);
		if (tmp_b->rrarrb < i)
			i = tmp_b->rrarrb;
		tmp_b->rarrb = cost_rarrb_b(stack_b, tmp_b);
		if (tmp_b->rarrb < i)
			i = tmp_b->rarrb;
		tmp_b->rrarb = cost_rrarb_b(stack_a, tmp_b);
		if (tmp_b->rrarb < i)
			i = tmp_b->rrarb;
		tmp_b->cheap = i;
		tmp_b = tmp_b->next;
	}
}
