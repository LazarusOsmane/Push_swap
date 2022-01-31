/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mediane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:46:16 by engooh            #+#    #+#             */
/*   Updated: 2022/01/31 16:25:56 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	**ft_create_tabs(int len, t_stack *stack, int size)
{
	int	i;
	int	j;
	int	**tabs;

	tabs = malloc(sizeof(int *) * size);
	if (!tabs)
		return (NULL);
	j = -1;
	tabs[--size] = 0;
	while (++j < size)
	{
		tabs[j] = malloc(sizeof(int) * 5);
		if (!tabs[j])
			return (NULL);
		i = -1;
		while (++i < 5 && len--)
		{
			tabs[j][i] = stack->content;
			stack = stack->next;
		}
	}
	return (tabs);
}

int	ft_get_mediane(int *tabs, int size, int i)
{
	int min;
	int max;
	int tab_index[3];

	if (size < 5)
		return (size);
	min = 0;
	max = 0;
	tab_index[0] = 0;
	tab_index[1] = size / 2;
	tab_index[2] = size - 1;
	while (++i < 3)
	{
			if (tabs[min] > tabs[tab_index[i]])
				min = tab_index[i];
			if (tabs[max] < tabs[tab_index[i]])
				max = tab_index[i];
	}
	i = -1; 
	while (++i < 3)
		if (tabs[tab_index[i]] != tabs[min] && tabs[tab_index[i]] != tabs[max])
			return(tab_index[i]);
	return (-1);
}

int ft_quicksort(int *tabs, int size)
{
	int	i;
	int swp;
	int	piv;

	i = 0;
	piv = ft_get_mediane(tabs, size, 0);
	while (++i < size)
		if (tabs[piv] < tabs[i] && i < piv)
		{
			swp = tabs[i];
			tabs[i] = tabs[piv];
			tabs[piv] = swp;
		}
	if (end > 1)
		return(ft_quicksort(tabs + 0, piv - 1) + ft_quicksort(tabs + piv, size - piv));
	return (1);
}

int ft_mediane_mediane(int size, t_stack *stack)
{
	int	i;
	int	j;
	int	**tabs;

	tabs = ft_create_tabs(size, stack, ((size) / 5) + 2);
	if (!tabs)
		return (0);
	ft_quicksort(tabs[0], size);
	i = -1;	
	while (tabs[++i] != 0)
	{	
		j = 0; 
		while (++j < 5 && size--)
			j++;
		free(tabs[i]);
	}
	free(tabs);
	return (0);
}
