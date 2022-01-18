/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:19:58 by engooh            #+#    #+#             */
/*   Updated: 2022/01/18 14:21:00 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_push(t_stack **push, t_stack **recv, char *flag)
{
	t_stack	*swap;

	if (!(*push))
		return ;
	swap = *push;
	*push = (*push)->next;
	swap->next = NULL;
	if (*recv)
		swap->next = *recv;
	*recv = swap;
	ft_putstr_fd(flag, 1);
}

int	ft_swap(t_stack **stack, char *flag)
{
	t_stack	*temp;

	if (!((*stack)->next))
		return (1);
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	ft_putstr_fd(flag, 1);
	return (1);
}

int	ft_rotate(t_stack **stack, char *flag)
{
	t_stack	*temp;

	if (!(*stack)->next)
		return (1);
	temp = *stack;
	*stack = (*stack)->next;
	ft_stacklast(*stack)->next = temp;
	temp->next = NULL;
	ft_putstr_fd(flag, 1);
	return (1);
}

t_stack	*ft_reverse(t_stack **stack, char *flag)
{
	t_stack	*new;
	t_stack	*p;

	new = NULL;
	if (*stack && (*stack)->next)
		new = ft_reverse(&((*stack)->next), flag);
	if (!new)
		new = &(**stack);
	else
	{
		p = new;
		while (new->next)
			new = new->next;
		new->next = *stack;
		new->next->next = NULL;
		new = p;
	}
	if (!(new->next))
		ft_putstr_fd(flag, 1);
	return (new);
}

void	ft_repeat_rules(t_stack **stack_a, t_stack **stack_b, char *flag)
{
	if (!ft_strcmp(flag, "ss\n") && ft_swap(stack_a, "")
		&& ft_swap(stack_b, "ss\n"))
		return ;
	else if (!ft_strcmp(flag, "rr\n") && ft_rotate(stack_a, "")
		&& ft_rotate(stack_b, "rr\n"))
		return ;
	else if (!ft_strcmp(flag, "rra\n"))
	{
		*stack_a = ft_reverse(stack_a, "");
		ft_rotate(stack_a, "rra\n");
	}
	else if (!ft_strcmp(flag, "rrb\n"))
	{
		*stack_b = ft_reverse(stack_b, "");
		ft_rotate(stack_b, "rrb\n");
	}
	else if (!ft_strcmp(flag, "rrr\n"))
	{
		*stack_a = ft_reverse(stack_a, "");
		ft_rotate(stack_a, "");
		*stack_b = ft_reverse(stack_b, "");
		ft_rotate(stack_b, "rrr\n");
	}
}
