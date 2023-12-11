/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:11:36 by alaa              #+#    #+#             */
/*   Updated: 2023/09/18 12:42:02 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../push_swap.h"
# include "../get_next_line/get_next_line.h"

void	read_inst(t_list **inst, t_stack **stack_a);
void	check_inst(t_list **inst, t_stack **stack_a);
void	implement_inst(t_stack **stack_a, t_stack **stack_b, t_list *inst);
void	implement_each(t_stack **stack_a, t_stack **stack_b, char *inst);

#endif
