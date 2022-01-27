/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:30:38 by engooh            #+#    #+#             */
/*   Updated: 2022/01/26 12:50:21 by lazarus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*void	ft_sort(t_stack **stack, int stacklen)
{
	ft_mediane_mediane(*stack, NULL, stacklen / 5, -1);
}

int	**ft_tabs(int size)
{
	int	**tabs;

	tabs = malloc(sizeof(int *) * (size + 1));
	if (!(tabs))
		return (NULL);
	while (size)
	{
		tabs[size] = malloc(sizeof(int) * 5);
		if (!(tabs[size]))
			return (NULL);
		size--;
	}
	return (tabs);
}

int	ft_mediane_mediane(t_stack *stack, int **tabs, int size, int i)
{
	if (!tabs)
		tabs = ft_tabs(size);
	while (stack && ++i < 5)
	{
		tabs[size][i] = stack->content;
		stack = stack->next;
	}
	if (size)
		ft_mediane_mediane(stack->next, tabs, size - 1, -1);
}*/
