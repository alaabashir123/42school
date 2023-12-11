/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:06:55 by alaa              #+#    #+#             */
/*   Updated: 2023/09/19 18:04:52 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*inst;

	stack_a = NULL;
	stack_b = NULL;
	inst = NULL;
	check_args(argc, argv);
	create_stack(&stack_a, argv, argc);
	if (!is_sorted(stack_a))
	{
		read_inst(&inst, &stack_a);
		implement_inst(&stack_a, &stack_b, inst);
	}
	if (is_sorted(stack_a) && !stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_lstclear_gnl(&inst);
	ft_lstclear(&stack_a);
}
