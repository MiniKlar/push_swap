/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 02:38:46 by lomont            #+#    #+#             */
/*   Updated: 2025/03/25 04:24:24 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_stack_a(t_node **stack_a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(stack_a);
		n = ft_atol(argv[i])
		if (n > INT_MAX || n < INT_MIN)
			free_errors(stack_a);
		if (error_duplicate(*a, (int)n)
			free_errors(stack_a);
		append_node(stack_a, (int)n);
		i++;
	}
}
void	append_node (t_node **stack, int n)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack)
		exit(EXIT_FAILURE);
	node = malloc(sizeof(*node));
	if (!node)
		exit(EXIT_FAILURE);
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

	// j = 1;
	// n = ft_atol(argv[argc - i]);
	// printf("%s\n\n", argv[argc - i]);
	// if (ft_strncmp(argv[argc - i], "0", 0) != 0 && n != 0)
	// {
	// 	while (ft_strncmp(argv[argc - i], 0, j))
	// 	{
	// 		k++;
	// 		j++;
	// 	}
	// }
	// else
	// {
	// 	printf("PREMIER EST ZERO\n\n");
	// }
	// n = ft_atol(argv[argc - i] + k);
// 	printf("VOICI LE DERNIER CHIFFRE %ld\n\n", ft_atol(argv[argc - i]));
// 	first_p = initalisation(ft_atol(argv[argc - i]));
// 	//printf("\n premiere node cree : %d", first_p->first->nbr);
// 	i++;
// 	while (argc - i != 0)
// 	{
// 		insertion(first_p, ft_atol(argv[argc - i]));
// 		printf("VOICI LE CHIFFRE %ld\n\n", ft_atol(argv[argc - i]));
// 		i++;
// 	}
// 	printf("VOICI LE DERNIER CHIFFRE %d\n\n", first_p->first->nbr);
// 	return (first_p);
// }
// list *fill_stack_b(void)
// {
// 	list 	*first_p;
// 	first_p = initalisation(0);
// 	printf("\n premiere node cree : %d", first_p->first->nbr);
// 	return (first_p);
// }
