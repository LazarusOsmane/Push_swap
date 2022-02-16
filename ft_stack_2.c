/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:03:40 by engooh            #+#    #+#             */
/*   Updated: 2022/02/15 09:34:54 by lazarus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*ind(t_stack *stack, int index)
{
	  if (!stack)
		    return (NULL);
	if (index > 1)
		return(ind(stack->next, index - 1));
	return (stack);
}

int	ft_stacklen(t_stack *stack)
{
	int			i;
	t_stack	*tmp;

	if (!stack)
		return (0);
	i = 1;
	tmp = stack->prev;
	while (stack != tmp && i++)
		stack = stack->next;
	return (i);
}

void	reind(t_stack *stack)
{
	int			i;
	t_stack *temp;

	i = 0;
	temp = stack->prev;
	while (++i && stack != temp)
	{
		stack->index = i;
		stack = stack->next;
	}
	stack->index = i;
}
