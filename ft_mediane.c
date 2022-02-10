/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mediane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:46:16 by engooh            #+#    #+#             */
/*   Updated: 2022/02/10 16:48:21 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_max(int *tab, int size)
{
	int	i;
	int	s;
	int	max;

	i = -1;
	max = 1;
	while (++i < size)
		if (tab[i] > tab[max])
			max = i;
	i--;
	s = tab[i];
	tab[i] = tab[max];
	tab[max] = s;
}

int	*ft_sort_in_tab(int *tab, int size)
{
	if (size > 1)
	{
		ft_max(tab, size);
		ft_sort_in_tab(tab, size - 1);
	}
	return (tab);
}

int	*ft_free(int *tab, int *tabs, int flag)
{
	if (flag == 1)
	{
		free(tabs);
		return (tab);
	}
	free(tab);
	return (tabs);
}

int	*ft_get_stack_info(int size, t_stack *stack, int flag)
{
	int	*tabs;
	int	*tab;
	int	i;

	i = size;
	tabs = malloc(sizeof(int) * (size));
	if (!tabs)
		return (0);
	tab = malloc(sizeof(int) * 3);
	if (!tab)
		return (NULL);
	while (--size >= 0)
	{
		stack = stack->prev;
		tabs[size] = stack->content;
	}
	ft_sort_in_tab(tabs, i);
	tab[0] = tabs[0];
	tab[1] = tabs[i / 2];
	tab[2] = tabs[i - 1];
	if (flag == 1)
		return (ft_free(tab, tabs, flag));
	else
		return (ft_free(tab, tabs, flag));
}
