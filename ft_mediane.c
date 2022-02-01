/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mediane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:46:16 by engooh            #+#    #+#             */
/*   Updated: 2022/02/01 18:53:23 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int ft_mediane(int *tabs, int start, int mil, int end)
{
	if (tabs[start] < tabs[mil] && tabs[start] > tabs[end])
		return (start);
	else if (tabs[start] > tabs[mil] && tabs[start] < tabs[end])
		return (start);
	else if (tabs[end] < tabs[mil] && tabs[end] > tabs[start])
		return (end);
	else if (tabs[end] > tabs[mil] && tabs[end] < tabs[start])
		return (end);
	else if (tabs[mil] < tabs[end] && tabs[mil] > tabs[start])
		return (mil);
	else if (tabs[mil] > tabs[end] && tabs[mil] < tabs[start])
		return (mil);
	return (end);
}

int *ft_quicksort(int *tabs, int size)
{
	int med;
//	int max;
	int swp;
	int i;
	int j;

	med = ft_mediane(tabs, 0, (size -1) / 2, size - 1);
	//printf("%d", tabs[med]);
	i = -1;
	j = --size;
	while (++i < j)
	{
		while (tabs[i] < tabs[med] && i < med)
			i++;
		while (tabs[j] > tabs[med] && j > med)
			--j;
		if (tabs[i] > tabs[j] && (i >= med))
		{
			if (tabs[i] == tabs[med])
				med = i;
			else if (tabs[j] == tabs[med])
				med = j;
			swp = tabs[j];
			tabs[j] = tabs[i];
			tabs[i] = swp;
			j--;
			i++;
		}
	}
	i = -1; 
	while (++i < size)
		printf(" %d ", tabs[i]);
	return (tabs);
}

int ft_mediane_mediane(int size, t_stack *stack)
{
	int *tabs;
	int i;

	i = size;
	tabs = malloc(sizeof(int) * (size));
	if (!tabs)
		return (0);
	while (--size >= 0)
	{
		stack = stack->prev;
		tabs[size] = stack->content;
	}
	tabs = ft_quicksort(tabs, i);
	return (0);
}
