/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:40:33 by engooh            #+#    #+#             */
/*   Updated: 2022/02/01 16:05:29 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
//	t_stack	*stack_b;

	stack_a = ft_init_stack(ac, av);
//	stack_b = NULL;
//	ft_push(&stack_a, &stack_b, "pa\n");
// printf("%d*\n", ft_stacklen(stack_a));
	ft_mediane_mediane(ft_stacklen(stack_a), stack_a);
	ft_delstack(stack_a, stack_a->prev);
	return (0);
}
