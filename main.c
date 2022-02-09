/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:40:33 by engooh            #+#    #+#             */
/*   Updated: 2022/02/09 19:05:43 by engooh           ###   ########.fr       */
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
	
//ft_sort_five(&stack_a, &stack_b);
	//temp = stack_a->prev;

	ft_pres_sort(&stack_a, &stack_b);
	printf("stack sort : \n");
	//ft_delarbre(arb);
	temp = stack_b->prev;
	while (stack_b != temp)
	{
		printf("%d ", stack_b->content);
		stack_b = stack_b->next;
	}
	printf("%d ", stack_b->content);
	ft_delstack(stack_b, stack_b->prev);
	return (0);
}
