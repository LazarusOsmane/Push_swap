/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:16:48 by engooh            #+#    #+#             */
/*   Updated: 2022/02/17 16:40:47 by engooh           ###   ########.fr       */
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
	int				i;
	t_stack				*tmp;

	if (!stack)
		return (0);
	i = 1;
	tmp = stack->prev;
	while (stack != tmp && i++)
		stack = stack->next;
	return (i);
}

int	ft_is_sort(int ac, char **av)
{
	int	n;
	int	nbr;

	while (--ac > 0)
	{
		n = ac;
		nbr = ft_atoi(av[ac]);
		while (--n > 0)
			if (nbr < ft_atoi(av[n]))
				return (0);
	}
	return (1);
}

int	ft_check(int ac, char **av)
{
	int		i;
	long	j;

	if (ac >= 2 && !ft_is_sort(ac, av))
	{
		i = 0;
		while (++i < ac)
		{
			j = -1;
			while (av[i][++j])
				if (!ft_isdigit(av[i][j]) && av[i][j] != '-')
					return (write(2, "Error\n", 6));
			j = i;
			while (++j < ac)
				if (!ft_strcmp(av[i], av[j]))
					return (write(2, "Error\n", 6));
			j = ft_atoi(av[i]);
			if (j < INT_MIN || j > INT_MAX)
				return (write(2, "Error\n", 6));
		}
	}
	else
		return (1);
	return (0);
}
