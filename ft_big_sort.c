/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:24:01 by engooh            #+#    #+#             */
/*   Updated: 2022/02/13 00:14:06 by lazarus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void ft_print_tabs(int size, int *tabs)
{
	int	i;

	printf("\nprint tabs : \n");
	i = -1;
	while (++i < size)
		printf("%d\n", tabs[i]);
	printf("\n");
}

void ft_pres_sort(t_stack **stack_a, t_stack **stack_b)
{
	int *tab;
	int end;

	tab = ft_get_stack_info(ft_stacklen(*stack_a), *stack_a, 1);
	end = tab[2] + 1;
	while ((*stack_a)->content != end)
	{
		  if ((*stack_a)->content == tab[2] && end > tab[2] && --end)
			    ft_rotate(stack_a, "ra\n");
		  ft_push(stack_a, stack_b, "pb\n");
		  if ((*stack_b)->content < tab[1])
			    ft_rotate(stack_b, "rb\n");
	}
	free(tab);
}

int	ft_get_majoran(int val, int len, t_stack *a)
{
	  int i;
	  int tmp;
	  int	min;
	  int res;
	  int *tab;

	  tab = ft_get_stack_info(len, a, 1);
	  min = tab[2];
	  res = 1;
	  i = 0;
	  while (++i <= len)
	  {
		    tmp = ind(a, i)->content;
		    if (tmp > val && tmp < min)
		    {
					  min = tmp;
					  res = i;
		    }
	  }
	  free(tab);
	  return (res);
}

int	ft_get_better_index(t_stack *a, t_stack *b, int res, int tab)
{
	  int i;
	  int maj;
	  int point;
	  int len_a;
	  int len_b;

	  i = 0;
	  len_a = ft_stacklen(a);
	  len_b = ft_stacklen(b);
	  res =  len_a + len_b + len_a;
	  while (i != len_a)
	  {
		    maj = ft_get_majoran(ind(a, i)->content, ft_stacklen(a), a);
		    if ((maj + i) < (len_a + len_b))
				point = (len_a + len_b) -  (len_a + len_b) - (maj + i); 
		    else 
				point = (len_a + len_b) - (maj + i);
		    if (point < res)
		    {
				res = point;
				tab[0] = i;
				tab[1] = maj;
		    }
	  }

}
