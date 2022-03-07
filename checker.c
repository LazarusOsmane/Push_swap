/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:57:59 by engooh            #+#    #+#             */
/*   Updated: 2022/03/07 09:58:30 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

int	ft_free1(int len, char **tab)
{
	while (--len >= 0)
		free(tab[len]);
	free(tab);
	return (0);
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


int	ft_is_sort2(int ac, int *av)
{
	int	n;
	int	nbr;

	if (ac == 1)
		return (0);
	while (--ac > 0)
	{
		n = ac;
		nbr = av[ac];
		while (--n >= 0)
			if (nbr < av[n])
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

char *join(char *line, char *buf, int len)
{
	int i;
	char *new;

	if (!line)
	{
		line = malloc(sizeof(char) * 2);
		if (!line)
			return (NULL);
		line[0] = *buf;
		line[1] = '\0';
		return (line);
	}
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (line[++i])
		new[i] = line[i];
	new[i++] = buf[0];
	new[i] = '\0';
	if (line)
		free(line);
	return (new);
}

char	*readstd(void)
{
	int		i;
	char	*std;
	char	buf[1];

	i = 1;
	while (read(0, buf, 1))
	{
		std = join(std, buf, i);
		if (*buf == '\n')
			return (std);
		i++;
	}
	return (NULL);
}

int	ft_free2(char *s)
{
	free(s);
	return (0);
}

int	main(int ac, char **av)
{	
	t_stack	*a;
	t_stack	*b;	
	int		*tab;
	char	*std;

	if (ft_check(ac - 1, av + 1) || ac <= 2)
			return (0);
	b = NULL;
	std = readstd();
	a = ft_init_stack(ac - 1, av + 1);
	while (std)
	{
		if (!ft_rules(&a, &b, std) && !ft_free2(std))
			return (write(1, "KO\n", 4));
		free(std);
		std = NULL;
		std = readstd();
	}
	tab = ft_get_stack_info(ac - 1, a, 1);
	if (!ft_is_sort2(ac - 1, tab))
		write(1, "KO\n", 4);
	free(tab);
	ft_delstack(a, a->prev);
	ft_delstack(b, b->prev);
	return (write(1, "OK\n", 4));
}
