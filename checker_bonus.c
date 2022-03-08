/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:07:57 by engooh            #+#    #+#             */
/*   Updated: 2022/03/08 13:05:38 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker_bonus.h"

int	ft_free1(int len, char **tab)
{
	while (--len >= 0)
		free(tab[len]);
	free(tab);
	return (0);
}

int	ft_free2(t_stack *a, t_stack *b, void *s, int nbr)
{
	if (nbr == 1)
	{
		ft_delstack(a, a->prev);
		ft_delstack(b, b->prev);
		free(s);
		write (1, "KO\n", 4);
		return (0);
	}
	free(s);
	return (0);
}

int	checker(int ac, char **av)
{	
	t_stack	*a;
	t_stack	*b;	
	int		*tab;
	char	*std;

	if (ft_check(ac, av))
		return (0);
	b = NULL;
	std = readstd();
	a = ft_init_stack(ac, av);
	while (std)
	{
		if (std && !ft_rules(&a, &b, std))
			return (ft_free2(a, b, std, 1));
		free(std);
		std = NULL;
		std = readstd();
	}
	tab = get_tab(a, ac);
	if (!ft_is_sort2(ac, tab))
		return (write(1, "KO\n", 4));
	free(tab);
	return (write(1, "OK\n", 4));
}

int	main(int ac, char **av)
{
	int		len;
	char	**tab;

	if (ac == 1)
		return (0);
	if (ac <= 2)
	{
		tab = ft_split(av[1], ' ');
		len = ft_cntword(av[1], ' ', 0);
		checker(len, tab);
		ft_free1(len, tab);
		return (0);
	}
	else if (ac >= 3)
		checker(ac - 1, av + 1);
	return (0);
}
