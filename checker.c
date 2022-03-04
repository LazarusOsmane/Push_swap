/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:57:59 by engooh            #+#    #+#             */
/*   Updated: 2022/03/04 20:58:08 by engooh           ###   ########.fr       */
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


int	checker(int ac, char **av)
{
	char		*rls;
	
	//if (ft_check(ac - 1, av + 1))
		//return (0);
	(void)rls;(void)ac;(void)av;
	printf("ICI\n");
	//read_output();
	return (1);
}

int	main(int ac, char **av)
{
	char	*std;
	char	buf[1];
	int		i;

	(void)ac;(void)av;
	i = 0;
	std = NULL;
	while (read(0, buf, 1))
		std = join(std, buf, i++);
	printf("%s", std);
	return (0);
}
