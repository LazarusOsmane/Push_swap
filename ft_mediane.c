/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mediane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:46:16 by engooh            #+#    #+#             */
/*   Updated: 2022/01/30 22:56:38 by lazarus          ###   ########.fr       */
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

int ft_get_mediane(int *tabs, int i, int min, int max)
{
	  int	res;

	  res = 0;
	  while (++i < 2)
	  {
		    if (max > tabs[i + 1])
				max = i;
		    if (min < tabs[i + 1])
				min = i;
	  }
	  i = -1;
	  while (++i < 2)
		    if (i != min && i != max)
				res = i;
	  return (tabs[res]);
}

int ft_quicksort(int *tabs, int end)
{
	  int end;

	  end = size;
	  if (size > 1)
		    ft_quicksort(tabs, size)
}

int ft_mediane_mediane(int size, t_stack *stack)
{
	int	i;
	int	j;
	int	**tabs;

	tabs = ft_create_tabs(size, stack, ((size) / 5) + 2);
	if (!tabs)
		return (0);
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
