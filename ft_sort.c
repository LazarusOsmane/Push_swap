/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 09:55:37 by engooh            #+#    #+#             */
/*   Updated: 2022/02/07 16:23:44 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_sort_tree(t_stack **stack)
{
	int	*tab;

	tab = ft_get_stack_info(3, *stack);
	if (tab[1] == ind(*stack, 2)->content && tab[0] == ind(*stack, 3)->content)
	{
		ft_rotate(stack, "ra\n");
		ft_swap(stack, "sa\n");
	}
	else if (tab[2] == ind(*stack, 2)->content && tab[0] == ind(*stack, 3)->content)
	{
		ft_rotate(stack, "ra\n");
		ft_rotate(stack, "ra\n");
	}
	else if (tab[2] == ind(*stack, 2)->content && tab[1] == ind(*stack, 3)->content)
	{
		ft_swap(stack, "sa\n");
		ft_rotate(stack, "ra\n");
	}
	else if (tab[0] == ind(*stack, 2)->content && tab[1] == ind(*stack, 3)->content)
		ft_rotate(stack, "ra\n");
	else if (tab[0] == ind(*stack, 2)->content && tab[2] == ind(*stack, 3)->content)
		ft_swap(stack, "sa\n");
	free(tab);
}

void ft_push_min_nbr(t_stack **stack_a, t_stack **stack_b, int len)
{
	int i;
	int *tab;
	t_stack *temp;

	i = 0;
	temp = *stack_a;
	tab = ft_get_stack_info(5, *stack_a);
	while (tab[0] != temp->content)
		temp = ind(*stack_a, ++i);
	if (temp->index > len / 2 && temp->index != len / 2 + 1)
		while ((*stack_a)->content != tab[0])
			ft_reverse(stack_a, "rra\n");
	else 
		while ((*stack_a)->content != tab[0])
			ft_rotate(stack_a, "ra\n");
	free(tab);
	ft_push(stack_a, stack_b, "pa\n");
}

void ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_min_nbr(stack_a, stack_b, ft_stacklen(*stack_a));
	reind(*stack_a);
	ft_push_min_nbr(stack_a, stack_b, ft_stacklen(*stack_a));
	reind(*stack_a);
	ft_sort_tree(stack_a);
	reind(*stack_b);
	if ((*stack_b)->content  <	 (*stack_b)->next->content)
		ft_swap(stack_b, "sb\n");
	while (*stack_b)
		ft_push(stack_b, stack_a, "pb\n");
}
