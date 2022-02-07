/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:40:33 by engooh            #+#    #+#             */
/*   Updated: 2022/02/07 12:48:11 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*temp;

	stack_a = ft_init_stack(ac, av);
	stack_b = NULL;
//	ft_push(&stack_a, &stack_b, "pa\n");
// printf("%d*\n", ft_stacklen(stack_a));len
	ft_sort_five(&stack_a, &stack_b);
	temp = stack_a->prev;
	printf("stack sort : \n");
	while (stack_a != temp)
	{
		printf("%d ", stack_a->content);
		stack_a = stack_a->next;
	}
	printf("%d ", stack_a->content);
	ft_delstack(stack_a, stack_a->prev);
	return (0);
}
