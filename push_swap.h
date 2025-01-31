/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 05:01:10 by lomont            #+#    #+#             */
/*   Updated: 2025/01/31 07:17:19 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
// #define INT_MAX 2147483647
// #define INT_MIN -2147483648

int ft_str_only_digit(char *str);
bool check_numbers(int argc, char **argv);
bool check_duplicate(char **argv);

typedef struct	s_node
{
	int 			nbr;
	struct s_node	*next;
}				t_node;

typedef struct	List
{
	t_node	*first;
	int		compteur;
}				list;

void note_addCount(list *liste);
void note_reduceCount(list *liste);
void free_list(list *liste);
void print_list(list *liste, t_node *tmp);
void suppresion(list *liste);
void suppresion_middle(list *liste, t_node *deleteElement);
void insertion_middle(list *liste, t_node *node, int nvNombre);
void insertion(list *liste, int nvNombre);
list	*initalisation(int number);
list *fill_stack_a(int argc, char **argv);
list *fill_stack_b(void);
void swap_a(list *stack_a);
void swap_b(list *stack_b);
void swap_a_and_b(list *stack_a, list *stack_b);
list *push_a(list *stack_a, list *stack_b);
list *push_b(list *stack_a, list *stack_b);
list *rotate_a(list *stack_a);
list *rotate_b(list *stack_b);
void rotate_a_and_b(list *stack_a,list *stack_b);
#endif