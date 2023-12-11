/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:06:31 by abashir           #+#    #+#             */
/*   Updated: 2023/09/19 17:48:08 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->data == tmp2->data)
				error_free(1, stack_a);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	fill_stack(t_stack **stack_a, char **str)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		num = ft_atoi(str[i]);
		ft_lstadd_back(stack_a, num);
		if (num > 2147483647 || num < -2147483648)
		{
			ft_free_array(str);
			error_free(1, stack_a);
		}
		i++;
	}
	ft_free_array(str);
	check_duplicate(stack_a);
}

void	create_stack(t_stack **stack_a, char **argv, int argc)
{
	char	*str;
	char	*tmp;
	char	**res;
	int		i;

	i = 2;
	str = ft_strjoin(argv[1], " ");
	if (!str)
		error_exit(1, 0, 0);
	while (i < argc)
	{
		tmp = ft_strjoin(str, argv[i++]);
		free(str);
		if (!tmp)
			error_exit(1, 0, 0);
		str = ft_strjoin(tmp, " ");
		free(tmp);
		if (!str)
			error_exit(1, 0, 0);
	}
	res = ft_split(str, ' ');
	free(str);
	if (!res)
		error_exit(1, 1, res);
	fill_stack(stack_a, res);
}
