/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:26:14 by engooh            #+#    #+#             */
/*   Updated: 2022/01/24 00:41:37 by lazarus          ###   ########.fr       */
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

t_stack	*ft_stack_new(int content)
{
	t_stack	*p;

	p = malloc(sizeof(t_stack));
	if (!p)
		return (NULL);
	p->next = p;
	p->prev = p;
	p->content = content;
	return (p);
}

void ft_stack_add_back(t_stack **alst, t_stack *new, t_stack *temp)
{
	  if (*alst && ((uintptr_t)(*alst)->next) != (uintptr_t)temp)
		    ft_stack_add_back(&((*alst)->next), new, temp);
	  if (*alst && ((uintptr_t)(*alst)->next) == (uintptr_t)temp)
	  {
		    temp->prev = new;
		    (*alst)->next = new;
		    new->prev = *alst;
		    new->next = temp;
	  }
}

void	ft_stack_add_front(t_stack **alst, t_stack *new)
{
	  t_stack	*temp;

	  temp = ft_stacklast(*alst, *alst); 
	  new->next = *alst;
	  new->prev = temp;
	  temp->next = new;
	  *alst = new;
}

t_stack	*ft_stacklast(t_stack *stack, t_stack *temp)
{
	if (stack && (uintptr_t)(stack->next) != (uintptr_t)(temp))
		return (ft_stacklast(stack->next, temp));
	return (stack);
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
