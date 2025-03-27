/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 05:01:10 by lomont            #+#    #+#             */
/*   Updated: 2025/03/27 21:48:22 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <limits.h>
# include "../LIB_C/LIB_C.h"

// #define INT_MAX 2147483647
// #define INT_MIN -2147483648


typedef struct	s_node
{
	int 			nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;


int		ft_str_only_digit(char *str);
bool	check_numbers(char *argv);
bool	check_duplicate(t_node *stack_a, int n);
void	swap_a(t_node **stack_a, bool print);
void	swap_b(t_node **stack_b, bool print);
void	swap_a_and_b(t_node **stack_a, t_node **stack_b, bool print);
void	push_a(t_node *stack_a, t_node *stack_b, bool print);
void	push_b(t_node **stack_a, t_node **stack_b, bool print);
void	rotate_a(t_node **stack_a, bool print);
void	rotate_b(t_node **stack_b, bool print);
void	rotate_a_and_b(t_node **stack_a, t_node **stack_b, bool print);
void	reverse_rotate_a(t_node **stack_a, bool print);
void	reverse_rotate_b(t_node **stack_b, bool print);
void	reverse_rotate_a_and_b(t_node **stack_a, t_node **stack_b, bool print);

void	sort_three(t_node **stack_a);
bool	stack_sorted(t_node *stack);
void	sort_stacks(t_node **stack_a, t_node **stack_b);
void	ft_exit(char *str);
void	free_stack(t_node *stack);
t_node	*find_min(t_node *stack);
void	prep_for_push(t_node **stack, t_node *top_node, char stack_name);
void	rotate_both(t_node **stack_a, t_node **stack_b, t_node *cheapest_node);
t_node	*find_min(t_node *stack);
t_node	*find_max(t_node *stack);
void	init_stack_a(t_node **stack_a, char **argv);
void	append_node(t_node **stack, int n);
void	current_index(t_node *stack);
void	set_target_a(t_node *stack_a, t_node *stack_b);
void	calcul_cost_a(t_node *stack_a, t_node *stack_b);
void	set_cheapest(t_node *stack);
void	init_nodes_a(t_node *stack_a, t_node *stack_b);
void	init_nodes_b(t_node *stack_a, t_node *stack_b);
void	set_target_b(t_node *stack_a, t_node *stack_b);
void	move_a_to_b(t_node **stack_a, t_node **stack_b);
void	move_b_to_a(t_node **stack_a, t_node **stack_b);
void	min_on_top(t_node **stack_a);
int		stack_len(t_node *stack);
t_node	*find_last(t_node **stack);
t_node	*get_cheapest(t_node *stack);
void	free_errors(t_node *stack_a);


#endif
