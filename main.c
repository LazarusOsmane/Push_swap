/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:40:33 by engooh            #+#    #+#             */
/*   Updated: 2022/02/16 14:35:09 by lazarus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_print_stack(t_stack *stack_a, char flag)
{
	int				i;
	t_stack		*temp;

	if (!stack_a)
		  return ;
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

	stack_a = ft_init_stack(ac, av);
	stack_b = NULL;
	ft_print_stack(stack_a, 'a');
	ft_big_sort(&stack_a, &stack_b);
	ft_print_stack(stack_a, 'a');
	ft_print_stack(stack_b, 'b');
	if (stack_b)
		  ft_delstack(stack_b, stack_b->prev);
	ft_delstack(stack_a, stack_a->prev);
	return (0);
}
