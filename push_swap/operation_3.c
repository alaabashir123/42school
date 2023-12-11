/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:01:17 by abashir           #+#    #+#             */
/*   Updated: 2023/09/19 16:20:43 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (flag == 1)
		ft_putstr_fd("rrr\n", 1);
}

void	swap(t_stack **stack)
{
	int		tmp;
	t_stack	*stack_a;

	if (!(*stack) || !(*stack)->next)
		return ;
	stack_a = *stack;
	tmp = stack_a->data;
	stack_a->data = stack_a->next->data;
	stack_a->next->data = tmp;
}

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!(*stack_a))
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	tmp->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = tmp;
	*stack_b = tmp;
	(*stack_b)->prev = NULL;
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	tmp2 = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	tmp->next = NULL;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	tmp2 = *stack;
	while (tmp->next)
		tmp = tmp->next;
	(*stack) = tmp;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = tmp2;
	tmp2->prev = tmp;
}
