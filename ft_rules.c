/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:19:58 by engooh            #+#    #+#             */
/*   Updated: 2022/02/16 14:22:44 by lazarus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_push(t_stack **push, t_stack **recv, char *flag)
{
	  t_stack	*swap;

	  if (!(*push))
		    return ;
	  swap = *push;
	  if (*push == (*push)->next)
		    *push = NULL;
	  else
	  {
		    (*push)->prev->next = (*push)->next;
		    (*push)->next->prev = (*push)->prev;
		    *push = (*push)->next;
	  }
	  if (*recv)
		    ft_stack_add_front(recv, swap);
	  else 
	  {
		    swap->next = swap;
		    swap->prev = swap;
		    *recv = swap;
	  }
	  ft_putstr_fd(flag, 1);
}

void ft_swap(t_stack **stack, char *flag)
{
	  t_stack	*temp;

	  if (*stack == (*stack)->next)
		    return ;
	  if (*stack == (*stack)->next->next)
		    return (ft_rotate(stack, flag));
	  temp = *stack;
	  *stack = (*stack)->next;
	  (*stack)->prev = temp->prev;
	  (*stack)->prev->next = *stack;
	  temp->next = (*stack)->next;
	  (*stack)->next->prev = temp;
	  temp->prev = *stack;
	  (*stack)->next = temp;
	  ft_putstr_fd(flag, 1);
}

void ft_rotate(t_stack **stack, char *flag)
{
	  if (!(*stack)->next)
		    return ;
	  *stack = (*stack)->next;
	  ft_putstr_fd(flag, 1);
}

void	ft_reverse(t_stack **stack, char *flag)
{
	  if (*stack == (*stack)->next)
		    return ;
	  *stack = (*stack)->prev;
	  ft_putstr_fd(flag, 1);
}

void ft_repeate(t_stack **stack_a, t_stack **stack_b, char *flag)
{
	  if (!ft_strcmp(flag, "ss\n"))
	  {
		    ft_swap(stack_a, "");
		    ft_swap(stack_b, "ss\n");
	  }
	  else if (!ft_strcmp(flag, "rr\n"))
	  {
		    ft_rotate(stack_a, "");
		    ft_rotate(stack_b, "rr\n");
	  }
	  else if (!ft_strcmp(flag, "rrr\n"))
	  {
		    ft_reverse(stack_a, "");
		    ft_reverse(stack_b, "rrr\n");
	  }
}

