/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:26:14 by engooh            #+#    #+#             */
/*   Updated: 2022/02/17 16:16:20 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*ft_stack_new(int val, int index)
{
	t_stack	*p;

	p = malloc(sizeof(t_stack));
	if (!p)
		return (NULL);
	p->next = p;
	p->prev = p;
	p->val = val;
	p->index = index;
	return (p);
}

t_stack	*ft_stacklast(t_stack *stack, t_stack *temp)
{
	if (stack && (stack->next) != temp)
		return (ft_stacklast(stack->next, temp));
	return (stack);
}

void	ft_delstack(t_stack *stack, t_stack *tmp)
{
	if (!stack)
		return ;
	if (!tmp)
		tmp = stack->prev;
	if (stack != tmp)
		ft_delstack(stack->next, tmp);
	free(stack);
}

void	ft_stack_add_front(t_stack **alst, t_stack *new)
{
	t_stack	*temp;

	if (!(*alst))
	{
		new->next = new;
		new->prev = new;
		*alst = new;
		return ;
	}
	temp = (*alst)->prev;
	new->next = *alst;
	(*alst)->prev = new;
	new->prev = temp;
	temp->next = new;
	*alst = new;
}

t_stack	*ft_init_stack(int ac, char **av)
{
	t_stack	*stack;

	if (!ac)
		return (NULL);
	if (ft_check(ac, av))
		return (NULL);
	stack = ft_stack_new(ft_atoi(av[ac - 1]), ac);
	--ac;
	while (--ac > 0)
		ft_stack_add_front(&stack, ft_stack_new(ft_atoi(av[ac]), ac));
	return (stack);
}
