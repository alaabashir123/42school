/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:11:36 by alaa              #+#    #+#             */
/*   Updated: 2023/09/20 13:00:22 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int					data;
	int					index;
	int					goal;
	int					opt;
	int					cheap;
	int					rarb;
	int					rrarrb;
	int					rarrb;
	int					rrarb;
	struct s_stack		*prev;
	struct s_stack		*next;
}	t_stack;

void	check_args_empty(int argc, char **argv);
void	check_args_char(int argc, char **argv);
void	check_args_quotes(int argc, char **argv);
void	check_args(int argc, char **argv);
void	check_duplicate(t_stack **stack_a);
void	create_stack(t_stack **stack_a, char **argv, int argc);
int		is_sorted(t_stack *stack_a);
void	sort_choice(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack_a);
void	sort_general(t_stack **stack_a, t_stack **stack_b);
void	ft_sort(t_stack **stack_a, t_stack **stack_b, char s);
void	set_index(t_stack **stack_a);
void	set_goal_b(t_stack **stack_a, t_stack *stack_b);
void	set_goal_a(t_stack *stack_a, t_stack **stack_b);
int		goal_a(t_stack *stack_a, int data_push);
int		goal_b(t_stack *stack_b, int data_push);
void	ft_set_cost_a(t_stack **stack_a, t_stack **stack_b);
int		cost_rrarrb_a(t_stack **stack_a, t_stack **stack_b, t_stack *tmp_b);
int		cost_rarb_a(t_stack *tmp_b);
int		cost_rarrb_a(t_stack **b, t_stack *tmp_b);
int		cost_rrarb_a(t_stack **a, t_stack *tmp_b);
void	ft_set_cost_b(t_stack **stack_a, t_stack **stack_b);
int		cost_rrarrb_b(t_stack **stack_a, t_stack **stack_b, t_stack *tmp_b);
int		cost_rarb_b(t_stack *tmp_b);
int		cost_rarrb_b(t_stack **b, t_stack *tmp_b);
int		cost_rrarb_b(t_stack **a, t_stack *tmp_b);
void	ft_optimum_rotation_a(t_stack **stack_a, t_stack **stack_b);
void	ft_optimum_rotation_b(t_stack **stack_a, t_stack **stack_b);
void	move(t_stack **stack_a, t_stack **stack_b, char s);
void	cont_rarb(t_stack **a, t_stack **b, t_stack *tmp_b, char s);
void	cont_rrarrb(t_stack **a, t_stack **b, t_stack *tmp_b, char s);
void	cont_rarrb(t_stack **a, t_stack **b, t_stack *tmp_b, char s);
void	cont_rrarb(t_stack **a, t_stack **b, t_stack *tmp_b, char s);
void	sa(t_stack **stack_a, int flag);
void	sb(t_stack **stack_b, int flag);
void	ss(t_stack **stack_a, t_stack **stack_b, int flag);
void	pa(t_stack **stack_a, t_stack **stack_b, int flag);
void	pb(t_stack **stack_a, t_stack **stack_b, int flag);
void	ra(t_stack **stack_a, int flag);
void	rb(t_stack **stack_b, int flag);
void	rr(t_stack **stack_a, t_stack **stack_b, int flag);
void	rra(t_stack **stack_a, int flag);
void	rrb(t_stack **stack_b, int flag);
void	rrr(t_stack **stack_a, t_stack **stack_b, int flag);
void	swap(t_stack **stack);
void	push(t_stack **src, t_stack **dst);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
long	ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
void	ft_free_array(char **ptr);
void	error_exit(int error, int flag, char **array);
void	error_free(int error, t_stack **stack_a);
void	ft_lstadd_back(t_stack **lst, int content);
int		ft_lstsize(t_stack *lst);
void	ft_lstclear(t_stack **lst);
void	print_list(t_stack *stack);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*min(t_stack *stack);
t_stack	*max(t_stack *stack);

#endif
