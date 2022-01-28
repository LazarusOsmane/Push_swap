/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mediane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:46:16 by engooh            #+#    #+#             */
/*   Updated: 2022/01/28 17:34:10 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	**ft_create_tabs(int ac, t_stack *stack, int size)
{
	int	i;
	int	j;
	int	**tabs;

	if (ac < 4)
		return (NULL);
	if (!size)
		size = 2;
	tabs = malloc(sizeof(int *) * size);
	if (!tabs)
		return (NULL);
	tabs[--size] = 0;
	j = -1;
	while (++j < size)
	{
		tabs[j] = malloc(sizeof(int) * 5);
		if (!tabs[j])
			return (NULL);
		i = -1;
		while (++i < 5 && --ac)
		{
			tabs[j][i] = stack->content;
			stack = stack->next;
		}
	}
	return (tabs);
}

int ft_sort(int *tabs, int size)
{
	int	i;
	int	j;
	int	swp;

	i = 0;
	while (i < size)
	{
		j = i;
		while (tabs[i] > tabs[i])
	}
}


int	ft_quicksort(int	*av)
{
	
}

int ft_mediane_mediane(int ac, t_stack *stack)
{
	int	i;
	int	j;	
	int	**tabs;

	tabs = ft_create_tabs(ac, stack, ((ac - 1) / 5) + 2);
	if (!tabs)
		return (0);
	i = -1;
	while (tabs[++i] != 0)
	{	
		j = -1; 
		while (++j < 5 && --ac)
		{
			printf("%d\n", tabs[i][j]);
		}
	}
	
	return (0);
}
