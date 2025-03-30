/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 02:17:58 by lomont            #+#    #+#             */
/*   Updated: 2025/03/30 04:34:25 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	if (stack == NULL)
		return ;
	else
	{
		while (stack)
		{
			tmp = stack->next;
			free(stack);
			stack = tmp;
		}
	}
}

void	free_errors(t_node *stack, char **argv, bool is_malloc)
{
	if (is_malloc)
		free_tab(argv);
	free_stack(stack);
	ft_exit("Error\n");
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
