/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:08:25 by engooh            #+#    #+#             */
/*   Updated: 2022/03/07 15:08:40 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker_bonus.h"

int	*get_tab(t_stack *stack, int size)
{
	int	*tab;

	tab = malloc(sizeof(int) * (size));
	if (!tab)
		return (NULL);
	while (--size >= 0)
	{
		stack = stack->prev;
		tab[size] = stack->val;
	}
	return (tab);
}

int	ft_is_sort2(int ac, int *av)
{
	int	n;
	int	nbr;

	if (ac == 1)
		return (0);
	while (--ac >= 0)
	{
		n = ac;
		nbr = av[ac];
		while (--n >= 0)
			if (nbr < av[n])
				return (0);
	}
	return (1);
}

char	*join(char *line, char *buf, int len)
{
	int		i;
	char	*new;

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
	std = NULL;
	while (read(0, buf, 1))
	{
		std = join(std, buf, i);
		if (*buf == '\n')
			return (std);
		i++;
	}
	return (NULL);
}

int	ft_rules(t_stack **a, t_stack **b, char *rsl)
{
	if (!ft_strcmp(rsl, "ra\n"))
		return (ft_rotate(a, ""));
	else if (!ft_strcmp(rsl, "rb\n"))
		return (ft_rotate(b, ""));
	else if (!ft_strcmp(rsl, "sa\n"))
		return (ft_swap(a, ""));
	else if (!ft_strcmp(rsl, "sb\n"))
		return (ft_swap(b, ""));
	else if (!ft_strcmp(rsl, "pa\n"))
		return (ft_push(b, a, ""));
	else if (!ft_strcmp(rsl, "pb\n"))
		return (ft_push(a, b, ""));
	else if (!ft_strcmp(rsl, "rra\n"))
		return (ft_reverse(a, ""));
	else if (!ft_strcmp(rsl, "rrb\n"))
		return (ft_reverse(b, ""));
	else if (!ft_strcmp(rsl, "rrr\n"))
		return (ft_reverse(a, "") + ft_reverse(b, ""));
	else if (!ft_strcmp(rsl, "rr\n"))
		return (ft_rotate(a, "") + ft_rotate(b, ""));
	else if (!ft_strcmp(rsl, "ss\n"))
		return (ft_swap(a, "") + ft_swap(b, ""));
	return (0);
}
