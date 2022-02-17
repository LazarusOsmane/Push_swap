/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:40:33 by engooh            #+#    #+#             */
/*   Updated: 2022/02/17 16:31:04 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int ac, char **av)
{
	int			*tab;
	t_stack	**stack;

	if (ft_check(ac - 1, av))
		return (0);
	stack = malloc(sizeof(t_stack *) * 2);
	if (!stack)
		return (0);
	tab = malloc(sizeof(int) * 6);
	if (!tab)
		return (0);
	stack[0] = ft_init_stack(ac, av);
	stack[1] = NULL;
	if (ac - 1 == 3)
		ft_sort_tree(&stack[0]);
	else if (ac - 1 == 5)
		ft_sort_five(&stack[0], &stack[1]);
	else if (ac - 1 > 5)
		ft_big_sort(stack, ft_stacklen(stack[0]), tab);
	ft_delstack(stack[1], NULL);
	ft_delstack(stack[0], NULL);
	return (0);
}
