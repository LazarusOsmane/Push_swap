/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:40:33 by engooh            #+#    #+#             */
/*   Updated: 2022/03/02 14:27:01 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_free1(int len, char **tab)
{
	while (--len >= 0)
		free(tab[len]);
	free(tab);
	return (0);
}

int	push_swap(int ac, char **av)
{
	int			*tab;
	t_stack		**stack;

	if (ft_check(ac, av))
		return (0);
	stack = malloc(sizeof(t_stack *) * 2);
	if (!stack)
		return (0);
	tab = malloc(sizeof(int) * 6);
	if (!tab)
		return (0);
	stack[0] = ft_init_stack(ac, av);
	stack[1] = NULL;
	if (ac == 3)
		ft_sort_tree(&stack[0]);
	if (ac >= 2 && ac <= 5 && ac != 3)
		ft_sort_five(&stack[0], &stack[1]);
	if (ac > 5)
		ft_big_sort(stack, stack[0]->prev->len, tab);
	ft_delstack(stack[1], NULL);
	ft_delstack(stack[0], NULL);
	free(stack);
	if (ac < 6)
		free(tab);
	return (0);
}

int	main(int ac, char **av)
{
	int		len;
	char	**tab;

	if (ac <= 2)
	{
		tab = ft_split(av[1], ' ');
		len = ft_cntword(av[1], ' ', 0);
		push_swap(len, tab);
		ft_free1(len, tab);
		return (0);
	}
	else if (ac >= 3)
		push_swap(ac - 1, av + 1);
	return (0);
}
