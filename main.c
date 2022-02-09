/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:40:33 by engooh            #+#    #+#             */
/*   Updated: 2022/02/08 17:27:01 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*temp;
	t_arbre	*arb;
	t_arbre *tmp;

	(void)stack_b;
	stack_a = ft_init_stack(ac, av);
	stack_b = NULL;
//	ft_push(&stack_a, &stack_b, "pa\n");
// printf("%d*\n", ft_stacklen(stack_a));len
	
//ft_sort_five(&stack_a, &stack_b);
	//temp = stack_a->prev;

	arb = NULL;
	ft_init_arbre(stack_a, &arb);
	ft_position_theorique(&arb);
	printf("arbre binaire");

	tmp = arb;
	if (tmp)
			printf("value = %d | position = %d\n", tmp->val, tmp->pos);
	while (tmp)
	{
		if (tmp->un)
			printf("value = %d | position = %d", tmp->un->val, tmp->un->pos);
		if (tmp->de)
			printf("  value = %d | position = %d\n", tmp->de->val, tmp->de->pos);
		tmp = tmp->de;
	}


	printf("stack sort : \n");
	//ft_delarbre(arb);
	temp = stack_a->prev;
	while (stack_a != temp)
	{
		printf("%d ", stack_a->content);
		stack_a = stack_a->next;
	}
	printf("%d ", stack_a->content);
	ft_delstack(stack_a, stack_a->prev);
	return (0);
}
