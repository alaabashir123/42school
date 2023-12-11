/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_inst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:35:47 by abashir           #+#    #+#             */
/*   Updated: 2023/09/17 17:37:31 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	implement_each(t_stack **stack_a, t_stack **stack_b, char *inst)
{
	if (ft_strncmp(inst, "sa\n", ft_strlen(inst)) == 0)
		sa(stack_a, 0);
	else if (ft_strncmp(inst, "sb\n", ft_strlen(inst)) == 0)
		sb(stack_b, 0);
	else if (ft_strncmp(inst, "ss\n", ft_strlen(inst)) == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strncmp(inst, "pa\n", ft_strlen(inst)) == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strncmp(inst, "pb\n", ft_strlen(inst)) == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strncmp(inst, "ra\n", ft_strlen(inst)) == 0)
		ra(stack_a, 0);
	else if (ft_strncmp(inst, "rb\n", ft_strlen(inst)) == 0)
		rb(stack_b, 0);
	else if (ft_strncmp(inst, "rr\n", ft_strlen(inst)) == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strncmp(inst, "rra\n", ft_strlen(inst)) == 0)
		rra(stack_a, 0);
	else if (ft_strncmp(inst, "rrb\n", ft_strlen(inst)) == 0)
		rrb(stack_b, 0);
	else if (ft_strncmp(inst, "rrr\n", ft_strlen(inst)) == 0)
		rrr(stack_a, stack_b, 0);
}

void	implement_inst(t_stack **stack_a, t_stack **stack_b, t_list *inst)
{
	while (inst)
	{
		implement_each(stack_a, stack_b, inst->content);
		inst = inst->next;
	}
}
