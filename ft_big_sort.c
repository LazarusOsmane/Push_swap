/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:24:01 by engooh            #+#    #+#             */
/*   Updated: 2022/02/09 18:12:59 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"


t_arbre	*ft_new_branche(int value)
{
	t_arbre	*new;

	new = malloc(sizeof(t_arbre) * 1);
	if (!new)
		return (NULL);
	new->val = value;
	new->un = NULL;
	new->de = NULL;
	return (new);
}

//0 10 7 2 6 3 5 8 4 1


int ft_add_branche(t_arbre *arb, int value, int flag)
{
	if (arb->value > value)
	{
		if (arb->de)
			ft_add_branche(arb->de, value, flag);
		if (!arb->de)
			arb->de = ft_new_branche(value);
		return (1);
	}
	else if (arb->value < value)
	{
		if (!arb->un)
			arb->un = ft_new_branche(value);
	}
}

t_arbre	ft_init_chunk(t_stack *stack, t_arbre *arb, t_stack *start)
{
	int			suite;
	int			point;
	t_stack	temp;


	if ()
	{
		temp = stack;
		while (stack != temp)
		{
			arb = ft_add_branche(arb, stack->content)
		}
	}
}
