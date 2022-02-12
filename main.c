/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:40:33 by engooh            #+#    #+#             */
/*   Updated: 2022/02/12 23:14:16 by lazarus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_print_stack(t_stack *stack_a, char flag)
{
	int				i;
	t_stack		*temp;

	printf("\nstack %c: \n", flag);
	i = 0;
	temp = stack_a->prev;
	while (stack_a != temp)
	{
		printf("val == %d    ind == %d\n", stack_a->content, ++i);
		stack_a = stack_a->next;
	}
	printf("val == %d    ind == %d\n", stack_a->content, ++i);
	printf("len de la stack == %d\n\n", ft_stacklen(stack_a));
}


int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	//t_arbre	*arb;

	stack_a = ft_init_stack(ac, av);
	stack_b = NULL;
	//arb = NULL;
	ft_print_stack(stack_a, 'a');
	ft_pres_sort(&stack_a, &stack_b);
	printf("majoran == %d", ft_get_majoran(12, ft_stacklen(stack_b), stack_b));
	//ft_init_arbre(stack_a, stack_a, arb, 0);
	//ft_val_to_top(stack_a, ft_stacklen(stack_a), 1);
	ft_print_stack(stack_a, 'a');
	ft_print_stack(stack_b, 'b');
	ft_delstack(stack_b, stack_b->prev);
	ft_delstack(stack_a, stack_a->prev);
	return (0);
}
