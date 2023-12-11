/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_choice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:11:59 by abashir           #+#    #+#             */
/*   Updated: 2023/09/18 13:50:29 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	if (max(*stack_a)->data == (*stack_a)->data)
	{
		ra(stack_a, 1);
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a, 1);
	}
	else if ((*stack_a)->next->data == max(*stack_a)->data)
	{
		rra(stack_a, 1);
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a, 1);
	}
	else
		sa(stack_a, 1);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b, char s)
{
	if (s == 'a')
	{
		while (ft_lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
		{
			ft_optimum_rotation_a(stack_a, stack_b);
			move(stack_a, stack_b, s);
		}
	}
	else
	{
		while (*stack_b)
		{
			ft_optimum_rotation_b(stack_a, stack_b);
			move(stack_a, stack_b, s);
		}
	}
}

void	final_rotation(t_stack **stack_a)
{
	if (min(*stack_a)->index < ft_lstsize(*stack_a) / 2)
		while ((*stack_a)->data != min(*stack_a)->data)
			ra(stack_a, 1);
	else
		while ((*stack_a)->data != min(*stack_a)->data)
			rra(stack_a, 1);
}

void	sort_general(t_stack **stack_a, t_stack **stack_b)
{
	int		i;

	i = 0;
	while (i++ < 2 && !is_sorted(*stack_a))
		pb(stack_a, stack_b, 1);
	if (ft_lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
		ft_sort(stack_a, stack_b, 'a');
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	ft_sort(stack_a, stack_b, 'b');
	final_rotation(stack_a);
}

void	sort_choice(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		error_free(0, stack_a);
	else
	{
		if (ft_lstsize(*stack_a) == 2)
			sa(stack_a, 1);
		else if (ft_lstsize(*stack_a) == 3)
			sort_three(stack_a);
		else
			sort_general(stack_a, stack_b);
	}
}
