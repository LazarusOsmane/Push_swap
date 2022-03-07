/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:16:48 by engooh            #+#    #+#             */
/*   Updated: 2022/03/07 09:50:22 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*ind(t_stack *stack, int index)
{
	if (!stack)
		return (NULL);
	if (index > 1)
		return (ind(stack->next, index - 1));
	return (stack);
}

int	ft_stacklen(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->prev->len);
}

int	ft_is_sort(int ac, char **av)
{
	int	n;
	int	nbr;

	if (ac == 1)
		return (0);
	while (--ac > 0)
	{
		n = ac;
		nbr = ft_atoi(av[ac]);
		while (--n >= 0)
			if (nbr < ft_atoi(av[n]))
				return (0);
	}
	return (1);
}

int	ft_check(int ac, char **av)
{
	int		i;
	long	j;

	i = -1;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]) && !(av[i][j + 1] &&
						av[i][j] == '-' && ft_isdigit(av[i][j + 1])))
				return (write(2, "Error\n", 6));
		j = i;
		while (++j < ac)
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (write(2, "Error\n", 6));
		j = ft_atoi(av[i]);
		if (j < INT_MIN || j > INT_MAX)
			return (write(2, "Error\n", 6));
	}
	if (ft_is_sort(ac, av))
		return (1);
	return (0);
}
