/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:40:33 by engooh            #+#    #+#             */
/*   Updated: 2022/01/17 18:21:07 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int ac, char **av)
{
	  t_stack	*stack_a;
	  t_stack	*stack_b;
	  t_stack	*p;

	 (void)stack_b;
	  stack_a = ft_init_stack(ac, av);
	  if (!stack_a)
		    return (0);
	  p = stack_a;
	  while (stack_a)
	  {
		    printf("%d\n", stack_a->content);
		    stack_a = stack_a->next;
	  }
	  printf("\n\n\n");
		p = ft_reverse(&p, "ra");
		/*printf("\n\n\n");
		while (stack_b)
	  {
		    printf("%d\n", stack_b->content);
		    stack_b = stack_b->next;
	  }*/
		printf("\n\n\n");
	  while (p)
	  {
		    printf("%d\n", p->content);
		    p = p->next;
	  }
	  return (0);
}
