/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:24:01 by engooh            #+#    #+#             */
/*   Updated: 2022/03/07 08:48:01 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_pres_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	*tab;
	int	end;

	tab = ft_get_stack_info((*stack_a)->prev->len, *stack_a, 1);
	end = tab[2] + 1;
	while ((*stack_a) && (*stack_a)->val != end)
	{
		if ((*stack_a)->val == tab[2] && end > tab[2] && --end)
			ft_rotate(stack_a, "ra\n");
		ft_push(stack_a, stack_b, "pb\n");
		if ((*stack_b)->val < tab[1])
			ft_rotate(stack_b, "rb\n");
	}
	free(tab);
}

int	ft_get_majoran(int val, t_stack *s)
{
	int	i;
	int	len;
	int	res;
	int	elem;
	int	majoran;

	i = 0;
	res = 1;
	majoran = INT_MAX;
	len = ft_stacklen(s);
	while (++i <= len)
	{
		elem = ind(s, i)->val;
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
	int	i;
	int	len[5];

	i = 0;
	len[0] = ft_stacklen(a);
	len[1] = ft_stacklen(b);
	while (++i <= len[1])
	{
		len[4] = ft_get_majoran(ind(b, i)->val, a);
		if (i <= len[1] / 2)
			len[2] = i - 1;
		else if (i > len[1] / 2)
			len[2] = len[1] - (i - 1);
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

void	ft_val_top(t_stack **s, int a, int b, int *tab)
{
	tab[3] = ft_stacklen(s[0]);
	tab[4] = ft_stacklen(s[1]);
	if (tab[3] % 2 != 0)
		tab[3]++;
	if (tab[4] % 2 != 0)
		tab[4]++;
	if (tab[1] <= tab[3] / 2 && tab[2] <= tab[4] / 2)
		while (s[0] && s[1] && s[0]->val != a && s[1]->val != b)
			ft_repeate(&s[0], &s[1], "rr\n");
	if (tab[1] > tab[3] / 2 && tab[2] > tab[4] / 2)
		while (s[0] && s[1] && s[0]->val != a && s[1]->val != b)
			ft_repeate(&s[0], &s[1], "rrr\n");
	if (tab[1] <= tab[3] / 2)
		while (s[0] && s[0]->val != a)
			ft_rotate(&s[0], "ra\n");
	if (tab[1] > tab[3] / 2)
		while (s[0] && s[0]->val != a)
			ft_reverse(&s[0], "rra\n");
	if (tab[2] <= tab[4] / 2)
		while (s[1] && s[1]->val != b)
			ft_rotate(&s[1], "rb\n");
	if (tab[2] > tab[4] / 2)
		while (s[1] && s[1]->val != b)
			ft_reverse(&s[1], "rrb\n");
}

void	ft_push_min_nbr(t_stack **stack_a, t_stack **stack_b, int len)
{
	int			i;
	int			*tab;
	t_stack		*temp;

	i = 0;
	temp = *stack_a;
	tab = ft_get_stack_info(5, *stack_a, 1);
	while (tab[0] != temp->val)
		temp = ind(*stack_a, ++i);
	if (i > len / 2)
		while ((*stack_a)->val != tab[0])
			ft_reverse(stack_a, "rra\n");
	else if (i <= len / 2)
		while ((*stack_a)->val != tab[0])
			ft_rotate(stack_a, "ra\n");
	free(tab);
	ft_push(stack_a, stack_b, "pb\n");
}
