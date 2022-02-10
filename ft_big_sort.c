/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:24:01 by engooh            #+#    #+#             */
/*   Updated: 2022/02/10 16:50:42 by engooh           ###   ########.fr       */
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
	int *tabs;
	int len;

	len = ft_stacklen(*stack_a);
	tab = ft_get_stack_info(len, *stack_a, 1);
	tabs = ft_get_stack_info(len, *stack_a, 0);
	ft_print_tabs(len, tabs);
	while (*stack_a &&)
	{
		if ((*stack_a)->content == tabs[len] && (*stack_a)->content > tab[1] && len--)
			ft_rotate(stack_a, "ra\n");
		ft_push(stack_a, stack_b, "pa\n");
		if (*stack_b && (*stack_b)->content < tab[1])
			ft_rotate(stack_b, "rb\n");
		if (*stack_b && (*stack_b)->content > tab[1] && (*stack_b)->content < (*stack_b)->next->content)
			ft_swap(stack_b, "sb\n");
	}
	free(tab);
}
