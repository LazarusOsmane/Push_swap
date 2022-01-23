/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:40:33 by engooh            #+#    #+#             */
/*   Updated: 2022/01/24 00:40:53 by lazarus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = ft_init_stack(ac, av);
	while (stack->content != 10)
	{
		  printf("%d", stack->content);
		  stack = stack->next;
	}
	printf("%d\n", stack->content);
	stack = stack->next;
	while (stack->content != 10)
	{
		  printf("%d", stack->content);
		  stack = stack->next;
	}
	printf("%d\n", stack->content);
	stack = stack->next;
	while (stack->content != 10)
	{
		  printf("%d", stack->content);
		  stack = stack->next;
	}
	printf("%d\n", stack->content);
	stack = stack->next;
	return (0);
}
