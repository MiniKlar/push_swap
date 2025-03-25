/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 03:37:21 by lomont            #+#    #+#             */
/*   Updated: 2025/03/25 07:00:29 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

bool check_numbers(char *argv)
{
	if (!argv)
	{
		ft_exit("ARGV VIDE\n");
		exit(EXIT_FAILURE);
	}
	if ((ft_atol(argv) == 0 && !(ft_strncmp(argv, "0", 1) == 0)) || ((ft_atol(argv) < INT_MIN) || (ft_atol(argv) > INT_MAX)))
		return (false);
	else if (!ft_str_only_digit(argv))
		return (false);
	else
		return (true);
}

bool check_duplicate(t_node *stack_a, int n)
{
	if (!stack_a)
		return (true);
	while(stack_a)
	{
		if (stack_a->nbr == n)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

int	stack_len(t_node *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_node *find_last(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_node *get_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	init_stack_a(t_node **stack_a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		ft_printf("voici argv[%d]= %s\n", i, argv[i]);
		if (check_numbers(argv[i]) == false)
		{
			free_errors(*stack_a);
		}
		ft_printf("TU AS PASSE LE CHECK DES NOMBRES\n");
		n = ft_atol(argv[i]);
		printf("NOMBRE : %ld\n\n", n);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(*stack_a);
		ft_printf("TU AS PASSE LE CHECK DU INT MAX/MIN\n");
		if (check_duplicate(*stack_a, (int)n) == false)
			free_errors(*stack_a);
		ft_printf("TU AS PASSE LE CHECK DUPLICATE\n");
		append_node(stack_a, n);
		i++;
	}
}

void	append_node(t_node **stack, int n)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(*node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
