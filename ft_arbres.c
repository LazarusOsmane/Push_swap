/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arbres.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:05:10 by engooh            #+#    #+#             */
/*   Updated: 2022/02/08 17:05:43 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_arbre	*ft_newnode(int value)
{
	t_arbre	*new;

	new = malloc(sizeof(t_arbre) * 1);
	if (!new)
		return (NULL);
	new->val = value;
	new->pos = -1;
	new->binom = NULL;
	new->un = NULL;
	new->de = NULL;
	return (new);
}

void	ft_addnode(t_arbre **arb, t_arbre *new)
{
	if (!*arb)
	{
		*arb = new;
		return ;
	}
	if ((*arb) && (*arb)->un && (*arb)->de)
		ft_addnode(&((*arb)->de), new);
	else if (!(*arb)->un)
		(*arb)->un = new;
	else
	{
		(*arb)->de = new;
		(*arb)->de->binom = (*arb)->un;
	}
}

void	ft_delarbre(t_arbre *arb)
{
	if (arb && arb->un && arb->de)
		ft_delarbre(arb->de);
	if (arb->un)
		free(arb->un);
	if (arb->de)
		free(arb->de);
	if (arb)
		free(arb);
}

void	ft_init_arbre(t_stack *stack, t_arbre **arb)
{
	t_stack	*temp;

	temp = stack->prev;
	while (stack != temp)
	{
		ft_addnode(arb, ft_newnode(stack->content));
		stack = stack->next;
	}
	ft_addnode(arb, ft_newnode(stack->content));
}
