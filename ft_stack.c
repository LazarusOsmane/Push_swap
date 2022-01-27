/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:26:14 by engooh            #+#    #+#             */
/*   Updated: 2022/01/26 12:59:45 by lazarus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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

t_stack	*ft_stacklast(t_stack *stack, t_stack *temp)
{
	if (stack && (stack->next) != temp)
		return (ft_stacklast(stack->next, temp));
	return (stack);
}

void ft_stack_add_back(t_stack **alst, t_stack *new, t_stack *temp)
{
	  if (!(*alst))
	  {
		    new->next = new;
		    new->prev = new;
		    *alst = new;
		    return ;
	  }
	  if (*alst && (*alst)->next != temp)
		    ft_stack_add_back(&((*alst)->next), new, temp);
	  if (*alst && (*alst)->next == temp)
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

	if (ft_check(ac, av))
		return (NULL);
	stack = ft_stack_new(ft_atoi(av[--ac]));
	while (--ac > 0)
		  ft_stack_add_front(&stack, ft_stack_new(ft_atoi(av[ac])));
	return (stack);
}
