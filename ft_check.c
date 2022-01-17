/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:43:17 by engooh            #+#    #+#             */
/*   Updated: 2022/01/14 17:24:00 by lazarus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_check(int ac, char **av)
{
	int		i;
	long		j;

	if (ac < 2)
		return (1);
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
	return (0);
}
