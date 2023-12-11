/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:32:03 by abashir           #+#    #+#             */
/*   Updated: 2023/09/18 14:53:41 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack **stack_a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

void	set_goal_a(t_stack *stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;

	tmp_b = *stack_b;
	while (tmp_b)
	{
		tmp_b->goal = goal_a(stack_a, tmp_b->data);
		tmp_b = tmp_b->next;
	}
}

void	set_goal_b(t_stack **stack_a, t_stack *stack_b)
{
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		tmp_a->goal = goal_b(stack_b, tmp_a->data);
		tmp_a = tmp_a->next;
	}
}

int	goal_b(t_stack *stack_b, int data_push)
{
	int	i;
	int	biggest_smaller;

	i = 1;
	set_index(&stack_b);
	if (data_push > stack_b->data && data_push < ft_lstlast(stack_b)->data)
		i = 0;
	else if (data_push > max(stack_b)->data || data_push < min(stack_b)->data)
		i = max(stack_b)->index;
	else
	{
		biggest_smaller = INT_MIN;
		while (stack_b != NULL)
		{
			if (stack_b->data < data_push && stack_b->data > biggest_smaller)
			{
				biggest_smaller = stack_b->data;
				i = stack_b->index;
			}
			stack_b = stack_b->next;
		}
	}
	return (i);
}

int	goal_a(t_stack *stack_a, int data_push)
{
	int		i;
	int		smallest_bigger;

	i = 1;
	set_index(&stack_a);
	if (data_push < stack_a->data && data_push > ft_lstlast(stack_a)->data)
		i = 0;
	else if (data_push > max(stack_a)->data || data_push < min(stack_a)->data)
		i = min(stack_a)->index;
	else
	{
		smallest_bigger = INT_MAX;
		while (stack_a != NULL)
		{
			if (stack_a->data > data_push && stack_a->data < smallest_bigger)
			{
				smallest_bigger = stack_a->data;
				i = stack_a->index;
			}
			stack_a = stack_a->next;
		}
	}
	return (i);
}
