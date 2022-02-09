/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:24:01 by engooh            #+#    #+#             */
/*   Updated: 2022/02/09 18:58:55 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"


void ft_pres_sort(t_stack **stack_a, t_stack **stack_b)
{
	int *tab;

	tab = NULL;
	while (stack_a)
	{
		tab = ft_get_stack_info(ft_stacklen(*stack_a), *stack_a);
		ft_push(stack_a, stack_b, "pa\n");
		if ((*stack_b)->content < tab[1])
			ft_rotate(stack_b, "rb\n");
		free(tab);
	}
}
