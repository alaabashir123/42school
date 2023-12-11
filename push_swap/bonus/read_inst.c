/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:31:53 by abashir           #+#    #+#             */
/*   Updated: 2023/09/18 12:41:41 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_inst(t_list **inst, t_stack **stack_a)
{
	t_list	*tmp;

	tmp = *inst;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, "sa\n", ft_strlen(tmp->content)) != 0 \
		&& ft_strncmp(tmp->content, "sb\n", ft_strlen(tmp->content)) != 0 \
		&& ft_strncmp(tmp->content, "ss\n", ft_strlen(tmp->content)) != 0 \
		&& ft_strncmp(tmp->content, "pa\n", ft_strlen(tmp->content)) != 0 \
		&& ft_strncmp(tmp->content, "pb\n", ft_strlen(tmp->content)) != 0 \
		&& ft_strncmp(tmp->content, "ra\n", ft_strlen(tmp->content)) != 0 \
		&& ft_strncmp(tmp->content, "rb\n", ft_strlen(tmp->content)) != 0 \
		&& ft_strncmp(tmp->content, "rr\n", ft_strlen(tmp->content)) != 0 \
		&& ft_strncmp(tmp->content, "rra\n", ft_strlen(tmp->content)) != 0 \
		&& ft_strncmp(tmp->content, "rrb\n", ft_strlen(tmp->content)) != 0 \
		&& ft_strncmp(tmp->content, "rrr\n", ft_strlen(tmp->content)))
		{
			ft_lstclear_gnl(inst);
			error_free(1, stack_a);
		}
		tmp = tmp->next;
	}
}

void	read_inst(t_list **inst, t_stack **stack_a)
{
	char	*line;

	line = get_next_line(0);
	if (!line)
		error_free(0, stack_a);
	else
	{
		while (line)
		{
			if (line[0] == '\n')
				break ;
			ft_lstadd_back_gnl(inst, ft_strdup(line));
			free(line);
			line = get_next_line(0);
		}
		free(line);
		check_inst(inst, stack_a);
	}
}
