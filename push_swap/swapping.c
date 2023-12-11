/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:36:18 by abashir           #+#    #+#             */
/*   Updated: 2023/09/17 17:42:50 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cont_rarb(t_stack **a, t_stack **b, t_stack *tmp_b, char s)
{
	if (s == 'a')
	{
		while ((*a)->data != tmp_b->data && goal_b(*b, tmp_b->data) > 0)
			rr(a, b, 1);
		while ((*a)->data != tmp_b->data)
			ra(a, 1);
		while (goal_b(*b, tmp_b->data) > 0)
			rb(b, 1);
		pb(a, b, 1);
	}
	else
	{
		while (goal_a(*a, tmp_b->data) > 0 && (*b)->data != tmp_b->data)
			rr(a, b, 1);
		while (goal_a(*a, tmp_b->data) > 0)
			ra(a, 1);
		while ((*b)->data != tmp_b->data)
			rb(b, 1);
		pa(a, b, 1);
	}
}

void	cont_rrarrb(t_stack **a, t_stack **b, t_stack *tmp_b, char s)
{
	if (s == 'a')
	{
		while ((*a)->data != tmp_b->data && goal_b(*b, tmp_b->data) > 0)
			rrr(a, b, 1);
		while ((*a)->data != tmp_b->data)
			rra(a, 1);
		while (goal_b(*b, tmp_b->data) > 0)
			rrb(b, 1);
		pb(a, b, 1);
	}
	else
	{
		while (goal_a(*a, tmp_b->data) > 0 && (*b)->data != tmp_b->data)
			rrr(a, b, 1);
		while (goal_a(*a, tmp_b->data) > 0)
			rra(a, 1);
		while ((*b)->data != tmp_b->data)
			rrb(b, 1);
		pa(a, b, 1);
	}
}

void	cont_rrarb(t_stack **a, t_stack **b, t_stack *tmp_b, char s)
{
	if (s == 'a')
	{
		while ((*a)->data != tmp_b->data)
			rra(a, 1);
		while (goal_b(*b, tmp_b->data) > 0)
			rb(b, 1);
		pb(a, b, 1);
	}
	else
	{
		while (goal_a(*a, tmp_b->data) > 0)
			rra(a, 1);
		while ((*b)->data != tmp_b->data)
			rb(b, 1);
		pa(a, b, 1);
	}
}

void	cont_rarrb(t_stack **a, t_stack **b, t_stack *tmp_b, char s)
{
	if (s == 'a')
	{
		while ((*a)->data != tmp_b->data)
			ra(a, 1);
		while (goal_b(*b, tmp_b->data) > 0)
			rrb(b, 1);
		pb(a, b, 1);
	}
	else
	{
		while (goal_a(*a, tmp_b->data) > 0)
			ra(a, 1);
		while ((*b)->data != tmp_b->data)
			rrb(b, 1);
		pa(a, b, 1);
	}
}

void	move(t_stack **stack_a, t_stack **stack_b, char s)
{
	t_stack	*tmp;

	if (s == 'a')
		tmp = *stack_a;
	else
		tmp = *stack_b;
	while (tmp)
	{
		if (tmp->opt == 1)
		{
			if (tmp->cheap == tmp->rarb)
				cont_rarb(stack_a, stack_b, tmp, s);
			else if (tmp->cheap == tmp->rarrb)
				cont_rarrb(stack_a, stack_b, tmp, s);
			else if (tmp->cheap == tmp->rrarb)
				cont_rrarb(stack_a, stack_b, tmp, s);
			else if (tmp->cheap == tmp->rrarrb)
				cont_rrarrb(stack_a, stack_b, tmp, s);
			break ;
		}
		tmp = tmp->next;
	}
}
