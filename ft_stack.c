/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:26:14 by engooh            #+#    #+#             */
/*   Updated: 2022/01/18 14:27:19 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_check(int ac, char **av)
{
	int		i;
	long	j;

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

void	ft_stack_add_front(t_stack **alst, t_stack *new)
{
	new->next = &(**alst);
	*alst = new;
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (stack && stack->next)
		return (ft_stacklast(stack->next));
	return (stack);
}

t_stack	*ft_stack_new(int content)
{
	t_stack	*p;

	p = malloc(sizeof(t_stack));
	if (!p)
		return (NULL);
	p->next = NULL;
	p->content = content;
	return (p);
}

t_stack	*ft_init_stack(int ac, char **av)
{
	t_stack	*stack;

	if (ft_check(ac, av))
		return (NULL);
	stack = ft_stack_new(ft_atoi(av[--ac]));
	while (--ac > 0)
		ft_stack_add_front(&stack, ft_stack_new(ft_atoi(av[ac])));
	return (stack);
}
