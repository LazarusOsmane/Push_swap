/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:24:01 by engooh            #+#    #+#             */
/*   Updated: 2022/02/16 17:11:10 by lazarus          ###   ########.fr       */
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

int	ft_get_majoran(int val, t_stack *s)
{
	  int i;
	  int len;
	  int res;
	  int elem;
	  int majoran;

	  i = 0;
	  res = 1;
	  majoran = INT_MAX;
	  len = ft_stacklen(s);
	  while (++i <= len)
	  {
		    elem = ind(s, i)->content;
		    if (elem > val && elem < majoran)
		    {
				majoran = elem;
				res = i;
		    }
	  }
	  return (res);
}

int	*ft_get_better_index(t_stack *a, t_stack *b, int *res)
{
	  int i;
	  int len[4];

	  i = 0;
	  len[0] = ft_stacklen(a);
	  len[1] = ft_stacklen(b);
	  while (++i <= len[1])
	  {
		    len[4] = ft_get_majoran(ind(b, i)->content, a);
		    if (i <= len[1] / 2)
				len[2] = i - 1;
		    if (i > len[1] / 2)
				len[2] += len[1] - (i - 1);
		    if (len[4] <= len[0] / 2)
				len[2] += len[4] - 1;
		    if (len[4] > len[0] / 2)
				len[2] += len[0] - (len[4] - 1);
		    if (len[2] < res[0])
		    {
				res[0] = len[2];
				res[1] = len[4];
				res[2] = i;
		    }
	  }
	  return (res);
}

void ft_val_top(t_stack **a, t_stack **b, int *tab)
{
	  int elema;
	  int elemb;

	  tab[3] = ft_stacklen(*a);
	  tab[4] = ft_stacklen(*b);
	  elema = ind(*a, tab[1])->content;
	  elemb = ind(*b, tab[2])->content; 
	  if (tab[3] % 2 != 0)
		    tab[3]++;
	  if (tab[4] % 2 != 0)
		    tab[4]++;
	  if (tab[1] <= tab[3] / 2 && tab[2] <= tab[4] / 2)
		    while (*a && *b && (*a)->content != elema && (*b)->content != elemb)
				ft_repeate(a, b, "rr\n");
	  if (tab[1] > tab[3] / 2 && tab[2] > tab[4] / 2)
		    while (*a && *b && (*a)->content != elema && (*b)->content != elemb)
				ft_repeate(a, b, "rrr\n");
	  if (tab[1] <= tab[3] / 2)
		    while (*a && (*a)->content != elema)
				ft_rotate(a, "ra\n");
	  if (tab[1] > tab[3] / 2)
		    while (*a && (*a)->content != elema)
				ft_reverse(a, "rra\n");
	  if (tab[2] <= tab[4] / 2)
		    while (*b && (*b)->content != elemb)
				ft_rotate(b, "rb\n");
	  if (tab[2] > tab[4] / 2)
		    while (*b && (*b)->content != elemb)
				ft_reverse(b, "rrb\n");
}

int ft_big_sort(t_stack **a, t_stack **b)
{
	  int len;
	  int *tab;

	  tab = malloc(sizeof(int) * 6);
	  if (!tab)
		    return (0);
	  ft_pres_sort(a, b);
	  while (*b)
	  {
		    tab[0] = INT_MAX;
		    tab = ft_get_better_index(*a, *b, tab);
		    ft_val_top(a, b, tab) ;
		    ft_push(b, a, "pa\n");
		    ft_print_stack(*a, 'a');
		    if (*b)
				ft_print_stack(*b, 'b');
	  }
	  free(tab);
	  len = ft_stacklen(*a);
	  tab = ft_get_stack_info(len, *a, 1);
	  if (len % 2)
		    len++;
	  if (tab[0] <= len / 2)
		    while ((*a)->content != tab[0])
				ft_rotate(a, "ra\n");
	  if (tab[0] > len / 2)
		    while ((*a)->content != tab[0])
				ft_reverse(a, "rra\n");
	  free(tab);
	  return (0);
}

int ft_big_sort(t_stack)
{

}
