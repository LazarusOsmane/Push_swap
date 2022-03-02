/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 09:55:37 by engooh            #+#    #+#             */
/*   Updated: 2022/02/28 19:27:38 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_sort_tree(t_stack **stack)
{
	int	*tab;

	tab = ft_get_stack_info(3, *stack, 1);
	if (tab[1] == ind(*stack, 2)->val && tab[0] == ind(*stack, 3)->val)
	{
		ft_rotate(stack, "ra\n");
		ft_swap(stack, "sa\n");
	}
	else if (tab[2] == ind(*stack, 2)->val && tab[0] == ind(*stack, 3)->val)
	{
		ft_rotate(stack, "ra\n");
		ft_rotate(stack, "ra\n");
	}
	else if (tab[2] == ind(*stack, 2)->val && tab[1] == ind(*stack, 3)->val)
	{
		ft_swap(stack, "sa\n");
		ft_rotate(stack, "ra\n");
	}
	else if (tab[0] == ind(*stack, 2)->val && tab[1] == ind(*stack, 3)->val)
		ft_rotate(stack, "ra\n");
	else if (tab[0] == ind(*stack, 2)->val && tab[2] == ind(*stack, 3)->val)
		ft_swap(stack, "sa\n");
	free(tab);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacklen(*stack_a) == 2)
		return (ft_swap(stack_a, "sa\n"));
	ft_push_min_nbr(stack_a, stack_b, ft_stacklen(*stack_a));
	ft_push_min_nbr(stack_a, stack_b, ft_stacklen(*stack_a));
	ft_sort_tree(stack_a);
	if ((*stack_b) && (*stack_b)->val < (*stack_b)->next->val)
		ft_swap(stack_b, "sb\n");
	while (*stack_b)
		ft_push(stack_b, stack_a, "pa\n");
}

int	ft_big_sort(t_stack **s, int len, int *tab)
{
	ft_pres_sort(&s[0], &s[1]);
	while (s[1])
	{
		tab[0] = INT_MAX;
		tab = ft_get_better_index(s[0], s[1], tab);
		if (s[1] && s[0] && tab[1] && tab[2])
			ft_val_top(s, ind(s[0], tab[1])->val, ind(s[1], tab[2])->val, tab);
		ft_push(&s[1], &s[0], "pa\n");
	}
	free(tab);
	len = ft_stacklen(s[0]);
	tab = ft_get_stack_info(len, s[0], 1);
	if (len % 2)
		len++;
	if (tab[0] <= len / 2)
		while ((s[0])->val != tab[0])
			ft_rotate(&s[0], "ra\n");
	if (tab[0] > len / 2)
		while ((s[0])->val != tab[0])
			ft_reverse(&s[0], "rra\n");
	free(tab);
	return (0);
}
