/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mediane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:46:16 by engooh            #+#    #+#             */
/*   Updated: 2022/02/02 16:49:12 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int ft_mediane(int *tabs, int start, int mil, int end)
{
	int med;

	if (tabs[start] < tabs[mil] && tabs[start] > tabs[end])
		med = start;
	else if (tabs[start] > tabs[mil] && tabs[start] < tabs[end])
		med = start;
	else if (tabs[end] < tabs[mil] && tabs[end] > tabs[start])
		med = end;
	else if (tabs[end] > tabs[mil] && tabs[end] < tabs[start])
		med = end;
	else if (tabs[mil] < tabs[end] && tabs[mil] > tabs[start])
		med = mil;
	else if (tabs[mil] > tabs[end] && tabs[mil] < tabs[start])
		med = mil;
	if (med != mil)
	{
		end = tabs[med];
		tabs[med] = tabs[mil];
		tabs[mil] = end;
	}
	return (mil);
}

int	ft_quicksort(int **tabs, int start, int end, int count)
{
	int med;
	int piv;
	int swp;
	int i;
	int j;

	printf("start = %d  ", tabs[0][start]);
	j = end;
	i = start;
	med = ft_mediane(tabs[0], start, end / 2, end);
	if (start)
	piv = tabs[0][med];
	while (i < j)
	{
		while (tabs[0][i] < piv)
			i++;
		while (tabs[0][j] > piv)
			j--;
		if (tabs[0][i] > tabs[0][j])
		{
			swp = tabs[0][j];
			tabs[0][j] = tabs[0][i];
			tabs[0][i] = swp;
		}
	}
	printf("med == %d piv == %d\n", med, piv);
	i = start; 
	while (i <= end)
		printf(" %d ", tabs[0][i++]);
	printf("\n\n");
	if (end > start && count >= 1)
		ft_quicksort(tabs, 0, med, count + 1);
	if (end > start && count <= 1)
		ft_quicksort(tabs, med + 1, end, count - 1);
	return (end);
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
	ft_quicksort(&tabs, 0, i - 1, 1);
	size = i;
	i = -1;
	while (++i < size)
		printf("%d ", tabs[i]);
	return (0);
}
